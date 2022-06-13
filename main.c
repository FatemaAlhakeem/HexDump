/* This main.c file prompts the user to enter five sentences then uses hex_dump   
    and hex_dump_highlight to input the strings into a hex table. */

#include <stdio.h>
#include "hexdump.c"
#include <string.h>
#include <stdlib.h>

int main (int argc, char *atgv[])
{
  char string[250]; 
  char *ptr; 
  char *buffer[5]; 
  int length= 0; 
  for (int i= 0; i<5; i++)
  {
    printf("\nEnter sentence %d: ", (i+1)); 
    fgets(string, sizeof(string), stdin); 
    length= strlen(string)-1;  
    printf("\nThe length of the sentence is: %d", length); 
    ptr= (char *) malloc(sizeof(char)*(length)); 
    strcpy(ptr, string);
    //printf("\nstrlen of string is %d\r\n strlen of ptr is %d", strlen(string), strlen(ptr)); 
    hex_dump(ptr, length);  
    hex_dump_highlight(ptr, length, 0, length);
    printf("\n%p", ptr);
    buffer[i]= ptr; 
  }

  for (int i=1; i<5; i++)
  {
    printf("\n%s", buffer[i]); 
    strcat(buffer[0], buffer[i]); 
  }

  hex_dump_highlight(buffer[0], strlen(buffer[0]), 0, strlen(buffer[0]));
  
  return 0; 
}

//Another similar method.........

/*int main(int argc, char *argv[])
{
   char strings[5][256];

   for (int i=0; i<5; i++)
   {
     printf("Enter sentence %d: ", i+1); 
     fgets(strings, sizeof(strings), stdin);
     char *mem= (char* ) malloc(sizeof(char)*strlen(strings));
     strcpy(mem, strings); 
     hex_dump(mem, strlen(strings)-1); 
     hex_dump_highlight(mem, 512, 0, (strlen(strings))-2); 
   }

   for (int i=0; i<5; i++)
   {
   printf("%s", &strings[i]); 
   }

  return 0; 
}
*/


