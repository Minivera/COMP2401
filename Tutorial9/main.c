// FILE main.c

/******************************************/

// INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

/********************************************/
// DEFINE
#define NUM_PEOPLE 7

/********************************************/

int main(int argc, char *argv[])
{
  struct person people[NUM_PEOPLE];
  int i;

  // populate the array
  for (i = 0; i < NUM_PEOPLE; i++) {
    populate(&people[i]);
  }

  // print the array
  for (i = 0; i < NUM_PEOPLE; i++) {
    print(&people[i]);
  }
  
  printf("\n\nHigh salary only\n\n");
  
  processArray(people, NUM_PEOPLE, printHighSalary);

  return 0;
}
