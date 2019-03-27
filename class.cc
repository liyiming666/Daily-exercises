#include <iostream>
#include <vector>
using namespace std;
class A{
public:
	void print(){
		cout << "a"<< endl;
	}
};
int main(){
	vector<A> va;
	for (int i=0; i<10; i++){
		A a;
		cout <<"__ i :" << i <<endl;
		va.push_back(a);
		cout <<"______ i :" << i <<endl;
	}

}
