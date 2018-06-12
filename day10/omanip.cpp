#include<iostream>
using namespace std;
ostream& red(ostream& os){
    return os<<"\033[;;31m";
}
ostream& def(ostream& os){
    return os<<"\033[0m";
}
int main(void){
    cout<<red<<"Hello,World!"<<def<<endl;
    cout<<def<<endl;
    return 0;
}