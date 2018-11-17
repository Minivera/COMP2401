// file is struct.h
#ifndef STRUCT_HEADER
#define STRUCT_HEADER


/* The file contains the structure declarations required by the program 



Revisions:
February 10, 2018 Doron Nussbaum, initial version

*/

/***************************************************************/

//DEFINES

#define NAME_SIZE     15	// size of array for patient/employee name (maximum name length is NAME_SIZE - 1)

//Patient related defines		
#define PATIENT_TYPE 1
#define NUM_SEVERITIES 4
#define LIGHT 0
#define STABLE 1
#define ACCUTE 2
#define IMMEDIATE_SURGERY 3

//Employee related defines
#define EMPLOYEE_TYPE 0
#define MAX_POSITIONS 4
#define DOCTOR 0
#define NURSE 1
#define SURGEON  2
#define ADMIN 3

// Department defines
#define MAX_DEPARTMENTS 6

/***************************************************************/

//Structures

// structure contains patient information 
typedef struct patient {
	// cost of hospitalization per day - an integer number in the range of 1-50, size 6
	unsigned int dailyCost : 6;
	// severity of illness - an integer number in the range of 0-3, size 2
	unsigned severity : 2;
    // department in hospital - an integer in the range of 1-6, size 3
	unsigned int department : 3;
	// number of days in hospital - an integer number in the range of 0-30, size 5
	unsigned short numDaysInHospital : 5;
} PatientRec;


// structure contains employee information
typedef struct employee {
    // position of employee in hospital - an integer in the range of 0-3, size 2
	unsigned int position : 2;
 	// years of service - an integer in the range of 0-60, size 6
	unsigned int yearsOfService : 6;
	// department in hospital - range 1-6 (integer), size 3
	unsigned int department : 3;
	// annual salary - a real non negative number, size 4
	float salary;
} EmployeeRec;


// structure contains person information
typedef struct person {
	char firstName[NAME_SIZE];
	char familyName[NAME_SIZE];
	char employeeOrPatient;
	union {
		EmployeeRec emp;
		PatientRec patient;
	};
} PersonRec;

void printPerson(PersonRec *person);
void printOnlyPatientsFun(PersonRec *person);

#endif
