
/*************************************************************/

// INCLUDES 
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

/*************************************************************/

// prototypes 

int fexists(char *fileName);
void readFile(FILE *fid);

/*************************************************************/

 
int main(int argc, char *argv[]) {

  FILE *fid;
  int rc=0;

  if (argc < 2) {
      printf("usage %s filename \n",argv[0]);
      return(1);
  }

  // check if file exists
  if(fexists(argv[1]))
  {
      printf("File %s exists \n", argv[1]);
      FILE* file = fopen(argv[1], "r");
      readFile(file);
      fclose(file);
      printf("\n");
  }


  return 0;
}


/*********************************************************************/
// Return whether the given file exists in the current directory.
// 
// Input:
// fileName - name of fle
//
// Output:
// None
//
// Return:
// 0 if the file does not exist
// 1 if the file exists
//
int fexists(char *fileName)
{
    FILE* file = fopen(fileName, "r");
    int result = file != NULL ? 1 : 0;
    fclose(file);
    return result;
}




/*********************************************************************/
// Read the content of the file 
// 
// Input:
// fid - file handle 
//
// Output:
// None
//
// Return:
// 0 if the file does not exist
// 1 if the file exists
//
void readFile(FILE *file)
{
    char line[256];

    while (fgets(line, sizeof(line), file)) 
    {
        printf("%s", line); 
    }
}
