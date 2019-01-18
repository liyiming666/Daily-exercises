#include <iostream>
#include <exception>
#include <malloc.h>
using namespace std;
int main(){
	try{
		char *p = (char*)malloc(sizeof(p));
		free(p);	
		p = NULL;
		char* p1 = p;
		//*p1 = 1; 	
		cout << *p1 << endl;	
	}catch (exception& e){
		//不能捕获异常
		//在C++中，很多错误是try{}catch{}捕获不到的，
		//比如空指针访问，野指针访问等，
		//程序都直接崩溃，不会让你捕获的。 
		cout << "Standard exception: " << e.what() << endl; 
	}
	return 0;
}
