# Assignment 3

By Guillaume St-Pierre, 16/11/2018

## Hospital

### Description

Hospital - Program for manipulating records of employees and patients in a hospital. This program is meant as a fondation build on the design specifications. It is memory safe and makes sure to ootpimize memory as much as possible.

The program also implements two optional features that allows *copying a list of persons t another list in sorted order* and *reversing a list of persons*.

### Files

The program is divided into a few files
- *person.c* and *person.h* contains the code to handle and create the generic person structs. A person will have a field stating if it is an employee or a patient.
- *employee.c* and *employee.h* contains the code to handle employee structs.
- *patient.c* and *patient.h* contains the code to handle patient structs.
- *person_list.c* and *person_list.h* contains the code to handle a list of persons and run basic operations on that list.

Other files are files for testing and to fill lists with sample data.

### How to use

Clean any executable with `make clean`

Compile with `make build`

Execute with `./Assignment3.exe`.the program should print the structures size and then show the various functions working.

### Limitations

The code may have some memory leaks as the memory management is handled in an untouched file. Copying a list to sort it may result in some unfreed memeory.