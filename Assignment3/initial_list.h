// File initial_list.h
/*
Purpose: populate the records of the patient and the employee

 


Revisions:
5/11/2018 - Doron Nussbaum file created




Copyright 2018 Doron Nussbaum


*/

#ifndef INITIAL_LIST_HEADER
#define INITIAL_LIST_HEADER


/*************************************************/
// Include 

#include "person.h"
#include "person_list.h"


/*************************************************/
// Function prototypes 


int createInitialList(PersonList **head, int numNodes, int sizeOfDataRec);
void releaseData();


#endif
