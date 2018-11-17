/*
File name is initial_list.c
Purpose: file contains a function to create an initial list

Revisions
created Doron Nussbaum 2018





Copyright 2018 Doron Nussbaum




Copyright 2018 Doron Nussbaum


*/

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "populateRecord.h"
#include "initial_list.h"


/************************************************************************/
// Define 


/************************************************************************/
// globals

static char *initialDataRecord = NULL;



/************************************************************************/

/*
Purpose: create an initrial liknked list of employees and patients
input
sizeOfDataRec - sizeof the the data record
numNodes - number of nodes to include in the linked list

input/output
head - head of linked list

return
A pointer to the node that was allocated.

NULL - if the operation was not successful

*/

int createInitialList(PersonList **head, int numNodes, int sizeOfDataRec)
{
	char *p = NULL;
	PersonList *q = NULL;

	int i;

	*head = NULL;

	p = (char *) malloc(numNodes * sizeOfDataRec);
	if (p == NULL) 	goto err;

	for (i = 0; i < numNodes; i++) {
		// allocate data  for node
		q = (PersonList *) malloc(sizeof(PersonList));
		if (q == NULL) goto err;

		// assign fields
		q->next = NULL;
		q->data = (PersonRec *) &p[i*sizeOfDataRec];
		// populate data record
		populateRecord(q->data);
		
		// add to list
		q->next = *head;
		*head = q;

	}

	// remember the allocated memory
	if (initialDataRecord != NULL) free(initialDataRecord);
	initialDataRecord = p;
	return(0);
	err:
	if (*head != NULL) {
		PersonList *q;
		while (*head != NULL) {
			q = *head;
			*head = (*head)->next;
			free(q);
		}
	}

	if (p != NULL) free(p);
	p = NULL;
	return(1);


}



void releaseData()
{
	free(initialDataRecord);
	initialDataRecord = NULL;
}

