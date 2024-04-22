#include <string>
using namespace std;

#include "Employee.h"

class Manager : public Employee
{
    double _salary;

public:
    Manager(const string, const string, double);
    double get_income() const;
    void print() const;
};