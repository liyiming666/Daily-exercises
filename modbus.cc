#include <iostream>
#include <modbus/modbus.h>

using namespace std;
int main(){
	void* d;
	int ret =0 ;
	uint8_t *d1 = (uint8_t*) d;
	modbus_t* ctx;
	ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
	cout << "-----------" << ctx << endl;
	ret = modbus_read_bits(ctx, 1, 2, d1);
	return 0;
}
