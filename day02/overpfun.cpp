#include<iostream>
using namespace std;
void foo(void){
    cout<<"foo(void)"<<endl;
}
void foo(int x){
    cout<<"foo(int)"<<endl;
}
void foo(double d){
    cout<<"foo(double)"<<endl;
}
int main(void){
    //根据函数指针类型中的参数表信息来决定其所指向的重载版本
    void(*pfun1)(void)=foo;
    void(*pfun2)(int)=foo;
    void(*pfun3)(double)=foo;
    pfun1();
    pfun2(123);
    pfun3(1.23);
    return 0;
}
