// file is hospital.c

/*
Purpose: contains the main function of the hospital 



Revisions:
11/2018 - Doron Nussbaum 	Created


Copyright 2018 Doron Nussbaum


*/
/******************************************************/
// include files 


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "person.h"
#include "patient.h"
#include "employee.h"
#include "initial_list.h"
#include "person_list.h"

/******************************************************/
// DEFINE


#define NUM_RECORDS 20
#define CONTINUE {printf("hit <cr> to continue \n");getchar();}


/******************************************************/
// function prototypes



/******************************************************/

int main()
{
    PersonList *personHead = NULL;
	PersonList *secondHead = NULL;
	PersonRec *data = NULL;
	char name[16] = "Johnson";

	// initialize the first list
	createInitialList(&personHead, NUM_RECORDS, sizeof(PersonRec));
    // print the structure sizes
    printf("\nSize of structures\n");
    printf("sizeof(PersonRec) = %ld \n",sizeof(PersonRec));
    printf("sizeof(PatientRec) = %ld \n",sizeof(PatientRec));
    printf("sizeof(EmployeeRec) = %ld \n",sizeof(EmployeeRec));
    CONTINUE;

	// print all the people in the list
	printf("\n\n print all nodes in the list \n");
	printListFun(personHead, printPerson);

	// print only the patients in the list
	printf("\n\n print only the paients in the list \n");
	printListFun(personHead, printOnlyPatientsFun);

	// print all the people that match the name Johnson
	printf("\n\n print all nodes that match the name %s \n", name);
	printAllByName(personHead, name);


	// delete first node with name Johnson
	deleteNodeByFamilyName(&personHead, "Johnson", &data);
	// print all the people in the list
	printf("\n\n print all nodes in the list without with first %s \n", name);
	printListFun(personHead, printPerson);

    // insert into the end of the list
	printf("\n\n inserting a person by name \n");
	if (data != NULL)
	{
	    strncpy(data->familyName, "zJohnson", NAME_LENGTH);
    }
    insertByName(&personHead, data);
	printListFun(personHead, printPerson);


	//Bonus questions
	//copy the sorted list 
	copySorted(personHead, &secondHead);

	// print all the people in the list
	printf("\n\n print the dupliated sorted list\n");
	printListFun(secondHead, printPerson);

	//Reverse list  
	// print list before reversing 
	printf("\n\n print the  list before reversing\n");
	printListFun(secondHead, printPerson);
	reverseList(&secondHead);
	printf("\n\n print the  list after reversing\n");
	printListFun(secondHead, printPerson);
	// delete the second list
	deleteList(&secondHead);


	// delete the lists
	deleteList(&personHead);

	

    // leave this function it is part of the test functions
	releaseData();
    return 0;
}


