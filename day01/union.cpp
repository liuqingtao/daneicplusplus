#include<cstdio>
using namespace std;
int main(void){
    //匿名联合
    union{
        char c[4];
        int i;
    };  
    i=0x12345678;
    printf("%#x,%#x,%#x,%#x\n",c[0],c[1],c[2],c[3]);
    return 0;
}