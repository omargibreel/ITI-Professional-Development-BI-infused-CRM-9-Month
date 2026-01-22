#include <iostream>

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
    //l1 call this ctor to construct start
    //l1 call this ctor to construct end
    Point()
    {
        x=y=0;
        cout<<"point def ctor";
    }
    Point(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"point 2p ctor";
    }
    //useless
    ~Point(){cout<<"point dest";}
    //useless
    Point(const Point& old)
    {
        x=old.x;
        y=old.y;
        cout<<"point cctor";
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
        myColor=_color;
    }
    ~Shape(){}
    virtual void Draw()=0;
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

    MyLine(int x1,int y1,int x2,int y2,int _color)
    :start(x1,y1),end(x2,y2),Shape(_color)
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
        //built-in fn
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
    //setters & getters
    Rect()
    {
    }
    Rect(int x1,int y1,int x2,int y2,int _color)
    :ul(x1,y1),lr(x2,y2),Shape(_color)
    {
    }
    ~Rect(){}
    Rect(Rect& old){}
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
    //
    //
    //
    //
    //
    void Draw()
    {
        //setcolor();
        //circle(,,);
    }
};

class MyTri:public Shape
{
    Point p1;
    Point p2;
    Point p3;
    public:
    //
    //
    //
    //
    //
    void Draw()
    {
        setcolor(myColor);
        line();
        line();
        line();
    }
};

class Picture
{
    private:
    Shape** sPtr;
    int sSize;
    public:
    Picture()
    {
        sPtr=NULL;
        sSize=0;
    }
    //set relationship
    void SetShapes(Shape** _sPtr,int _sSize)
    {
        sPtr=_sPtr;
        sSize=_sSize;
    }
    //Process
    void Execute()
    {
       for (int i = 0; i < sSize; i++)
       {
            sPtr[i]->Draw();
       }
    }

};

int main()
{
    initgraph();
    MyLine larr[2]={MyLine(1,1,1,1,1),MyLine()};
    Rect rarr[3]={};

    Shape* sPtrArr[5]={larr,&larr[1],rarr,&rarr[1],&rarr[2]};

    Picture p1;

    p1.SetShapes(sPtrArr,5);

    p1.Execute();

    p1.SetShapes(NULL,0);

    return 0;
}
