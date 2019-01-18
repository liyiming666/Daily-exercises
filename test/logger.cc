#include <iostream>
#include <string>

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h> // 日志输出宏
#include <log4cplus/consoleappender.h> // 将日志输出到控制台
#include <log4cplus/fileappender.h> // 将日志输出到文件
#include <log4cplus/layout.h>       // 输出格式控制
#include <log4cplus/loglevel.h>
#include <iomanip>
#include <unistd.h>
#include <memory>
#include <map>

using namespace std;

enum LoggerLavel {
	TRACE = 0,
	DEBUG,
	INFO,
	WARN,
	ERROR,
	FATAL	
};

class Logger : public log4cplus::Logger{
public:	
	Logger(const string& name, 
		const string& pattern="%D{20%y-%m-%d %H:%M:%S} %p: %m%n", 
		LoggerLavel level = WARN){

	}
	virtual ~Logger(){

	}
public:
	void init(){

	}
	
	void setLogLevel(LoggerLavel lvl){
		
	}	
	
	void log()	
private:
	
}










