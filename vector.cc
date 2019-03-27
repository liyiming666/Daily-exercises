#include <iostream>
#include <vector>

using namespace std;
int main(){
	vector <string> r;
	r.push_back("a");
	r.push_back("b");
	r.push_back("c");
	r.push_back("d");
	for (int i=0; i<r.size(); i++){
		cout << r[i]<< endl;
	}
	return 0;
}
