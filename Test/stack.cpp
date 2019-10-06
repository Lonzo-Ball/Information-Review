#include <iostream>

using namespace std;
int i = 0;
void func(){
	int buffer[256];  //256 * 8 = 1 KB
	++i;
	cout << i << endl;
	
	func();
}
int main(){
	func();
	return 0;
}
