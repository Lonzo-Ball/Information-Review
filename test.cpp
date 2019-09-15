#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	std::cout << sizeof(fd_set) << std::endl;
	return 0;
}
