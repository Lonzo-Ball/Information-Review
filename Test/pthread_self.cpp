#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;
void * thread_work(void* param){
	int TID = syscall(SYS_gettid);
	
	cout << "thread: " << TID << endl;
	cout << "pthread_self: " << pthread_self() << endl;
	cout << "I will exit!" << endl;
	 
	pthread_exit(NULL);
	return NULL;
}
int main(){
	pthread_t tid;
	int ret;
	
	ret = pthread_create(&tid,NULL,thread_work,NULL);
	ret = pthread_join(tid,NULL);

	ret = pthread_create(&tid,NULL,thread_work,NULL);
	ret = pthread_join(tid,NULL);

	return 0;
}
