#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "employee.h"



void printEmployee(Employee *emp)
{
	printf("%-16s %-16s %8d  %8.2f \n",
		emp->name.firstName, emp->name.familyName,
		emp->id, emp->salary);

}

void initEmployee(Employee *emp, char *firstName, char *familyName, 
	unsigned int id, float salary)
{
	strncpy(emp->name.firstName, firstName, NAME_LENGTH - 1);
	strncpy(emp->name.familyName, familyName, NAME_LENGTH - 1);
	emp->id = id;
	emp->salary = salary;

}

