#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	struct message{
		string sid;
		string badge_nbr;
		string mfg_cd;
		string spid;
	} mess;
	mess.sid= "1";
	mess.badge_nbr = "badge_nbr";
	mess.mfg_cd = "mfg_cd";
	mess.spid = "spid";
	printf(" %s \n", mess.sid.c_str());
	printf(" %p \n", &(mess.badge_nbr)); //不行啊
	printf(" %p \n", &(mess.sid) ); //不行啊
	int a = &(mess.badge_nbr)-&(mess.sid);
	cout << *(&(mess.badge_nbr)+1) << endl; ;
	

	return 0;
}
