#include <iostream>
#include <string>
#include <map>
using namespace std;
class String{
public:
	String(const string s):_str(s){}
	~String(){}	
	map<string> split(const char *l){
		
	}
private:
	int _len;
	string _str;
};
int main(){
	int i = 84468375;
	string s_i = to_string(i);
	cout << s_i << endl;	
	return 0;
}

