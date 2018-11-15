#include <iostream>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

int main(){
        hash_map<int, string, string> mymap;
        mymap[9527]="唐伯虎点秋香","aa";
	cout << mymap[9527] << endl;	

	return 0;	
}
