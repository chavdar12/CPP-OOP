# Usage: cmake -DEXE=<program> -DINPUT=<file> -DEXPECTED=<file> -P RunTest.cmake
execute_process(COMMAND ${EXE} INPUT_FILE ${INPUT} OUTPUT_VARIABLE actual RESULT_VARIABLE code TIMEOUT 10)
file(READ ${EXPECTED} expected)

if (NOT code EQUAL 0)
    message(FATAL_ERROR "${EXE} exited with '${code}'")
endif ()
if (NOT actual STREQUAL expected)
    message(FATAL_ERROR "Output mismatch for ${INPUT}\n--- expected ---\n${expected}\n--- actual ---\n${actual}")
endif ()
