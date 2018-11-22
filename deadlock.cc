#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <mutex>
using namespace std;
std::mutex mtx;
void* fun(void* args){
	mtx.lock();	
	cout << "child, the tid -----:" << pthread_self() << endl;
	cout << "pthread" << endl;
	//mtx.unlock();
	return 0;
}
int main(){
	pthread_t tids[2];
	for(int i=0; i<2; i++){
		int ret = pthread_create(&tids[i], NULL, fun, NULL);
		//cout << "parent, the tid = " << pthread_self() << endl;
	}
	mtx.lock();	
	cout << "parent, the tid -----:" << pthread_self() << endl;
	mtx.unlock();	
	cout << "---------"<< endl;
	pthread_exit(NULL);
	return 0;
}
