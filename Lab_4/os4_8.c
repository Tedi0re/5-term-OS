#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void* os04_08_T1(void* arg)
{
 for(int i = 0; i < 75; i++)
 {
  if(i == 50) sleep(10);
  printf("T1: %d-%d\n", getpid(), i);
  sleep(1);
 }
 pthread_exit("T1 thread");
}

int main(int argc, char **argv) 
{
 pthread_t a_thread;
 void* thread_result;
 pthread_create(&a_thread, NULL, os04_08_T1, NULL);
 
 for(int i = 0; i < 100; i++)
 {
  if(i == 30) sleep(15);
  printf("%d-%d\n", getpid(), i);
  sleep(1);
 }
 
 pthread_join(a_thread, (void**)&thread_result);
 exit(0);
}
