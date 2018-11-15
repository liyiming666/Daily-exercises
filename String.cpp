#include <iostream>
#include <cstring>
//String类的实现
using namespace std;
class String{
public:
	String(const char* str=""){
		m_str = new char[strlen(str)+1];
		strcpy(m_str,str);				
	}
	~String(void){
	
	}
	String(const String& that){
		cout << "拷贝构造" <<endl;
		m_str = new char[strlen(that.m_str)+1];
		strcpy(m_str, that.m_str);
	}
	String operator=(const String& that){
		cout << "拷贝赋值" <<endl;
		if(&that != this){
			delete[] m_str;	
			m_str = new char[strlen(that.m_str)+1];
			strcpy(m_str,that.m_str);
		}
		return *this;
	}
	const char* c_str(void)const{
		return m_str;
	}
private:	
	char* m_str;
};

int main(){
	String s1("hello");
	cout << s1.c_str() << endl;
	String s2(s1);
	cout << s2.c_str() << endl;
	String s3("dd");
	s3 = s2;
	cout << s3.c_str() << endl;
	
}
