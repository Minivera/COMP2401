/*
File name is patient.c
Purpose: file contains a function for processing patient records

Revisions
11/2018 - Doron Nussbaum created 





Copyright 2018 Doron Nussbaum

*/

/******************************************************************/
// INCLUDE 



#include "string.h"
#include "stdio.h"
#include "patient.h"


/*****************************************************************/

void printPatient(PersonRec *person)

{
	char patientString[256];
	sprintf(patientString, "%s %s", person->firstName, person->familyName);
	printf(
	   "%-33s dept:%2d days in hospital:%3d severity:%2d daily cost:%3d total cost:%5d\n",
	   patientString,
	   person->patient.department,
	   person->patient.numDaysInHospital,
	   person->patient.severity,
	   person->patient.dailyCost,
	   person->patient.numDaysInHospital * person->patient.dailyCost
   );
}


