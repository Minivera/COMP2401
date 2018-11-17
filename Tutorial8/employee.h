
#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#define NAME_LENGTH  16

typedef struct name {
  char firstName[NAME_LENGTH];
  char familyName[NAME_LENGTH];
} Name;

typedef struct emp{
  unsigned int	id;
  float salary;
  Name	name;
} Employee;

void printEmployee(Employee *emp);
void initEmployee(Employee *emp, char *firstName, char *familyName,
	unsigned int id, float salary);


#endif
