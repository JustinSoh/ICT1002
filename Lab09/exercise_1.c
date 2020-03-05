#include <stdio.h>

int main(void) {
  int a[4] = { -1, 2, 10 , 7};
  int b[4];
  for(int i = 0; i < 4; i++){
    b[i] = a[3-1];
  }
  printf("%d\n", a[3]); //7
  printf("%d\n", b[3]); //10 
  printf("%d\n", b[a[1]]); //10 

  return 0;
}