cmake_minimum_required(VERSION 3.16)
project(CPP_OOP CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Every <NNN-topic>/ExNNN directory is one standalone program, e.g. target 007_Ex003
file(GLOB exercise_dirs LIST_DIRECTORIES true ${CMAKE_SOURCE_DIR}/[0-9]*/Ex*)
foreach (dir ${exercise_dirs})
    file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${dir})
    string(REGEX REPLACE "^([0-9]+)-.*/(Ex[0-9]+)$" "\\1_\\2" target ${rel})
    file(GLOB sources ${dir}/*.cpp)
    add_executable(${target} ${sources})

    # tests/<case>.in is fed to stdin; stdout must equal tests/<case>.expected
    file(GLOB inputs ${dir}/tests/*.in)
    foreach (input ${inputs})
        get_filename_component(case ${input} NAME_WE)
        add_test(NAME ${target}_${case}
                COMMAND ${CMAKE_COMMAND} -DEXE=$<TARGET_FILE:${target}> -DINPUT=${input}
                -DEXPECTED=${dir}/tests/${case}.expected -P ${CMAKE_SOURCE_DIR}/cmake/RunTest.cmake)
    endforeach ()
endforeach ()

# Prints pointer values, which differ per run and per standard library, so match the shape: null casts print 0/0x0
add_test(NAME 012_Ex005_casts COMMAND 012_Ex005)
set_tests_properties(012_Ex005_casts PROPERTIES PASS_REGULAR_EXPRESSION
        "^0x[0-9a-f]+\n(0|0x0)\n0x[0-9a-f]+\n0x[0-9a-f]+\n(0|0x0)\n$")
