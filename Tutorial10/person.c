#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystat.h"
#include "person.h"


void printPerson(struct personalInfo *p)
{
  float averageBestFiveYears = 0;
  int i;

  average(p->salary, NUM_YEARS, &averageBestFiveYears);
  printf("Person Name =%s   %s  age = %hu \n Salaray:", p->firstName, p->familyName, p->age);
  for (i = 0; i < NUM_YEARS; i++) {
      printf(" y[%d]= %f ", i, p->salary[i]);
  }
  printf("\n");
}

void populatePerson(struct personalInfo *p)
{
  int i;
  static int id = 0;
  char *firstName[5] = { "David", "John", "Diana", "Tal", "Shir" };
  char *familyName[5] = { "Smith", "kirsh", "Worker", "Light", "North" };

  strncpy(p->familyName, familyName[rand() % 5], NAME_LENGTH);
  strncpy(p->firstName, firstName[rand() % 5], NAME_LENGTH);

  p->id = id++;
  p->age = (rand() % 45) + 20;

  for (i = 0; i < NUM_YEARS; i++) {
    p->salary[i] = BASE_SALARY + (rand() & 5000);
  }
}
