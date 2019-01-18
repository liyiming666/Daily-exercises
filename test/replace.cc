#include <iostream>
#include <string>
//字符串的替换
using namespace std;
int main(){
	size_t ops;
	string a = "abcd";
	string b = a.replace(1,2,"yz");
	cout << b << endl;
	return 0;
}
