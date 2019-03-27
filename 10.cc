#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <math.h>
using namespace std;


unsigned int getbitu(const unsigned char *buff, int pos, int len)
{
    unsigned int bits=0;
    int i;
    for (i=pos;i<pos+len;i++)
    {
        bits=(bits<<1)+((buff[i/8]>>(7-i%8))&1u);   //从高位到低位逐位计算
    }
    return bits;
}

float HexToFloat(const unsigned char *buf)
{
    float value = 0.0;
    unsigned int i = 0;
    unsigned int num, temp;
    int num2;
    bool flags1 = true;

    num = getbitu(buf, i, 1); //标志位
    i = i + 1;
//指数部分,float型数据其规定偏移量为127,阶码有正有负，对于8位二进制，则其表示范围为-128-127
    num2 = getbitu(buf, i, 8) - 127;
    i = i + 8;

    while(1)
    {
        if(flags1)
        {
            value += 1 * pow(2, num2);
            num2--;
            flags1 = false;
        }
        temp = getbitu(buf, i, 1);
        i += 1;
        value += temp * pow(2, num2);
        num2--;

        if(i == 32)
            break;
    }

    if(num == 1)
        value *= -1;

    return value;
}

double HexToDouble(const unsigned char* buf)
{
    double value = 0;
    unsigned int i = 0;
    unsigned int num,temp;
    int num2;
    bool flags1 = true;

    num = getbitu(buf,i,1); //标志位
    i += 1;
//double型规定偏移量为1023，其表示范围为-1024-1023
    num2 = getbitu(buf,i,11) - 1023;
    i += 11;

    while(1)
    {
        if(flags1)
        {
            flags1 = false;
            value += 1 * pow(2,num2); num2--;
        }
        temp = getbitu(buf,i,1);    i += 1;
        value += temp * pow(2,num2); num2--;
        if(i == 64)
            break;
    }
    if(num == 1)
        value *= -1;

    return value;
}


int main(void)
{
        unsigned char buf[8] = {
//                0x40, 0x06, 0x66, 0x66,
                0x00, 0x00, 0x00, 0x01
        };
        double value = HexToFloat(buf);
        cerr << value << endl;

        return 0;
}
