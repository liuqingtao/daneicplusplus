#include<iostream>
#include<ostream>
#include<cstdio>
#include<sstream>
using namespace std;
int main(void){
    int n=123;
    double d=4.56;
    const char* s="hello";
    /*
    char buf[256];
    sprintf(buf,"%d %g %s",n,d,s);
    cout<<buf<<endl;
    */
    ostringstream oss;
    oss<<n<<' '<<d<<' '<<s;
    string str=oss.str();
    cout<<str<<endl;
    istringstream iss("world 3.54 321");
    iss>>str>>d>>n;
    cout<<str<<endl;
    cout<<d<<endl;
    cout<<n<<endl;
    return 0;
}