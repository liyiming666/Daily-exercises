#include <iostream>
using namespace std;

int main(){
	unsigned char *p = NULL; 
	unsigned char a[8] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
	p= a;
	int analyticalType =2;
	int bytes = 4;
	int nobit =32;
	int d = 0x00;
	for (int j = 0; j < bytes; j++) {
		if (analyticalType == 0 && bytes == 2) 
		{
			d += ((*p) <<( nobit/2)) + *(p+1);
		}
		else if (analyticalType == 1 && bytes == 2) 
		{
			d += ((*p+1) <<(nobit/2)) + *(p);
			cout << d << endl;
		}
		else if (analyticalType == 2 && bytes == 4)
		{
			cout << *p <<endl;
			d +=((*p) <<( nobit/2)*(bytes-j-1));
			cout << "( nobit/2)" << ( nobit/2) <<endl;
			cout << "( nobit/2)*(bytes-j-1))" << ( nobit/2)*(bytes-j-1) << endl;
			cout << "----------------------------" <<d<< endl;
		}
		else if (analyticalType == 3 && bytes == 4)
		{
			
		}
		else if (analyticalType == 4 && bytes == 4)
		{
			d;
		}
		else if (analyticalType == 5 && bytes == 4)
			d;
	p++;
	}
	cout << d << endl;

	
}
