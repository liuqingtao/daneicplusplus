#include<iostream>
using namespace std;
class A{
public:
    A(int data):m_data(data){
        cout<<"A构造:"<<this<<endl;
    }
protected:
    int m_data;
};
class B:virtual public A{
public:
    B(int data):A(data){
        cout<<"B构造："<<this<<endl;
    }
    void set(int data){
        cout<<"B:"<<&m_data<<endl;
        m_data=data;
    }
};
class C:virtual public A{
public:
    C(int data):A(data){
        cout<<"C构造："<<this<<endl;
    }
    int get(void)const{
        cout<<"C:"<<&m_data<<endl;
        return m_data;
    }
};
class D:public B,public C{
public:
    D(int data):B(data),C(data),A(data){
        cout<<"D构造："<<this<<endl;
    }
};
int main(void)
{
    D d(100);
    d.set(200);
    cout<<sizeof(d)<<endl;
    cout<<d.get()<<endl;
}