#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <cstddef>
using namespace std;
 
int main(){
	string s = "8040ff00641800003b";
	int j =0;
	for(int i=0; i<s.size()/2; i++){
		string sub_s = s.substr(i+j,2);
		j++;
		char p[8] = {0};
		int ch = 0;
		sscanf(sub_s.c_str(), "%x", &ch);
		cout << ch << endl;
		bitset<8> baz( ch);
		cout << sub_s << endl;
		cout << baz << endl;
		cout << baz[0] << "|" << baz[1] << "|" << baz[2] << "|" <<
			baz[3] << "|" << baz[4] << "|" << baz[5] << "|" <<
			baz[6] << "|" << baz[7] << endl;
			cout << baz.size() << endl;
		for (size_t j=baz.size()-1; j>0; j--){
			
			cout << baz.test(j) << endl;
		}
	}
	return 0;
}
