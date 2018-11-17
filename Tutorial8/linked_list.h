#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER


#include "employee.h"
typedef struct listNodeStruct ListNode;

struct listNodeStruct {
	Employee *data;
	ListNode *next;	// next node in the linked list
};


int addNode(ListNode **head, Employee *emp);
void printList(ListNode *head);
void printListRecursive(ListNode *head);
int printThirdLast(ListNode *head);
void printListInReverse(ListNode *head);
void deleteNode(ListNode **head, Employee **data);

#endif
