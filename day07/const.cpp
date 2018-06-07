#include<iostream>
using namespace std;
class Base{
public:
    Base(void){
        cout<<"Base::Base(void)"<<endl;
    }
    Base(int x){
        cout<<"Base::Base(int)"<<endl;
    }
    Base(int x,int y){
        cout<<"Base::Base(int,int)"<<endl;
    }
};
class Derived:public Base{
public:
    /*
    Derived(void){
        cout<<"Derived:derived(void)"<<endl;
    }
    */
   Derived(void):Base(){
        cout<<"Derived:derived(void):Base()"<<endl;
   }
   Derived(int x):Base(x){
        cout<<"Derived(int x):Base(x)"<<endl;
   }
   Derived(int x,int y):Base(x,y){
        cout<<"Derived(int x,int y):Base(x,y)"<<endl;
   }

};
int main(void){
    Derived d1;
    Derived d2(10);
    Derived d3(10,20);
    return 0;
}