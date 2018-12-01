# Assignment 4

By Guillaume St-Pierre, 16/11/2018

This assignment is feature complete and also implements the two bonus tasks of making multiSpawn use the number of numbers inthe binary file rather than a hardcoded number as well as the multSpawnSignal program thatimpleents a signal into multiSpawn.

## SinglePrime

### Description

This program morphs itself into the `isPrime` program to check if the first number of the given binary file is a prime number.

### Files

The program is made up of a main file plus some utility files described bellow.
- *singlePrime.c* The main program.

### How to use

Clean any executable with `make -f Makefile1 clean`

Compile with `make -f Makefile1`

Execute with `./singlePrime prime.bin; echo $?`. The program will tell you if some parameters are missing and will print it's return value using `echo`.

## SingleSpawn

### Description

This program spawn a new process that will morphs itself into the `isPrime` program to check if the first number of the given binary file is a prime number.

### Files

The program is made up of a main file plus some utility files described bellow.
- *singleSpawn.c* The main program.

### How to use

Clean any executable with `make -f Makefile2 clean`

Compile with `make -f Makefile2`

Execute with `./singleSpawn prime.bin; echo $?`. The program will tell you if some parameters are missing, if the number is a prime number and will print it's return value using `echo`.

## MultiSpawn

### Description

This program spawn as many process as there are numbers in the given file and each process will morph itself into the `isPrime` program to check if the number they are assigned is a prime number.

### Files

The program is made up of a main file plus some utility files described bellow.
- *multiSpawn.c* The main program.

### How to use

Clean any executable with `make -f Makefile3 clean`

Compile with `make -f Makefile3`

Execute with `./multiSpawn prime.bin`. The program will tell you if some parameters are missing and each number will be printed with whether or not they are a prime number.

## MultiSpawnSignal

### Description

This program spawn as many process as there are numbers in the given file and each process will morph itself into the `isPrime` program to check if the number they are assigned is a prime number.

This program also implements a handler for the special signal SIGUSR1 to show the number of process still running when received.

### Files

The program is made up of a main file plus some utility files described bellow.
- *multiSpawnSignal.c* The main program.

### How to use

Clean any executable with `make -f Makefile4 clean`

Compile with `make -f Makefile4`

Execute with `./multiSpawnSignal prime.bin`. The program will tell you if some parameters are missing and each number will be printed with whether or not they are a prime number.

To test the signal, find the process id with `ps` and send the signal to the program using `kill -10 <process>`. Changing the sleep time of the isPrime program can help test.

## Utility files
These files are shared between all programs.

- *isPrime.c* The special program that checks if it's first parameter is a prime number.
- *createBinary.c* Special program that will regenerate the `prime.bin` file with new numbers.
- *helpers.c* and *helpers.h* A file with functions that help with file handling.
- *morph.c* and *morph.h* A file with function that can help with managing process and morph programs.

## Data files
- *prime.bin* A binary file coaining up to 12 prime numbers represented as a unsigned integer.
- *prime.txt* A textual representation of *prime.bin*.

## Known limitations
No limitations are known.