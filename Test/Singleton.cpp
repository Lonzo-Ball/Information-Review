#include <iostream>

using namespace std;
class Singleton{
private:
	Singleton(){
		cout << "Singleton()" << endl;
	}

	//C++98 防拷贝
	//Singleton(const Singleton&);
	//Singleton& operator=(const Singleton);
	
	//C++11 delete
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton) = delete;

	static Singleton m_instance;
public:
	static Singleton* GetInstance(){
		return &m_instance;
	}
};Singleton Singleton::m_instance;  //在程序入口之前就完成单例对象的初始化

int main(){
	Singleton *p = Singleton::GetInstance();
	cout << p << endl;
	
	return 0;
}
