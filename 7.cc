#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;
int main(){
	time_t t1, t2;
	time(&t1); 
	for (int i=0; i<255; i++){
		
		const timespec ts ={0, 7000000};
		nanosleep(&ts, NULL);
	}
	time(&t2);
	cout << "====================================> " << t2 - t1 << endl;
	return 0;
}
