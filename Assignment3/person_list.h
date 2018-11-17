
/* 
File name is linked_list.h
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2018

  Copyright 2018 Doron Nussbaum

 
 */


#ifndef LINKED_LIST_2401_HEADER
#define LINKED_LIST_2401_HEADER 1


 /************************************************************************/
 // Include

#include "person.h"


 /************************************************************************/
 // DEFINE


#define NAME_LENGTH 16


/************************************************************************/

// STRUCTURES


typedef struct PersonList {
	struct PersonList *next;
	PersonRec *data;
} PersonList;

/************************************************************************/
// FUNCTION PROTOTYPES


// Print Functions
void printAllByName(PersonList *head, char *FamilyName);
void printListFun(PersonList *head, void(*printFun)(PersonRec *));


// Delete Functions
int deleteNodeByFamilyName(PersonList **head, char *FamilyName,  PersonRec **data);
void deleteList(PersonList **head);


//insert functions
PersonList *insertByName(PersonList **head, PersonRec *data);


// Copy constructors
void copySorted(PersonList *inHead, PersonList **outHead);

// Utility functions
void reverseList(PersonList **head);


/***************************************************/
/*
  You do not need to code these functions as part of the assignments.  However,
  you may find it simipler to code these functions and use them as needed
  to implement the required functions.
  
  These are helper functions (code as needed)

*/

 
// Insert Functions 
PersonList *insertFirst(PersonList **head, PersonRec *data);
PersonList *insertAfter(PersonList *node, PersonRec *data);
PersonList *insertLast(PersonList **head, PersonRec *data);

// Delete Functions
int deleteFirst(PersonList **head, PersonRec **data);
int deleteAfter(PersonList *node, PersonRec **data);


#endif
