#ifndef COMPANY_H
#define COMPANY_H

#include <sstream>
#include <vector>

class HasId
{
public:
    virtual int getId() const = 0;

    virtual ~HasId()
    {
    };
};

class HasInfo
{
public:
    virtual std::string getInfo() const = 0;

    virtual ~HasInfo()
    {
    };
};

class Company : public HasId, public HasInfo
{
protected:
    int id;
    std::string name;
    std::vector<std::pair<char, char>> employees;

public:
    Company();
    Company(int id, std::string name, std::vector<std::pair<char, char>> employees);

    int getId() const override;
    std::string getName() const;
    std::vector<std::pair<char, char>> getEmployees() const;
    std::string getInfo() const override;

    friend std::ostream& operator<<(std::ostream& stream, const Company& c);
    friend std::istream& operator>>(std::istream& stream, Company& c);
};

#endif
