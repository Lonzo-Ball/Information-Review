#include <iostream>

using namespace std;
void fun(int n){
	cout << "第 " << n << " 次调用fun函数！" << endl;
}
int main(){
	for(int i = 0;i < 100;++i){
		fun(i);
	}
	return 0;
}
