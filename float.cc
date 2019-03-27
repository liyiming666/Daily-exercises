#include <stdio.h>
 
int main()
{
    float pi = 3.14f;
    char (*bytes)[4] = (char (*)[4])π
     
    printf("%02hhX %02hhX %02hhX %02hhX\n", (*bytes)[3], (*bytes)[2], (*bytes)[1], (*bytes)[0]);
}
