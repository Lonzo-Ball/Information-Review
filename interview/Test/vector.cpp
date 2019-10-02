#include <iostream>
#include <vector>

using namespace std;
class Test{
public:
	Test(){
		cout << "Test()" << endl;
	}
	Test(const Test& t){
		cout << "Test(const Test& t)" << endl;
	}
	~Test(){
		cout << "~Test()" << endl;
	}
};
int main(){
	Test t1;
	Test t2;
	Test t3;
	vector<class Test> v;

	v.push_back(t1);
	cout << "capacity = " << v.capacity() << endl;
	v.push_back(t2);	
	cout << "capacity = " << v.capacity() << endl;
	v.push_back(t3);
	cout << "capacity = " << v.capacity() << endl;

	return 0;
}
