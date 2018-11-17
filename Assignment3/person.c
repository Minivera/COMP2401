// file is person.c

/*
Purpose: contains the functions for processing person records



Revisions:
11/2018 - Doron Nussbaum 	Created




Copyright 2018 Doron Nussbaum


*/



/******************************************************/
// include files 

#include "employee.h"
#include "patient.h"
#include <string.h>


/******************************************************/
// function prototypes
void printPerson(PersonRec *person)
{
    // Even numbers (2) are patiens
    if (person->employeeOrPatient % 2)
    {
        printPatient(person);
    }
    // Odd numbers (1) are employees
    else
    {
        printEmployee(person);
    }
}

void printOnlyPatientsFun(PersonRec *person)
{
    // Even numbers (2) are patiens
    if (person->employeeOrPatient % 2)
    {
        printPatient(person);
    }
}
