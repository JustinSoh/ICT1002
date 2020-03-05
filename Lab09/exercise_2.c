#include <stdio.h>
#include <string.h>
int main(void) {
  char *a = "abcdef";
  char b[7];  
  strcpy(b, a);
  printf("%c\n", a[0]); //a
  printf("%c\n", b[0]);//a
  printf("%c\n", b[4]); //e
  printf("%lu\n" , strlen(a)); //6.0
  printf("%lu\n" , strlen(b)); //6.0
  printf("%d\n" , strcmp(a,b)); //0
  


  return 0;
}