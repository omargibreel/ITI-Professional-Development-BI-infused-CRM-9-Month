#include"graphics.h"
#include<iostream>
using namespace std;
class Point
{
    private:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    void SetY(int _y){y=_y;}
    int GetY(){return y;}

    Point()
    {
        x=y=0;
    }
    Point(int _x,int _y)
    {
        x=_x;y=_y;
    }

    ~Point(){}

    Point(const Point& old)
    {
        x=old.x;
        y=old.y;

    }
};

class Shape
{
protected:
    int myColor;
public:
    void SetMyColor(int _mycolor){myColor=_mycolor;}
    int GetMyColor(){return myColor;}
    Shape()
    {
        myColor=0;
    }
    Shape(int _color)
    {
        myColor = _color;
    }
    ~Shape(){}
};
class MyLine:public Shape
{
    private:
    Point start;
    Point end;
    public:
    void SetStart(Point _start)
    {
        start=_start;
    }
    Point GetStart()
    {
        return start;
    }
    void SetEnd(Point _end)
    {
        end=_end;
    }
    Point GetEnd()
    {
        return end;
    }
    MyLine()
    {
    }

    MyLine(int x1,int y1,int x2,int y2,int _color):start(x1,y1),end(x2,y2),Shape(_color)
    {
    }
    ~MyLine(){}
    MyLine(const MyLine& old)
    {
        start=old.start;
        end=old.end;
        myColor=old.myColor;
    }
    void Draw()
    {
        setcolor(myColor);
        line(start.GetX(),start.GetY(),end.GetX(),end.GetY());
    }

};

class Rect:public Shape
{
    private:
    Point ul;
    Point lr;
    public:
    Rect()
    {
    }
    Rect(int x1,int y1,int x2,int y2,int _color)
    :ul(x1,y1),lr(x2,y2),Shape(_color)
    {
    }
    ~Rect(){}
    Rect(const Rect& old){}
    void Draw()
    {
        setcolor(myColor);
        rectangle(ul.GetX(),ul.GetY(),lr.GetX(),lr.GetY());
    }
};

class MyCircle:public Shape
{
    int radius;
    Point center;
    public:
    MyCircle(int x1,int y1,int color,int _raduis):center(x1,y1),Shape(color){
    radius = _raduis;
    }
    void Draw()
    {
        setcolor(myColor);
        circle(center.GetX(),center.GetY(),myColor);
    }
    MyCircle(const MyCircle& old)
    {
        radius=old.radius;
        center=old.center;
        myColor=old.myColor;
    }

};
class MyTri:public Shape
{
    Point p1;
    Point p2;
    Point p3;
    public:
    MyTri(int x1,int y1,int x2,int y2,int x3,int y3,int _color):p1(x1,y1),p2(x2,y2),p3(x3,y3),Shape(_color){
    }
    void Draw()
    {
        setcolor(myColor);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
        line(p2.GetX(),p2.GetY(),p3.GetX(),p3.GetY());
        line(p3.GetX(),p3.GetY(),p1.GetX(),p1.GetY());
    }
    MyTri(const MyTri& old)
    {
        p1=old.p1;
        p2=old.p2;
        p3=old.p3;
        myColor=old.myColor;
    }
};

class Picture
{
    private:
    MyLine *lPtr;
    int lSize;
    Rect *rPtr;
    int rSize;
    MyCircle *cPtr;
    int cSize;
    MyTri *tPtr;
    int tSize;
    public:
    Picture()
    {
        lPtr = NULL;
        lSize = 0;
        rPtr = NULL;
        rSize = 0;
    }
    void SetLines(MyLine* _lPtr , int _lSize)
    {
        lPtr = _lPtr;
        lSize = _lSize;
    }
     void SetRect(Rect* _rPtr , int _rSize)
    {
        rPtr = _rPtr;
        rSize = _rSize;
    }
       void SetCircle(MyCircle* _cPtr , int _cSize)
    {
        cPtr = _cPtr;
        cSize = _cSize;
    }
       void SetTri(MyTri* _tPtr , int _tSize)
    {
        tPtr = _tPtr;
        tSize = _tSize;
    }

    void Execute()
    {
        for(int i = 0; i < lSize; i++)   lPtr[i].Draw();
        for(int i = 0; i < rSize; i++)   rPtr[i].Draw();
        for(int i = 0; i < cSize; i++)   cPtr[i].Draw();
        for(int i = 0; i < tSize; i++)   tPtr[i].Draw();
    }


};



int main()
{

    initgraph();

    MyLine larr[2]={MyLine(230,338,191,142,4),MyLine(82,338,120,142,4)};
    MyCircle carr[2]={MyCircle(156,142,70,4),MyCircle(156,338,147,4)};
    Rect rarr[1]={Rect(20,445,308,540,4)};
    MyTri tarr[1]={MyTri(265,473,278,501,252,501,4)};
    Picture p1;
    p1.SetLines(larr,2);
    p1.SetCircle(carr,2);
    p1.SetRect(rarr,1);
    p1.SetTri(tarr,1);

    p1.Execute();
    p1.SetLines(NULL,0);


    return 0 ;
}
