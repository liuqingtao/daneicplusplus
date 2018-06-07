#include<iostream>
using namespace std;
//人类
class Human{
public:
    Human(string const& name,int age):m_name(name),m_age(age){
        cout<<"Human构造:"<<this<<endl;
    }
    ~Human(void){
        cout<<"Human析构："<<this<<endl;
    }
    void eat(string const& food){
        cout<<"我在吃"<<food<<"."<<endl;
    }
    void sleep(string const& loc){
        cout<<"我在"<<loc<<"睡觉"<<endl;
    }
    void who(void){
        cout<<"我叫"<<m_name<<", 今年"<<m_age<<"岁。"<<endl;
    }
    void print(void) const{
        cout<<"hello"<<endl;
    }
    string  m_name;
    int m_age;
private:
    int m_a;
protected:
    int m_c;
};
//学生类
class Student:public Human{
public:
    Student(string const& name,int age,int no):Human(name,age),m_no(no){
        cout<<"Student构造："<<this<<' '<<&m_no<<endl;
    }
    ~Student(void){
        cout<<"Student析构"<<this<<endl;
    }
    void learn(string const& course){
        cout<<"我是一个学生，学号 "<<m_no<<",  我在学"<<course<<"."<<endl;
    }
    
    void foo(void){
        //m_a=100; 基类的私有成员子类无法访问
        m_c=100; //保护成员可以在自己和自己的子类中访问
    }

    int m_no;    
};
//教师类
class Teacher:public Human{
public:
    Teacher(string const& name,int age,float salary):Human(name,age),m_salary(salary){
        cout<<"Teacher构造："<<this<<' '<<&m_salary<<endl;
    }
    ~Teacher(void){
        cout<<"Teacher析构 "<<this<<endl;
    }
    void teach(string const& course){
        cout<<"我是老师，工资 "<<m_salary<<", 我在教 "<<course<<endl;
    }
    float m_salary;
    int print;
};
int main(void){
    Student s1("张飞",25,1001);
    cout<<s1.m_name<<endl;
    cout<<s1.m_age<<endl;
    cout<<s1.m_no<<endl;
    s1.who();
    s1.eat("包子");
    s1.sleep("地上");
    s1.learn("c++");
    Teacher t1("赵云",45,20000);
    cout<<t1.m_name<<endl;
    cout<<t1.m_age<<endl;
    cout<<t1.m_salary<<endl;
    t1.who();
    t1.eat("驴肉火烧");
    t1.sleep("沙发上");
    t1.teach("c++");
    cout<<sizeof(Human)<<endl;
    cout<<sizeof(Student)<<endl;
    cout<<sizeof(Teacher)<<endl;
    Human* ph=&s1;//Is a....
    cout<<ph->m_name<<endl;
    cout<<ph->m_age<<endl;
    ph->who();
    Student* ps=static_cast<Student*>(ph);
    cout<<ps->m_no<<endl;
    /*Human没有m_no，导致风险
    Human h1("关羽",25);
    ps =static_cast<Student*>(&h1);
    cout<<ps->m_no<<endl;
    */
   //谨慎 使用对象截切
    Human h1=s1;
    cout<<h1.m_name<<endl;
    cout<<h1.m_age<<endl;
    t1.Human::print();
    return 0;
}

