#include<iostream>
using namespace std;
void foo(int a,int b=100){
        cout<<a<<endl;
        cout<<b<<endl;
    }
int main(void){
    foo(100);
    return 0;
}