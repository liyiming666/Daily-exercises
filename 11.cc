#include <iostream>
#include <vector>
#include <string.h>
#include <map>
int main(){
	vector<std::string> _rtu_slave_to_sid;
	_rtu_slave_to_sid.push("1");
	_rtu_slave_to_sid.push("2");
	_rtu_slave_to_sid.push("3");
	vector<std::string>::iterator it= _rtu_slave_to_sid.begin();
	while(*it! = NULL){
		cout << *it << endl;
		it++;
	}
	return 0;
}
