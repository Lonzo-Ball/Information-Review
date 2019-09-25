#include <iostream>
#include <mutex>
#include <pthread.h>

using namespace std;
//懒汉模式
class Singleton{
private:
	//构造函数私有
	Singleton(){
		pthread_mutex_init(&lock,NULL);
		cout << "Singleton()" << endl;
	}

	//C++11 delete
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton) = delete;

	static Singleton *m_pInstance;  //单例对象指针
	static pthread_mutex_t  lock;  //互斥锁
public:
	static Singleton* GetInstance(){
		if(NULL == m_pInstance){
			pthread_mutex_lock(&lock);
			if(NULL == m_pInstance){
				m_pInstance = new Singleton();
			}
			pthread_mutex_unlock(&lock);
		}

		return m_pInstance;
	}

	//实现一个内嵌垃圾回收类
	class CGarbo{
		private:
		public:
			~CGarbo(){
				pthread_mutex_destroy(&lock);
				if(NULL != m_pInstance){
					cout << "~CGarbo" << endl;
					delete Singleton::m_pInstance;
				}
			}
	};
	static CGarbo Garbo;  //定义一个静态成员变量，程序结束时，会自动调用它的析构函数从而释放单例对象
};
Singleton* Singleton::m_pInstance = NULL;
pthread_mutex_t Singleton::lock;
Singleton::CGarbo Garbo;

int main(){
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	return 0;
}

#if 0
//饿汉模式
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
};
Singleton Singleton::m_instance;  //在程序入口之前就完成单例对象的初始化
#endif
