//*********************************************
//This is the HEADER FILE salariedemployee.h. 
//This is the INTERFACE for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h"

namespace SavitchEmployees
{

  class SalariedEmployee : public Employee
  {
  public:
    SalariedEmployee( );
    SalariedEmployee (string theName, string theSsn,
                  double theWeeklySalary);
    double getSalary();
    void setSalary(double newSalary); 
    void printCheck( );

  protected:
    double salary; //weekly
  };

}//SavitchEmployees

#endif //SALARIEDEMPLOYEE_H
