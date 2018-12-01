#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

int fexists(char *fileName);

int main(int argc, char *argv[]) {

  struct personalInfo person;
  
  if (argc < 2) {
      printf("usage %s filename \n",argv[0]);
      return(1);
  }

  // check if file exists
  if(fexists(argv[1]))
  {
      printf("File %s exists \n", argv[1]);
      FILE* file = fopen(argv[1], "rb+");
      
      int result = fread(&person, sizeof(struct personalInfo), 1, file);
      if (result)
      {
          printf("Original person\n");
          printPerson(&person); 
          person.age = 36;
          person.salary[0] = 47500;
          person.salary[1] = 40000;
          person.salary[2] = 23000;
          person.salary[3] = 51000;
          person.salary[4] = 37000;
          fseek(file, 3* sizeof(struct personalInfo), SEEK_CUR);
          fwrite(&person, sizeof(struct personalInfo), 1, file);
  
          int currentPosition = ftell(file);
          int recordNumber = currentPosition / sizeof(struct personalInfo);
          printf("Record number is %d, should be 5\n\n", recordNumber);
          
          fseek(file, -sizeof(struct personalInfo), SEEK_CUR);
          fread(&person, sizeof(struct personalInfo), 1, file);
          printf("Modified person\n");
          printPerson(&person);
      }

      fclose(file);
      printf("\n");
  }


  return 0;
}

/************************************************************************/
// Return whether the given file exists in the current directory.
// TODO: Complete this function.
int fexists(char *fileName)
{
    FILE* file = fopen(fileName, "r");
    int result = file != NULL ? 1 : 0;
    fclose(file);
    return result;
}
