#include <iostream>
#include <mutex>
#include <stdio.h>
#include <sys/time.h>
#include <mutex>
using namespace std;
using namespace chrono;

int main(){
	//打印时间精确到秒
	char time_str[64] = {0};
	time_t t;
	time(&t);
	const char* format = "%M:%S";
	strftime(time_str, sizeof(time_str), format, localtime(&t));	
	cout << time_str << endl;
	//打印时间精确到毫秒
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long gt = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("%zd",gt/10000000000);
	
	//循环尝试上锁，且在for循环中不占用cpu时间
	std::mutex mtx;
	mtx.lock();
	time_t t1, t2;
	time(&t1);
	for (int i=0; i<255; i++){
		cout << i <<endl;
		if(mtx.try_lock()){
		}
		//const timespec ts = {0, 10}; //睡10纳秒
		const timespec ts ={0, 7000000}; //大约一个for循环结束是2秒吧
		nanosleep(&ts, NULL);
	}
	time(&t2);
	cout << "====================================> " << t2 - t1 << endl;
	mtx.unlock();
	
	

}
