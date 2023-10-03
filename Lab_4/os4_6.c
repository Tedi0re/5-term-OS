#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
 for(int i = 0; i < 100; i++)
 {
  printf("%d-%d\n", getpid(), i);
  sleep(1);
 }
 return 0;
}
