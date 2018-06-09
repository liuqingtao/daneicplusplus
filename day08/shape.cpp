#include<iostream>
using namespace std;
//形状：位置、绘制
//|
//+--圆形：半径、（绘制）
//+--矩形：长、宽、（绘制）
class Shape{
public:
    Shape(int x,int y):m_x(x),m_y(y){}
    virtual void draw(void) const=0; //纯虚函数
protected:
    int m_x;
    int m_y;
};
//圆形
class Circle:public Shape{
public:
    Circle(int x,int y,int r):Shape(x,y),m_r(r){}
    void draw(void) const{
        cout<<"圆形（"<<m_x<<','<<m_y<<','<<m_r<<')'<<endl;
    }
private:
    int m_r;
};
class Rectangle:public Shape{
public:
    Rectangle(int x,int y,int w,int h):Shape(x,y),m_w(w),m_h(h){}
    void draw(void) const{
        cout<<"矩形（"<<m_x<<','<<m_y<<','<<m_w<<','<<m_h<<')'<<endl;
    }
private:
    int m_w;
    int m_h;
};
void render(Shape* shapes[]){
    for(size_t i=0;shapes[i];++i){
        shapes[i]->draw();
    }
}
void drawAny (Shape const& shape){
    shape.draw();
}
int main(void){
    Shape* shapes[1024]={0};
    shapes[0]=new Circle(1,2,3);
    shapes[1]=new Circle(4,5,6);
    shapes[2]=new Rectangle(7,8,9,10);
    shapes[3]=new Rectangle(11,12,13,14);
    shapes[4]=new Rectangle(15,16,17,18);
    render(shapes);
    Circle c(18,19,20);
    Shape& r=c;
    r.draw();
    Rectangle rc(21,22,23,24);
    drawAny(rc);
    return 0;
}

