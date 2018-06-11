#include<iostream>
#include<cstring>
using namespace std;
class A{
public:
    virtual  void foo(void){
        cout<<"A::foo(void)"<<endl;
    }
};
class B:public A{
public:
    void foo(void){
        cout<<"B::foo(void)"<<endl;
    }
};
int main(void){
    A a;
    a.foo();
    B b;
    b.foo();
    //a=b; //对象截切，会把虚表指针改为a类型
    memcpy(&a,&b,sizeof(a)); //指针复制会把b类型的虚表指针给a，所以调用b的。
    a.foo();
    A* p=&a;
    p->foo();
    return 0;
}