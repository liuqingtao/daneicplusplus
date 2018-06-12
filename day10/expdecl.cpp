#include<cstdlib>
#include<iostream>
using namespace std;
void foo(int i) throw(int,double,char const*){
    if(i==1)
        throw 100;
    if(i==2)
        throw 3.14;
    if(i==3)
        throw "hello,world!";
}
int main(int argc,char* argv[]){
    try{
        foo(atoi(argv[1]));
        
    }
    catch(int ex){
        cout<<ex<<endl;
    }
    catch(double ex){
        cout<<ex<<endl;
    }
    catch(char const* ex){
        cout<<ex<<endl;
    }
    return 0;
}