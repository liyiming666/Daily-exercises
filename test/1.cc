#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
//读取json格式数据，打印
int main(){
	FILE *fd = NULL;
	fd = fopen("./o.out_bak","r");
	if(fd == NULL){
		perror("open file error.\n");
		fclose(fd);
		fd = NULL;
		return 0;
	}
	//读取每行，存入map<int , vector<string>>
	string str;
	unsigned char *buf = NULL;
	size_t line = 0;
	map <int ,vector<string>> m;
	vector<string> v;
	while(1){
		size_t t = getline((char **)&buf ,&line , fd);//line会自己+
		v = {(char *)buf, to_string(t)};//我们把vector存成数组
		m.insert (pair<int, vector<string>>(line,v)); //map的初始化，key:line value:是一个v
		
		//feof这个函数用于判断fd是否指向了底部，已经没有数据了
		if(feof(fd)){
			perror("file end.\n");
            fclose(fd);
            fd = NULL;
			break;
		}
	}
	
		
	//下面遍历map,还有格式话输出json对应的值，避免错误
	map<int, vector<string>> ::iterator it = m.begin();
	
	ostringstream out;
	for(int i = 0 ; it != m.end() ; it++){
		out << std::hex << std::setw(2) <<std::setfill('0');//
		for (int t = 0; t < atoi(it->second[1].c_str()); t++) {
	        out << static_cast<int>(it->second[0][t]) << " "; //
        }
		 cerr << it->first << "--" << out.str() <<"-----" << it->second[1] <<endl;

	}


	return 0;
}
