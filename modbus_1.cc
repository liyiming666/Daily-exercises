#include <iostream>
#include <string>
#include <modbus/modbus.h>
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;

string getHexString(unsigned int s, const int& len)
{
        std::ostringstream out;
        out << std::hex << std::setw(2) << std::setfill('0');
        for (int i = 0; i < len; i++)
        {
               out << std::hex << std::setw(2)
                  << std::setfill('0') << static_cast<int>(s[i]) << " ";
        }
        return out.str();
}

int readBat(const int& addr, const int& nb, unsigned int req, int func_code)
{
	modbus_t* _ctx;
	_ctx = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
	int req_length = _ctx->backend->build_request_basis(
             _ctx, func_code, addr-1, nb, req);
	int ret =  _ctx->backend->send_msg_pre(req, req_length);
		
	string a = getHexString(req, ret);

        return ret;
}

int main(){
	unsigned int req[1024] = {0};
	int ret = mb.readBat(1,
		1, req, 1);

	return 0;
}
