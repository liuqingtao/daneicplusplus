#include<iostream>
using namespace std;
class Square{
public:
    int operator() (int i)const{
        return i*i;
    }
    double operator()(double d)const{
        return d*d;
    }
};
int main(void){
    Square square;
    cout<<square(2)<<endl;
    //cout<<square.opreator()(2)<<endl;
    cout<<square(3.0)<<endl;
    return 0;
}