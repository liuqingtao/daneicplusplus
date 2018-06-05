#include<iostream>
using namespace std;
class Student; //类的短式声明
class Teacher{
public:
    void educate(Student* student);
    void reply(string const& answer){
        m_answer=answer;
    }
private:
    string m_answer;
};
class Student{
public:
    void ask(const string& question,Teacher* teacher){
        cout<<"问题："<<question<<endl;
        teacher->reply("不知道！");
    }
};
void Teacher::educate(Student* student){
        student->ask("什么是this指针？",this);
        cout<<"回答："<<m_answer<<endl;
    }
int main(void){
    Teacher teacher;
    Student student;
    teacher.educate(&student);
    return 0;
}