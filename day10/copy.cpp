#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char* argv[]){
    if(argc<3){
        cout<<"用法："<<argv[0]<<"<源文件> <目标文件>"<<endl;
        return -1;
    }
    ifstream ifs(argv[1],ios::binary);
    if(!ifs){
        cerr<<"open failure!"<<endl;
        return -1;
    }
    ofstream ofs(argv[2],ios::binary);
    if(!ofs){
        cerr<<"open failure!"<<endl;
        return -1;
    }
    char buf[1024];
    while(ifs.read(buf,1024))
       if(!ofs.write(buf,1024)){
           cerr<<"write failure!"<<endl;
           return -1;
       }
    if(!ifs.eof()){
        cerr<<"读源文件失败"<<endl;
        return -1;
    }
    if(!ofs.write(buf,ifs.gcount())){
        cerr<<"写目标 文件 失败"<<endl;
        return -1;
    }
}