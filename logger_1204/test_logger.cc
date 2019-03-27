#include <iostream>
#include <string>

#include "../../log/ssa_logger.h"

using namespace std;

int main(){
	string s = "I am wondering what should I pass as a channelNam    e and do I need to do anything else in order to receive realtime notificatio    ns? Usually 404 response codes are related to addressed resources not being     found. Are you sure that your Application ID ? What happens you when you que    ry      If I try this, I'm getting 415 Unsupported MedType. Nevertheless req    uiring GET /application/applications/28 the application has tena being manag    ement the tenant I want it to be located ";
	cout << s.size() << endl;
//	while(1){
	for (int i = 0; i < 7000; i++) {
		SSADebug(" I am wondering what should I pass as a channelName and do I need to do anything else in order to receive realtime notifications? Usually 404 response codes are related to addressed	resources not being found. Are you sure that your Application ID ? What happens you when you query	If I try this, I'm getting 415 Unsupported MedType. Nevertheless requiring GET /application/applications/28 the application has tena being management the tenant I want it to be located ");

	usleep(8000);
	}	
	return 0;
}
