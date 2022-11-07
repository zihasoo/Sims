
#ifndef SIMS_ADMINISTRATOR_H
#define SIMS_ADMINISTRATOR_H

#include "salariedemployee.h"

namespace SavitchEmployees {
    class Administrator : public SalariedEmployee {
        string title;
        string responsibility;
        string supervisor;
    protected:
        double annualSalary{};
    public:
        Administrator();

        Administrator(const string &, const string &, string , string , string , double);

        void setSupervisor(string newSupervisor);

        void setAdminData();

        void print() const;

        void printCheck();
    };
}


#endif //SIMS_ADMINISTRATOR_H
