#include<iostream>
#include<stdexcept>
using namespace std;
class OverFlow:public exception{
private:
    char const* what(void) const throw(){
        return "我的堆栈上溢了！";
    }
};
void push(int data){
    throw OverFlow();
}
int main(void){
    try{
        push(100);
    }
    catch(exception& ex){
        cout<<ex.what()<<endl;
    }
    return 0;
}