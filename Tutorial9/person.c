// FILE is person.c

/************************************************/
// INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "mystat.h"

/************************************************/
// DEFINE

#define BASE_SALARY 30000


/************************************************/

/* Print the information of a person.

   input
   p - a person record

*/

void print(PersonRec *p)
{
    float avg_best_five_years = 0;


    average(p->salary, NUM_YEARS, &avg_best_five_years);


    printf("Person Name: %-10s %-10s, Age: %hu, Best five years salary: %6.2f\n",
            p->first_name, p->last_name, p->age, avg_best_five_years);
}

/************************************************/

/* Populate the information of a person.

   input
   p - a person record

*/

void populate(PersonRec *p) {

    int i;
    static long long id = 0;
    char *first_name[5] = { "David", "John", "Diana", "Rob", "Sarah" };
    char *last_name[5] = { "Smith", "Bell", "West", "Johnson", "Ford" };

    strncpy(p->last_name, last_name[rand() % 5], NAME_LENGTH);
    strncpy(p->first_name, first_name[rand() % 5], NAME_LENGTH);

    p->id = id++;
    p->age = (rand() % 45) + 20;

    // Populate the salary information.
    for (i = 0; i < NUM_YEARS; i++) {
        p->salary[i] = BASE_SALARY + (rand() & 5000);
    }
}



void printHighSalary(PersonRec *p)
{
    float avg_best_five_years = 0;


    average(p->salary, NUM_YEARS, &avg_best_five_years);

    if (avg_best_five_years < 32000)
    {
        return;
    }

    printf("Person Name: %-10s %-10s, Age: %hu, Best five years salary: %6.2f\n",
            p->first_name, p->last_name, p->age, avg_best_five_years);
}

int processArray(PersonRec *arr, int size, void (*processFun)(PersonRec *rec))
{
    for (int i = 0; i < size; i++)
    {
        processFun(&arr[i]);
    }
    return 0;
}
