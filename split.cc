#include <iostream>
#include <string>
#include <vector>
using namespace std;
class String{
public:
	String(const string s):_str(s){}
	~String(){}	
	vector<string> split(const char *l){
		vector<string> v;
		size_t pos = 0;
		string s1 = _str;
		while((pos= s1.find(l)) != string::npos){
			const string& s= s1.substr(0, pos);
			v.push_back(s);
			s1 = s1.substr(pos+1, _str.size()); 
		}	
		v.push_back(s1);
		return v;
	}
 	//string类本身自带replace字符串替换功能	
private:
	string _str;
};
int main(){
	String s("hello,world");
	vector <string> v = s.split(",");
	cout << v[0] << "|" << v[1] << endl;
	
	return 0;
}

