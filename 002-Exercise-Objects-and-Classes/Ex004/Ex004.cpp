#include <iostream>
#include <vector>
#include <string>

struct student
{
    std::string name;
    std::string surname;
    double average;

    void print() const
    {
        std::cout << name << " " << surname << " " << average << '\n';
    }
};

int main()
{
    int num_students;
    std::cin >> num_students;

    if (num_students <= 0)
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    std::vector<student> students(num_students);

    double sum_average = 0;

    for (auto& stud : students)
    {
        std::cin >> stud.name >> stud.surname >> stud.average;
        stud.print();
        sum_average += stud.average;
    }

    std::cout << sum_average / students.size() << '\n';
}
