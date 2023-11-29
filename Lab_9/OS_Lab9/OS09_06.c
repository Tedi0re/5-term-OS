#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#include <stdbool.h>



int main(int argc, char *argv[])
{
 char *locale = setlocale(LC_ALL, "");
 char c;
 int rowNumber = 0;
 int in = open("./OS09_05.txt", O_RDONLY);
 int out;
 int num;
 bool yaBool = 0;
 
 out = open("./OS09_06_1.txt", O_CREAT | O_WRONLY, 0777);
 
 while (read(in, &c, 1) == 1)
 {
 if (rowNumber % 5 == 0)
 {
 write(out, &c, 1);
 }
  
  if (c == '\n'){
   rowNumber++;
   }
   

  
 }
 close(out);
 close(in);
 return 0;
}