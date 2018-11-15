#include <map>
#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
        map<int, int> m;
        for (int i = 0; i < 100; i++) {
                m[i] = i;
        }

        map<int, int>::reverse_iterator it =m.rbegin();

	printf("%d\n",it->first);
	it->second = it->second +1;
	printf("%d\n",it->first);
	printf("%d\n",it->second);

	return 0;
}
