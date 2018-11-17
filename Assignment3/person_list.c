
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2018

 
 
 
 
 Copyright 2018 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "person.h"
#include "employee.h"
#include "patient.h"
#include "person_list.h"

/************************************************************************/
// Define 


/************************************************************************/
/*
Purpose: prints all the person in the list that their family name matches the input familyName

input
head - the head of the list
familyName - familyName to be matched

output 
None

Return
None
*/


void printAllByName(PersonList *head, char *FamilyName)
{
    PersonList *element = head;
	while (element != NULL)
	{
        if (strcmp(element->data->familyName, FamilyName) == 0)
        {
            printPerson(element->data);
        }
	    element = element->next;
	}
}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printListFun(PersonList *head, void(*printFun)(PersonRec *data))
{
    PersonList *element = head;
	while (element != NULL)
	{
	    printFun(element->data);
	    element = element->next;
	}
}

/************************************************************************/

/*
Purpose: insert a new node into the list in a lexcicographic order

input
data - a person record

input/output
head - head of linked list

return
A pointer to the node that was allocated.
NULL - if the operation was not successful

NULL - if the operation was not successful

*/


PersonList *insertByName(PersonList **head, PersonRec *data)
{
    //If the head is null, insert at the start
    if (*head == NULL)
    {
        return insertFirst(head, data);
    }
	PersonList *element = *head;
	PersonList *previous = NULL;
	while (element != NULL)
	{
	    // Loop in all the element and check if the name is smaller than the current element
	    if (strcmp(element->data->familyName, data->familyName) > 0)
	    {
	        if (previous == NULL)
	        {
	            //If previous is null, then we should insert first
	            return insertFirst(head, data);
	        }
	        return insertAfter(previous, data);
	    }
        previous = element;
        element = element->next;
	}
	return insertLast(head, data);
}

/************************************************************************/

/*
Purpose: deletes the first node that matches the family namne
input
head - the head of the linked list
familyName - family name of person

inputoutput
head - modified head in case the first record was deleted
data - the data of the deleted node.  Return NULL if node was not deleted

return
0 - if a node was deleted
1 - if a node was not deleted


*/
int deleteNodeByFamilyName(PersonList **head, char *familyName, PersonRec **data)
{
	PersonList *element = *head;
	PersonList *previous = NULL;
	while (element != NULL)
	{
	    // Loop in all the element and check if the name match
	    if (strcmp(element->data->familyName, familyName) == 0)
	    {
	        // If yes, either delete the head
	        if (previous == NULL)
	        {
	            return deleteFirst(head, data);
	        }
	        // Or delete the element
            return deleteAfter(previous, data);
	    }
        previous = element;
        element = element->next;
	}
	return 1;
}

/***********************************************************************/
/*
Purpose: deletes all nodes from the list.  Note that the function should not need to release
the data field (it is up to the calling program)
input/output
head - the head of the list (set to NULL)


*/


void deleteList(PersonList **head)
{
	*head = NULL;
}

/************************************************************************/

/*
Purpose: Copies the given list into a new list sorted by name
input
inHead - the head of the linked list to copy
outHead - A reference to the head of the copied list

inputoutput
outHead - Modified list with the copied data sorted by name
*/
void copySorted(PersonList *inHead, PersonList **outHead)
{
    PersonList *element = inHead;
    //Copying the lsit sorted essentially means inserting using our sorting insert
    while(element != NULL)
    {
        // This will allocated some new memory for the node
        insertByName(outHead, element->data);
        element = element->next;
	   printListFun(*outHead, printPerson);
    }
}

void reverseList(PersonList **head)
{
    // It's easier to think of reversing as simply "changing the pointing direction of the nodes"
    // So this A->B becomes this A<-B
    PersonList *previous = NULL;
    PersonList *element = *head;
    PersonList *next = NULL;
    while (element != NULL) 
    { 
        // Store next 
        next = element->next;   
        // Reverse current node's pointer 
        element->next = previous;    
        // Move pointers one position ahead. 
        previous = element; 
        element = next; 
    } 
    *head = previous; 
}


/************************************************************************/

/************************************************************************/
/************************************************************************/
/************************************************************************/
/************************************************************************/
/************************************************************************/

// CODE THESE FUNCTIONS IF  NEEDED
/*
Purpose: insert a new node into the list as the first element
input
data - a person record

input/output
head - head of linked list

return
A pointer to the node that was allocated.
NULL - if the operation was not successful

*/


PersonList *insertFirst(PersonList **head, PersonRec *data)
{
	PersonList *newNode = malloc(sizeof(PersonList));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
	return newNode;
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
data - a person record


return
A pointer to the node that was allocated.  
NULL - if the operation was not successful

*/


PersonList *insertAfter(PersonList *node, PersonRec *data)
{
    if (node == NULL)
    {
        return NULL;
    }
	PersonList *newNode = malloc(sizeof(PersonList));
	newNode->data = data;
	newNode->next = node->next;
	node->next = newNode;
	return newNode;
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
data - a person record


return
A pointer to the node that was allocated.  
NULL - if the operation was not successful

*/


PersonList *insertLast(PersonList **head, PersonRec *data)
{
	if (*head == NULL)
    {
        return insertFirst(head, data);
    }
    PersonList *element = *head;
    while(element->next != NULL)
    {
        element = element->next;
    }
	PersonList *newNode = malloc(sizeof(PersonList));
	newNode->data = data;
	newNode->next = NULL;
	element->next = newNode;
	return newNode;
}


/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/

int deleteAfter(PersonList *node, PersonRec **data)

{
    if (node == NULL || node->next == NULL)
    {
        return 0;
    }
    PersonList *temp = node->next;
    node->next = node->next->next;
    *data = temp->data;
    return 1;
}

/************************************************************************/

/*
Purpose: delete the first node in the linked list
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
data - a person record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteFirst(PersonList **head, PersonRec **data)
{
    PersonList *temp = *head;
	if (temp == NULL)
	{
	    return 1;
	}
    *data = temp->data;
    temp = temp->next;
    *head = temp;
    return 0;
}







