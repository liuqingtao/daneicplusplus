#include<iostream>
using namespace std;
class Complex{
public:
    Complex(int r=0,int i=0):m_r(r),m_i(i){}
    void print(void) const{
        cout<<'('<<m_r<<'+'<<m_i<<"i)"<<endl;
    }
    Complex const operator-(void)const{
        return Complex(-m_r,-m_i);
    }
    friend int operator~(Complex const&c){
        return c.m_r*c.m_r+c.m_i*c.m_i;
    }
private:
    int m_r;
    int m_i;
};
int main(void){
    Complex c1(1,2);
    Complex c2=-c1;
    c2.print();
    int r=~c1;
    cout<<r<<endl;
    return 0;
}