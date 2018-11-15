#include <iostream>
#include <time.h>
int main(){
	time_t t1,t2;
	
	int j=0;
	for(long i=0; i<10000000000; i++){
		j=i+j;
	}
	
	return 0;
}
