#include <iostream> 
#include <sys/time.h>
using namespace std;
int main(){
	time_t tm;
	time(&tm);
	cout << tm << endl;
	for (int i = 0; i<100000000; i++){
		cout << "--" << endl;
	}
	time(&tm);
	cout << tm << endl;

	return 0;
}
