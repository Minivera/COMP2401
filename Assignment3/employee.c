// file is person.c

/*
Purpose: contains the functions for processing employree records



Revisions:
11/2018 - Doron Nussbaum 	Created




Copyright 2018 Doron Nussbaum


*/



/******************************************************/
// include files 


#include "stdio.h"
#include "employee.h"



/******************************************************/

void printEmployee(PersonRec *person)
{
	char employeeString[256];
	sprintf(employeeString, "%s %s", person->firstName, person->familyName);
	printf(
	   "%-33s dept:%2d salary:%6.2f position:%2d years of service:%4d salary to-date:%8.2f\n",
	   employeeString,
	   person->emp.department,
	   person->emp.salary,
	   person->emp.position,
	   person->emp.yearsOfService,
	   person->emp.yearsOfService * person->emp.salary
   );

	return;
}
