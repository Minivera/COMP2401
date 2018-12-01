#ifndef PERSON_HEADER
#define PERSON_HEADER

#define NAME_LENGTH 32
#define NUM_YEARS 5
#define BASE_SALARY 30000

struct personalInfo {
  unsigned int id;
  unsigned short age;
  float salary[NUM_YEARS];
  char firstName[NAME_LENGTH];
  char familyName[NAME_LENGTH];
};

typedef struct personalInfo personalInfo; 
void populatePerson(struct personalInfo *p);
void printPerson(struct personalInfo *p);

#endif
