#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

int globalVar = 1;
static int staticGlobalVar = 1;
int main()
{
	static int staticVar = 1;
	int localVar = 1;

	int num1[10] = {1, 2, 3, 4};
	char char2[] = "abcd";
	const char* pChar3 = "abcd";

	int* ptr1 = (int*)malloc(sizeof (int)*4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)*4);

	cout << sizeof(num1) << endl;  //40
	//cout << strlen(num1) << endl;  //随机值

	cout << sizeof(char2) << endl;  //5
	cout << strlen(char2) << endl;  //4

	cout << sizeof(pChar3) << endl;  //8
	cout << strlen(pChar3) << endl;  //4

	cout << sizeof(ptr1) << endl;  //8

	//int x = 0;
	//cout << sizeof(&x) << endl;
	
	free (ptr1);
	free (ptr3);
}
