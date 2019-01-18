#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <setjmp.h>
#include <stdarg.h>
using namespace std;
jmp_buf env;
void recvSignal(int sig){
	cout << "recvSignal :" << sig << endl;
	//使用setjmp,longjmp尝试跳过错误的堆栈
	longjmp(env,1);
}
int main(){
	
	for (int i=0; i<2; i++){
		int r = setjmp(env);
		cout << "setjmp after : "<< r << endl;
		if (r == 0) {
			//初次执行		
			//给信号注册处理函数
			signal(SIGSEGV, recvSignal);
			cout << "excute this code!" << endl;
			int *s =0;
			(*s) = 1;//产生段错误
		} else {
			//是由longjmp回来的
			cout << "jumo this code!" << endl;	
		}	
		sleep(4);
		cout << "sleep4 after" << endl;
	}
	while(1){
		sleep(1);
		cout << "sleep 1" << endl;
	}
	return 0;
}
