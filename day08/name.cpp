#include<iostream>
using namespace std;
class A{
public:
    void foo(void){
        cout<<"A::foo(void)"<<endl;
    }
};
class B{
public:
    void foo(int x){
        cout<<"B::foo(int)"<<endl;
    }
};
class C:public A,public B{
public:
    void foo(int f,int x){
        if(f==1)
            A::foo();
        else if(f==2)
            B::foo(x);
    }
/*
    using A::foo;
    using B::foo;
*/
};
int main(void){
    C c;
    /*
    c.A::foo();
    c.B::foo(10);
    */
   /*
   c.foo();
   c.foo(10);
   */
  c.foo(1,0);
  c.foo(2,10);
    return 0;
}