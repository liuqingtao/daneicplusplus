#include<iostream>
using namespace std;
//电话
class Phone{
public:
    Phone(string const& no):m_no(no){
        cout<<"Phone构造："<<this<<endl;
    }
    void call(string const& no){
        cout<<m_no<<"呼叫"<<no<<endl;
    }
    ~Phone(void){
        cout<<"Phone析构"<<this<<endl;
    }
private:
    string m_no;
};
//播放器
class Player{
public:
    Player(string const& media):m_media(media){
        cout<<"Player构造："<<this<<endl;
    }
    void play(string const& clip){
        cout<<m_media<<"播放器播放"<<clip<<endl;
    }
    ~Player(void){
        cout<<"Player析构："<<this<<endl;
    }
private:
    string m_media;
};
//电脑
class Computer{
public:
    Computer(string const& os):m_os(os){
        cout<<"Computer构造： "<<this<<endl;
    }
    void run(string const& app){
        cout<<"在"<<m_os<<"上运行"<<app<<endl;
    }
    ~Computer(void){
        cout<<"Computer析构："<<this<<endl;
    }
private:
    string m_os;
};
//智能手机
class SmartPhone:public Phone,public Player,public Computer{
public:
    SmartPhone(string const& no,string const& media,string const& os):
        Phone(no),Player(media),Computer(os){
            cout<<"SmartPhone构造："<<this<<endl;
        }
    ~SmartPhone(void){
        cout<<"SmartPhone析构："<<this<<endl;
    }

};
int main(void){
    SmartPhone sp("15210621839","mp3/mp4/3GP","android");
    sp.call("15010037259");
    sp.play("小苹果");
    sp.run("C++大战Java");
    cout<<"&sp="<<&sp<<endl;
    Player* pPlayer=&sp;
    cout<<"pPlayer="<<pPlayer<<endl;
    SmartPhone* pSmart=static_cast<SmartPhone*>(pPlayer);
    cout<<"pSmart="<<pSmart<<endl;
    return 0;
}