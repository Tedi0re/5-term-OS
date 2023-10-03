#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void* os04_07_T1(void* arg)
{
 for(int i = 0; i < 75; i++)
 {
  printf("T1: %d-%d\n", getpid(), i);
  sleep(1);
 }
 pthread_exit("T1 thread");
}

int main() 
{
 pthread_t a_thread;
 void* thread_result;
 pthread_create(&a_thread, NULL, os04_07_T1, NULL);
 
 for(int i = 0; i < 100; i++)
 {
  printf("%d-%d\n", getpid(), i);
  sleep(1);
 }
 
 pthread_join(a_thread, (void**)&thread_result);
 exit(0);
}
