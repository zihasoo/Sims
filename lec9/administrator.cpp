#include <iostream>
#include "administrator.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

namespace SavitchEmployees {
    Administrator::Administrator() {
        setAdminData();
    }

    Administrator::Administrator(string name, string ssn, string title, string responsibility,
                                 string supervisor, double annual_salary) :
            SalariedEmployee(name, ssn, 0), title(title), responsibility(responsibility),
            supervisor(supervisor), annual_salary(annual_salary) {}

    void Administrator::setSupervisor(string newname) {
        name = newname;
    }

    void Administrator::setAdminData() {
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
        cout << "annual_salary: ";
        cin >> annual_salary;
    }

    void Administrator::print() {
        cout << "name: " << name << '\n'
             << "ssn: " << ssn << '\n'
             << "title: " << title << '\n'
             << "responsibility: " << responsibility << '\n'
             << "supervisor: " << supervisor << '\n';
    }

    void Administrator::printCheck() {
        cout << "montly salary: " << annual_salary / 12 << '\n';
    }
}
