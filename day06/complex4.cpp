#include<iostream>
using namespace std;
class Complex{
public:
    Complex(int r=0,int i=0):m_r(r),m_i(i){}
    void print(void) const{
        cout<<'('<<m_r<<'+'<<m_i<<"i)"<<endl;
    }
    Complex& operator++(void){
        ++m_r;
        ++m_i;
        return *this;
    }
    friend Complex& operator--(Complex& c){
        --c.m_r;
        --c.m_i;
        return c;
    }
    //后++
    Complex const operator++(int){
        Complex old=*this;
        ++m_r;
        ++m_i;
        return old;
    }
    //后--
    friend Complex const operator--(Complex& c,int){
        Complex old =c;
        --c.m_r;
        --c.m_i;
        return old;
    }
private:
    int m_r;
    int m_i;
};
int main(void){
    Complex c1(1,2);
    Complex c2=++c1;
    //Complex c2=c1.operator++()
    c2.print();
    c1.print();
    c2=++++c1;
    //c2=c1.operator++().operator++();
    c2.print();
    c1.print();
    --c1; //::operator--(c1);
    c1.print();
    c2=----c1;
    c2.print();
    c1.print();
    c2=c1++;
    //c2=c1.operator++(0);
    c2.print();
    c1.print();
    c2=c1--;
    //c2=::operator--(c1,0);
    c2.print();
    c1.print();
    return 0;
}