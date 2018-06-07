#include<cstring>
#include<iostream>
using namespace std;
class String{
public:
    //接受C风格的字符串的（类型转换）构造函数
    String(char const* str=NULL):
        m_str(strcpy(new char[strlen(str ? str:"")+1],str ? str:"")){}
    //拷贝构造函数
    String(String const& that):
        m_str(strcpy(new char[strlen(that.m_str)+1],that.m_str)){}
    //拷贝赋值
  /* 模版
   String& operator=(String const& rhs){
       if(&rhs != this){
           char *str=new char[strlen(rhs.m_str)+1];
           delete[] m_str;
          m_str= strcpy(str,rhs.m_str);
       }
       return *this;
   }
   */
  //老鸟
    String & operator=(String const& rhs){
        if(&rhs !=this){
            String str(rhs);
            swap(m_str,str.m_str);
        }
        return *this;
    }
    //析构函数
    ~String(void){
        if(m_str){
            delete[] m_str;
            m_str=NULL;
        }
    }
    //获取C风格字符串
    char const* c_str(void) const{
        return m_str;
    }
private:
    char* m_str;
};
int main(void){
    String s1("达内科技");
    cout<<s1.c_str()<<endl;
    String s2=s1;
    cout<<s2.c_str()<<endl;
    String s3("hello");
    s1=s3;
    cout<<s1.c_str()<<endl;
    return 0;
}