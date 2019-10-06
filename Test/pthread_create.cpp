#include <iostream>
#include <pthread.h>

using namespace std;
void * thread_work (void* param) {
	cout << "void * thread_work (void* param)" << endl;
	pthread_exit(NULL);
	return NULL;
}
int main(){
	int ret = 0;
	pthread_t tid;

	ret = pthread_create(&tid,NULL,thread_work,NULL);
	cout << ret << endl;
	if(0 != ret){
		cout << "errno is " << ret << endl;
	}
	pthread_join(tid,NULL);	

	return 0;
}
