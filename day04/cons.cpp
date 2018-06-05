#include<iostream>
using namespace std;
class Integer{

public:
	//无参构造函数，缺省构造函数
	Integer(void){
		m_i=0;
	}
	//单参构造函数，类型转换构造函数
	Integer(int i){
		m_i=i;
	}
	int& value(void){
		return m_i;
	}
private:
	int m_i;
};
int main(void){
	Integer i1;
	cout<<i1.value()<<endl;	//0
	Integer i2(10);
	cout<<i2.value()<<endl;	//10
	i2=100; 	//i2=Integer(100);
	cout<<i2.value()<<endl;	//100
	return 0;
}
