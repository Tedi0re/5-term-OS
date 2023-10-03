#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
 
int main()
{
for(int i = 1; i <= 1000; i++) {
	cout << getpid()  << "U.N.I" << i << endl;
sleep(1);
}
return 0;
}
