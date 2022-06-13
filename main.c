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
    //printf("\n%p", ptr);
    buffer[i]= ptr; 
  }
  
  printf("\nSentences enetered are as below: "); 
  printf("\n%s", buffer[0]); 
  for (int i=1; i<5; i++)
  {
    printf("\n%s", buffer[i]); 
    strcat(buffer[0], buffer[i]); 
  }
  int bufferLength= strlen(buffer[0]);

  hex_dump_highlight(buffer[0], bufferLength, 0, bufferLength);
  
  return 0; 
}
