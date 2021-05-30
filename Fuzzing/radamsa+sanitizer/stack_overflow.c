// RUN: clang -O -g -fsanitize=address %t && ./a.out
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  if(argc != 3){
  	printf("You need just 2 inputs!\n");
  	return 0;
  }
  printf("%s,%s\n",argv[1],argv[2]);
  int size=strtol(argv[1], NULL, 10);
  int index=strtol(argv[2], NULL, 10);;
  int stack_array[size];
  stack_array[0] = 0;
  return stack_array[index];  // BOOM
}
