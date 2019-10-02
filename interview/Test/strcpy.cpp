#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;
void * my_memmove ( void * dest, const void * src, size_t num );
char* my_strcpy(char* dest,const char* src){
	assert(NULL != dest && NULL != src);

	//char* cur = dest;
	//while ((*cur++ = *src++) != '\0') {
	//	;
      	//}
      	
	my_memmove(dest,src,strlen(src)+1);

	return dest;
}

void * my_memmove ( void * dest, const void * src, size_t num ){
	assert(NULL != dest && NULL != src);

	char *cur = (char*)dest;
	char *src_ = (char*)src;
	if (cur >= src_ && cur <= (src_+num-1)) {
		cur = cur+num-1;
		src_ = src_+num-1;
		while(num--){
			*cur-- = *src_--;
		}
	}
	else{
		while(num--){
			*cur++ = *src_++;
		}
	}
}
int main(){
	//char dest[100];
	//const char* src = "Hello Word!";

	//考虑内存重叠问题
	char dest[100] = "Hello Word!";
	char *ret = my_strcpy(dest+1,dest);
	
	cout << dest << endl;
	return 0;
}
