#include<iostream>
using namespace std;
enum Color{RED,GREEN,BLUE};
int main(void){
    //Color color=100; 错误，无法与int转换,int的值域比color大
    Color color=RED;
    color=GREEN;
    int i=color; //可以，color的值域比int小
    cout<<i<<endl; 
    return 0;
}