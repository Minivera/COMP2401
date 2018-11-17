#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"


/***********************************************************/
/*
Purpose:  adds a record as the first node of the linked list 
input:
head - head of the list
data - a pointer to an Employee record

Output
head - the updated head of the list 

Return
0 - if data was successfully added to the list
1 - if node was not added to the list
*/


int addNode(ListNode **head, Employee *data)
{
	ListNode *p = NULL;
	
    p = malloc(sizeof(ListNode));

    p->data = data;
    p->next = *head;
    *head = p;
    return(0);

}
/***********************************************************/
/*
Purpose:  prints the list from the first node to the last node
input:
head - head of the list

Output
None

Return
None
*/


void printList(ListNode *head) 
{
	ListNode *p = head;
	while(p != NULL)
	{
		printEmployee(p->data);
		p = p->next;
	}

}

/***********************************************************/
/*
Purpose:  prints the list from the first node to the last node using recursiion
input:
head - head of the list

Output
None

Return
None
*/


void printListRecursive(ListNode *head) 
{
	if (head == NULL)
	{
		return;
	}
	printEmployee(head->data);
	printListRecursive(head->next);
}




/***********************************************************/
/*
Purpose:  prints the third last record in the list
input:
head - head of the list

Output
None

Return
0 if successful
1 if an error occur (e.g., list does not have three nodes)
*/


int printThirdLast(ListNode *head) 

{
	if (head == NULL)
	{
		return 0;
	}
	int count = 1 + printThirdLast(head->next);
	if (count == 3)
	{
		printEmployee(head->data);
	}
    return count;

}

/***********************************************************/
/*
Purpose:  prints the list in reverse from the last node to the first node using recursiion
input:
head - head of the list

Output
None

Return
None
*/


void printListInReverse(ListNode *head) 
{

	// check bounary conditions

	// make recursive call

	// do work 

}




/***********************************************************/
/*
Purpose:  delete the first node from the linked list 
input:
head - head of the list

Output
head - the updated head of the list 
data - the data that was stroed in the record 

Return
none 
*/


void deleteNode(ListNode **head, Employee **data)
{
	ListNode *p = NULL;

    if (*head == NULL) {
        return;
    }

    p = (*head)->next;
    *data = (*head)->data;
    free(*head);
    *head = p;

    return;
}
/***********************************************************/

