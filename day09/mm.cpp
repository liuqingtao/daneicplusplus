#include<iostream>
using namespace std;
class A{
public:
    virtual void  foo(void){
        cout<<"A::foo(void)"<<endl;
    }
};
class B{
public:
    virtual void bar(void){
        cout<<"B::bar(void)"<<endl;
    }
};
class C:public  A,public B{
public :
    void foo(void){
        cout<<"C:foo(void)"<<endl;
    }
    void bar(void){
        cout<<"C::bar(void)"<<endl;
    }
};
int main(void){
    C c;
    A* p=&c;
    p->foo();
    B& r=c;
    //r.foo(); 编译错误，编译器检查B类型中没有 foo函数
    r.bar();
}