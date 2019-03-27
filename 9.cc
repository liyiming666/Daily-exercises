#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>


using namespace std;

int bat(int d, int& sb, int& nb, string& is_signed) {         
	unsigned long t = ((1ULL << nb) - 1) << sb;         
	d &= t;         
	d = (d >> sb);         
	if (is_signed == "true") {   
	         if (nb == 1) {        
	                 return d;
                 }                 
		if ((d >> (nb - 1)) & 1) { // 负数                         
			d = ~d + 1;      
	                d &= (1ULL << nb) - 1;
                        d = ~d + 1;
                 } else {
                         d &= (1ULL << nb) - 1; 
                }     
	 } else {               
		d &= (1ULL << nb) - 1;  
       	 }
         return d; 
}

int main() {
	int a = 0;
	int b = 32;	
	string c = "false";
	int i = bat(-65538,a,b,c);
	cout << i << endl;
	cout << sizeof(long)<< endl;
	return 0;
}
