#include<iostream>
#include<fstream>
using namespace std;
int main(void){
    ifstream ifs("get.txt");
    if(!ifs){
        cout<<"open file failue!"<<endl;
        return -1;
    }
    /*
    int ch;
    
    while((ch=ifs.get())!=EOF)
        cout<<(char)ch;
    */
   /*
   char ch;
   while(ifs.get(ch))
    cout<<ch;
    */
   /*
   char buf[1024];
   ifs.get(buf,1024);
   cout<<buf<<endl;
   ifs.ignore();
   ifs.get(buf,1024);
   cout<<buf<<endl;
   */
  /*
    char buf[1024];
    ifs.get(buf,1024,'$');
    cout<<buf<<endl;
    */
   char buf[1024];
   while(ifs.getline(buf,1024))
    cout<<buf<<endl;
    return 0;
}