#ifndef LEC9_ADMINISTRATOR_H
#define LEC9_ADMINISTRATOR_H

#include "salariedemployee.h"
#include <string>

using std::string;

namespace SavitchEmployees {

    class Administrator : public SalariedEmployee {
    private:
        string title;
        string responsibility;
        string supervisor;
    protected:
        double annual_salary;
    public:
        Administrator();

        Administrator(string, string, string, string, string, double);

        void setSupervisor(string);

        void setAdminData();

        void print();

        void printCheck();
    };
}


#endif //LEC9_ADMINISTRATOR_H
