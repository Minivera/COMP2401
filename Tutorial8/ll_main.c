#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"
#include "employee.h"


int main(void) {
  int i;
  
  Employee employee[5];
  Employee *data = NULL;

  initEmployee(&employee[0], "Joe", "Clark", 567890345,100345);
  initEmployee(&employee[1],"Brian", "Mulroney", 567890767, 178983);
  initEmployee(&employee[2],"Jean", "Chretien", 567345890, 190329);
  initEmployee(&employee[3],"Paul", "Martin", 567899528, 192456);
  initEmployee(&employee[4],"Kim", "Campbell", 567436582, 192234);


  printf("array of employees \n");
  for (i = 0; i < 5; i++) {
	  printEmployee(&employee[i]);
  }

  ListNode *empHead = NULL;

    // add five nodes  
  for (i = 0; i < 5; i++) {
	  addNode(&empHead, &employee[i]);
  }

  printf("\n Printing the list from the first node to the last node \n");
  printList(empHead);


  printf("\n Recursive printing of list  \n");
  printListRecursive(empHead);
  
  printf("\n Reverse printing of list  \n");
  printListInReverse(empHead);

  printf("\n Printing the third last node in the list \n");
  printThirdLast(empHead);
  
  // delete five nodes  
  for (i = 0; i < 5; i++) {
	  deleteNode(&empHead, &data);
      printf("deleted node [%d] \n",i);
	  printEmployee(data);
  }
  printf("\n");
  return 0;
}


