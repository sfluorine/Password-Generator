#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char * genPass(size_t size)
{
  char * buffer = NULL;
  char input;

  if (size < 8)
  {
    printf("Your password length is less than 8 characters, continue? y / n: ");
    input = getc(stdin);
  
    if (input == 'y') 
    {
      srand(time(NULL));

      buffer = malloc(sizeof(char) * size);
      char * alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@!#$%^&*+-";
      int numArr[size];

      for (size_t i = 0; i < size; i++)
      {
        numArr[i] = rand() % strlen(alphabet + 1);
        buffer[i] = alphabet[numArr[i]];
      }
    } 
    else if (input == 'n') 
    {
      exit(EXIT_SUCCESS);
    }
  } 
  else 
  {
    srand(time(NULL));

    buffer = malloc(sizeof(char) * size);
    char * alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@!#$%^&*+-";
    int numArr[size];

    for (size_t i = 0; i < size; i++)
    {
      numArr[i] = rand() % strlen(alphabet + 1);
      buffer[i] = alphabet[numArr[i]];
    }
  }

  return buffer;
}

int main(int argc, char ** argv)
{
  if (argc < 2)
  {
    printf("Not enough argument \n");
    printf("ARGUMENT: length of password \n");

    exit(EXIT_FAILURE);
  }

  char * argument = argv[1];
  int length = atoi(argument);

  char * result = genPass((size_t)length);
  
  printf("result:  %s \n", result);

  free(result);
}
