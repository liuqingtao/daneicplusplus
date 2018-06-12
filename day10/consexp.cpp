#include<iostream>
#include<memory>
using namespace std;
class A{
public:
    A(void){
        cout<<"A构造"<<endl;
    }
    ~A(void){cout<<"A析构"<<endl;}
};
class B{
public:
    B(void):m_a(new A){
        cout<<"B构造"<<endl;
        //delete m_a;
        throw -1;
    }
    ~B(void){
        cout<<"B析构"<<endl;
        //delete m_a;
    }
private:
//    A m_a;
        //A* m_a;
        auto_ptr<A> m_a;
};
int main(void){
    try{
        B b;
    }
    catch(int ex){
        cout<<ex<<endl;
        return -1;
    }
    return 0;
}