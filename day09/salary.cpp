#include<iostream>
using namespace std;
//            Employee 
//            /     |    \
//Technician    Manager    Sales
//           \      /   \      /
//           TechMnger    SalesMngr
//普通员工
class Employee{
public: 
    Employee(string const& name,int id,int grade):m_name(name),m_id(id),m_grade(grade){}
    void printInfo(void) const{
        //打印员工信息
        printBasic();  
        printExtra();
    }
    void paySalary(void){
        cout<<" 薪酬："<<calBasic()+calMerit()<<endl;
    }
protected:
    double m_attend;//出勤率
private:
    //计算基本薪酬
    double calBasic(void){
        cout<<"出勤天数：";
        int attend;
        cin>>attend;
        m_attend=attend/23.0;
        m_basic=s_grades[m_grade-1]*m_attend;
        return m_basic;
    }
    //计算绩效资金
    virtual double calMerit(void){
        return m_basic/2;
    }
    //打印基本信息
    void printBasic(void) const{
        cout<<" 姓名："<<m_name<<endl;
        cout<<" 工号："<<m_id<<endl;
        cout<<" 职级："<<m_grade<<endl;
    }
    //打印附加信息
    virtual void printExtra(void)  const{

    }
    static double s_grades[8];
    string m_name;  //姓名
    int m_id;       //工号
    int m_grade;    //职级
    double m_basic; //基本工资
};

double Employee::s_grades[]={1000,2000,3000,4000,5000,6000,7000,8000};

//经理
class Manager:virtual public Employee{
public:
    Manager(string const& name,int id,int grade,double bouns):Employee(name,id,grade),
        m_bonus(bouns){}
protected:
    void printExtra(void) const{
        cout<<"绩效资金："<<m_bonus<<endl;
    }
    double calMerit(void){
        cout<<"绩效因数：";
        double factor;
        cin>>factor;
        return m_bonus*factor*m_attend;
    }
private:
    double m_bonus; //绩效奖金 
};

//技术员
class Technician:virtual public Employee{
public:
    Technician(string const& name,int id,int grade,double allow):Employee(name,id,grade),
                m_allow(allow){}
protected:
    void printExtra(void)const{
        cout<<"研发津贴："<<m_allow<<endl;
    }
    double calMerit(void){
        cout<<"研发津贴：";
        cin>>m_allow;
        cout<<"进度因数：";
        double factor;
        cin>>factor;
        return 8*23*m_allow*factor*m_attend;
    }
private:
    double m_allow;  //研发津贴

};

//销售员
class Sales:virtual public Employee{
public:
    Sales(string const& name,int id,int grade,double comm):Employee(name,id,grade),
        m_comm(comm){}
protected:
    void printExtra(void)const{
        cout<<"提成比例："<<m_comm<<endl;
    }
    double calMerit(void){
        cout<<"销售额：";
        double saleroom;
        cin>>saleroom;
        return saleroom*m_comm;
    }
private:
    double m_comm;//提成比例
};

//技术主管
class TechMngr:public Technician,public Manager{
public:
    TechMngr(string const& name,int id,int grade,double allow,double bonus):
        Technician(name,id,grade,allow),
        Manager(name,id,grade,bonus),
        Employee(name,id,grade){}
private:
    void printExtra(void) const{
        Technician::printExtra();
        Manager::printExtra();
    }
    double calMerit(void){
        return(Technician::calMerit()+Manager::calMerit())/2;
    };
};

//销售主管
class SalesMnger:public Manager,public Sales{
public:
    SalesMnger(string const& name,int id,int grade,double comm,double bonus):
        Sales(name,id,grade,comm),
        Manager(name,id,grade,bonus),
        Employee(name,id,grade){}
private:
    void printExtra(void) const{
        Sales::printExtra();
        Manager::printExtra();
    }
    double calMerit(void){
        return(Sales::calMerit()+Manager::calMerit())/2;
    };
};

int main(void){
    /*
    Employee emp("张飞",1164,4);
    emp.printInfo();
    emp.paySalary();
    Manager mngr("赵云",1242,6,5000);
    mngr.printInfo();
    mngr.paySalary();
    
   Technician tech("关羽",1344,2,10);
   tech.printInfo();
   tech.paySalary();

   Sales  sales("黄忠",1833,3,0.1);
   sales.printInfo();
   sales.paySalary();
 
    TechMngr techMngr("刘备",1712,4,20,5000);
    techMngr.printInfo();
    techMngr.paySalary();
     */
    SalesMnger saleMngr("曹操",1144,8,0.1,5000);
    saleMngr.printInfo();
    saleMngr.paySalary();
    return 0;
}