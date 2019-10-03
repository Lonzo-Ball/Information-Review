
#include <iostream>
//#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

using namespace std;
int main(){
 	cout << getpid() << endl;
	//cout << gettid() << endl;
	cout << syscall(SYS_gettid) << endl;
	return 0;
}
