#include <stdio.h>
#include <string.h>
#include <modbus/modbus.h>
#include <modbus/modbus-rtu.h>
#include <unistd.h>

int main(int argc, char * argv[])
{

	modbus_t * m_modbus;
	int i, addr, act;
	int ret = 0;
	m_modbus = modbus_new_rtu("/dev/ttyUSB0", 9600, 'N', 8, 1);
	//波特率9600,比特位8，校验位1，无等价位
	modbus_set_debug(m_modbus, 0);
	//设置为1将可以看到调试信息
	struct timeval response_timeout;
	response_timeout.tv_sec = 1;

	response_timeout.tv_usec = 0;
	modbus_set_response_timeout(m_modbus,&response_timeout);
	//设置等待延时时间
	if(m_modbus && modbus_connect(m_modbus) == -1) {
		printf("\nSorry,fail to connect ttyS0,please check your device's state.\n");
	} else {
		printf("Connected to dev!\n");
		//connected = 1;
	}

	if(m_modbus == NULL) 
	{
		printf("No connection,check your device!\n");
		//return;
	}
	/* //注释中的代码作用是读取串口的4个端口数据
	*/
	uint8_t dest[4]; //setup memory for data
	uint16_t * dest16 = (uint16_t *) dest;
	memset(dest, 0, 4);
	modbus_set_slave(m_modbus, 0);
	/* //本段注释代码给指定端口赋值
	*/
	ret = modbus_read_bits(m_modbus, 0, 4, dest);
	printf("%d\n", ret);
	for(i = 0; i < 4 ; i++)
	{
		printf("\n%d:%4d",i,dest[i]);
	}
		for(i = 0; i < 4 ; i++)
	{
		ret = modbus_write_bit(m_modbus, i , 1);
		if(ret)
		{
		printf("成功写入数据！返回值：%d\n",ret);
		}
		else	
		{
		printf("写入数据失败，返回值：%d",ret);
		}
		sleep(2);
	}

//断开连接
if(m_modbus) {
modbus_close(m_modbus);
modbus_free(m_modbus);
m_modbus = NULL;
}
printf("Disconnect succeed!\n");
return 0;
}
