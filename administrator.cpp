#include <iostream>
#include "administrator.h"

using std::cin;
using std::cout;

namespace SavitchEmployees {
    Administrator::Administrator() {
        setAdminData();
    }

    Administrator::Administrator(const string &name, const string &ssn, string title,
                                 string responsibility,
                                 string supervisor, double annualSalary) :
                                 SalariedEmployee(name, ssn, 0),
                                 title(std::move(title)), responsibility(std::move(responsibility)), supervisor(std::move(supervisor)), annualSalary(annualSalary){}

    void Administrator::setSupervisor(string newSupervisor) {
        supervisor = std::move(newSupervisor);
    }

    void Administrator::setAdminData() {
        //name, ssn, title, responsibility, supervisor, annualSalary
        cout << "name: ";
        cin >> name;
        cout << "ssn: ";
        cin >> ssn;
        cout << "title: ";
        cin >> title;
        cout << "responsibility: ";
        cin >> responsibility;
        cout << "supervisor: ";
        cin >> supervisor;
        cout << "annualSalary: ";
        cin >> annualSalary;
    }

    void Administrator::print() const {
        // name, annualSalary, ssn, title, responsibility, supervisor
        cout << "name: " << name << '\n';
        cout << "annualSalary: " << annualSalary << '\n';
        cout << "ssn: " << ssn << '\n';
        cout << "title: " << title << '\n';
        cout << "responsibility: " << responsibility << '\n';
        cout << "supervisor: " << supervisor << '\n';
    }

    void Administrator::printCheck() {
        double monthly_salary = annualSalary / 12;
        setSalary(monthly_salary);
        cout << "monthly salary: " << monthly_salary << '\n';
    }
}