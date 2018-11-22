#include <iostream>
#include <mutex>
#include <stdio.h>
#include <sys/time.h>
using namespace std;
using namespace chrono;

int main(){
	char time_str[64] = {0};
	time_t t;
	time(&t);
	const char* format = "%M:%S";
	strftime(time_str, sizeof(time_str), format, localtime(&t));	
	cout << time_str << endl;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long gt = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%zd",gt/10000000000);

}
