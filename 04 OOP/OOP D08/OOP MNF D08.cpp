///CPY ctor
///operator overloading
///OOR V1.0
//////////////////////////////////////////
//#include<iostream>
using namespace std;
class Complex
{
    private:
    int real;
    int img;
    public:
    void SetReal(int _real)
    {
        this->real=_real;
    }
    int GetReal() const 
    {
        return this->real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg() const
    {
        return (*this).img;
    }
    void Print()
    {
        cout<<real<<"+"<<this->img<<"i"<<endl;
    }
    Complex Add(Complex right)
    {
        Complex result;
        result.real=this->real+right.real;
        result.img=img+right.img;
        return result;
    }
    Complex()
    {
        cout<<"complec default ctor";
        this->real=0;
        (*this).img=0;
    }
    Complex(int _real,int _img)
    {
        cout<<"complec 2p ctor";
        this->real=_real;
        img=_img;
    }
    Complex(int _num)
    {
        cout<<"complec 1p ctor";
        this->real=img=_num;
    }
    //destructor learning purpose //useless
    ~Complex()
    {
        cout<<"complex destructor\n";
    }
    //
};
Complex AddComplex(Complex left,Complex right)
{
    Complex result;
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}


int main()
{
    Complex c1(3,4),c2(5,6),c3;
    c3=AddComplex(c1,c2);
    c3.Print();
    return 0;
}
////////////////////////////////////////
//#include<iostream>
using namespace std;
class Stack
{
    private:
    int* arr;
    int size;
    int tos;
    public:
    Stack()
    {
        tos=0;
        size=5;
        arr=new int[size];
        cout<<"Stack def ctor";
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new int[size];
        cout<<"Stack 1p ctor";
    }
    //cpy ctor
    //param call cpy ctor
    //this -> pointer to param
    //oldObj-> reference on s1
    Stack(const Stack& oldObj)
    {
        cout<<"cpy ctor";
        tos=oldObj.tos;
        size=oldObj.size;
        arr=new int[size];
        for (int i = 0; i < tos; i++)
        {
            this->arr[i]=oldObj.arr[i];
        }
    }
    //

    //dest  important?YESSSSSSSS Very
    ~Stack()
    {
        delete[] arr;
        cout<<"Stack dest";
    }
    //Stack functions
    void Push(int value)
    {
        if(!IsFull())
        {
            arr[tos]=value;
            tos++;
        }
        else
        {
            cout<<"FULL!!!\n";
        }
    }
    int Pop()
    {
        int result=-123;
        if(!this->IsEmpty())
        {
            tos--;
            result=arr[tos];
        }
        else
        {
            cout<<"EMPTY!!!\n";
        }
        return result;
    }
    //
    int IsFull(){return tos==size;}
    int IsEmpty(){return tos==0;}
    //
    //
    friend void ViewStack(Stack param);
    //

    //
    Stack Reverse()
    {
        Stack result;
        //go upward into result
        return result; //return VALUESSSSS
    }
    //

    //s2=s1=s3  [MANDATORY]
    Stack& operator=(const Stack& right)
    {
        //REMEMBER to avoid memory leak
        delete[] this->arr;
        //
        tos=right.tos;
        size=right.size;
        arr=new int[size];
        for (int i = 0; i < tos; i++)
        {
            arr[i]=right.arr[i];
        }
        //REMEMBER
        return *this;
    }
    //

};
void ViewStack(Stack param)
{
    for (int  i = 0; i < param.tos; i++)
    {
        cout<<param.arr[i]<<endl;
    }
}
//
int main()
{
    Stack s1(10);
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);

    //Stack s2;
    //s2=s1.Reverse();


    ViewStack(s1);
    ViewStack(s1);

    Stack s2(s1); //call cpy ctor
    return 0;
}
/////////////////////////////////////////////////////

//>copy ctor not exists -> o.s make bitwise copy

//Copy [Constructor]:method called
// when we create object
//constructor method called automatically -we cannot call it-
//in three cases:
//1- pass object by value
//2- return object by value
//3- create object from object اصنع كائن بدلاله كائن اخر

///When cpy ctor IS MUST???
///when u make DT contains pointer will be
///dynamically allocated

///how to write cpy ctor explicitly?

class Trial
{
    private:
    int x;
    public:
    //this-> new object that will be created
    //oldobj => reference on old object being copied from 
    Trial(/*Trial *this,*/Trial& oldObj)
    {

    }
};
/////////////////////////////////////////////////////
///operators overloading
//operators in c++ can be overloaded
//you can overload operator as member or stand alone fn

// int main()
// {
//     int x=3,y=4,z;
//     double a=3,b=4,c;
//     z=x+y;
//     c=a+b;
//     //compiler call
//     //int operator+(int left,int right){}
//     //double operator+(double left,double right){}
//     //Complex operator+(Complex left,Complex right){}

//     Complex c1(3,4),c2(5,6),c3;
//     c3=AddComplex(c1,c2);
//     c3=c1.Add(c2);
//     c3=c1+c2;
//     //Complex operator+(Complex left,Complex right){}
//     return 0;
// }

/////////////////////////////////////////////////////
class Complex
{
    private:
    int real;
    int img;
    public:
    void SetReal(int _real)
    {
        this->real=_real;
    }
    int GetReal() const 
    {
        return this->real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg() const
    {
        return (*this).img;
    }
    void Print()
    {
        cout<<real<<"+"<<this->img<<"i"<<endl;
    }
    Complex Add(Complex right)
    {
        Complex result;
        result.real=this->real+right.real;
        result.img=img+right.img;
        return result;
    }
    Complex()
    {
        cout<<"complec default ctor";
        this->real=0;
        (*this).img=0;
    }
    Complex(int _real,int _img)
    {
        cout<<"complec 2p ctor";
        this->real=_real;
        img=_img;
    }
    Complex(int _num)
    {
        cout<<"complec 1p ctor";
        this->real=img=_num;
    }
    //destructor learning purpose //useless
    ~Complex()
    {
        cout<<"complex destructor\n";
    }
    //cpy ctor useless [for learninig purpose]
    Complex(const Complex& old)
    {
        real=old.real;
        img=old.img;
    }
    //
    //operators
    //c1+c2
    Complex operator+(const Complex& right)
    {
        Complex result;
        result.real=real+right.real;
        result.img=this->img+right.img;
        return result;
    }

    //c1+10
    Complex operator+(int _num)
    {
        Complex result(real+_num,img);
        return result;
    }
    
    //c3=++c1
    Complex& operator++()
    {
        real++;
        img++;
        return *this; //*this===c1 //return object by value
    }
    //c3=c1++
    Complex operator++(int)
    {
        Complex originalState(real,img);
        this->real++;
        img++;
        return originalState; //3+4i 
    }
    //c1+=c2+=c3;
    Complex& operator+=(const Complex& right)
    {
        real+=right.real;
        img+=right.img;
        return *this;
    }
    //c1>c2
    int operator>(Complex right)
    {
        return real>right.real && img>right.img;
    }
    //
    //c1=c2=c3 [useless]
    Complex& operator=(const Complex& right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    //

};
Complex AddComplex(Complex& left,Complex& right)
{
    Complex result;
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}
//
Complex operator+(int _num,Complex& right)
{
    return right+_num;
    //OR
    Complex result;
    result.SetReal(right.GetReal()+_num);
    result.SetImg(right.GetImg());
    return result;
}
//

int main()
{
    Complex c1(3,4),c2(5,6),c3;

    // c3=c1+c2; 
    // //stand alone Compiler operator+(c1,c2)
    // //member Compiler c1.operator+(c2)
    // c3.Print();

    // c3=c1+10; //
    // c3.Print(); //13+4i

    //c3=10+c1; //caller ->10 [int]  stand alone

    //c3=++c1;  //c1.operator++()
    
    //c3=c1++;
    //c1.Print(); //4+5i
    //c3.Print(); //3+4i
    
    //c1+=c2;  //c1.operator+=(c2)
    
    // if(c1>c2)
    // {

    // }
    
    ////casting [tomorrow]
    ///int real=c1;
    
    c1=c2; //memberwise copy  //useless
    
    c3=AddComplex(c1,c2);
    return 0;
}

/////////////////////////////////////////////////////



int main()
{
    Stack s1(10);
    Stack s2;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s1.Push(50);
    s1.Push(60);

    s2=s1;

    //Complex fields, setter&getters ,ctor,ctor() ,destX,ccpyX,=X
    //Stack int*arr fields, setter&getters ,ctor,ctor() ,destM,ccpyM,=M
}
///////////////////////////////////////////////////////
///////////////////////////////////
//Object Oriented Relations
//Relation between classes

//1-Composition [Tightly Coupled]
    //DT Contains All Of Another DT

//2-Aggregation [loosely coupled]
    //class may contains another class later

//3-Association [Very Loosely coupled]
    //peer to peer each class may not depend on
        //another one 

//4- inheritance
////////////////////////////////////////////////////
//A-Association [Very Loosely coupled]
///1- Peer-To-Peer
        //teacher    subject
///2- Temporarily relation
///3- represent in code
        //Pointer of class inside another class
        //C# Reference
        ///class Teacher
        //{
            //id,name,age
            //Subject * sub; //null
        //};
//4- 1-0 1-1  1-M M-M 
//5- No Dependency


//B-Aggregation [loosely coupled]
///1- Whole vs. part
///      Student       Department
///2- temp. Relation
///3- Represent in code
    /// Pointer of class inside another class
        //C# Reference
        ///class Student
        //{
            //id,name,age
            //Department * Dept;
            //ctor(){new dept[1]}
        //};
///4-1-0 1-1   1-M M-M
///5- No Dependency


//C- Composition [Tightly Coupled]
///1- complete ownership [has a]
///2- Permenant relationship
        //Room    wall
///3- object of class inside another class
        ///class Room
        //{
            //Wall  w1;
            //Wall  w2;
            //Wall  w3;
            //Wall  w4;
            
        //};
        ///main  room r[10] ||||||||
        //room r1,r2,r3
///4- 1-1 1-m 
///5- Complete Dependency






//Dependency Inversion:
///Principle of how to create 
///loosely coupled application


///SOLID

//principle
//Concept
//Framework

///////////////////////////////////////////////////////
///Composition
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
    //l2 call pnt def ctor to construct its start
    //l2 call pnt def ctor to construct its end
    Point()
    {
        x=y=0;
        cout<<"Point def ctor\n";
    }
    //r2 call this so that ctor chaiing
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"Point 2p ctor\n";
    }
    ~Point() //useless //debugging
    {
        cout<<"Point dest\n";
    }
    Point(const Point& old) //useless 
    {
        x=old.x;
        y=old.y;
        cout<<"point cctor\n";
    }
};
////////
class Line
{
    private:
    Point start; 
    Point end;
    public:
    void SetStart(Point _start){start=_start;}
    Point GetStart(){return start;}
    void SetEnd(Point _end){end=_end;}
    Point GetEnd(){return end;}
    Line()
    {
        //-> l1 start x|0| y|0|   end x|0| y|0|
        //start.x=0;start.y=0;end.x=0;end.y=0; //compile error
        //useless code
        //start.SetX(0);
        //start.SetY(0);
        //end.SetX(0);
        //end.SetY(0);
        cout<<"Line def ctor\n";
    }
    Line(int x1,int y1,int x2,int y2)
    {
        //-> l2 start x|0| y|0|   end x|0| y|0|
        start.SetX(x1);
        start.SetY(y1);
        end.SetX(x2);
        end.SetY(y2);
        //-> l2 start x|1| y|2|   end x|3| y|4|
        //->6times
        cout<<"Line 4p ctor\n";
    }
    ~Line(){cout<<"Line dest\n";}
    Line(const Line& old)
    {
        start=old.start;
        end=old.end;
        cout<<"line cctor \n";
    }
    void PrintLine()
    {
        cout<<"Start"<<start.GetX()<<","<<start.GetY();
        cout<<"end"<<end.GetX()<<","<<end.GetY();
    }
};


//ctor chaining 1-increase performence 2-reduce written code
class Rect
{
    private:
    Point ul;
    Point lr;
    public:
    void SetUL(Point _ul){ul=_ul;}
    Point GetUL(){return ul;}
    void SetLR(Point _lr){lr=_lr;}
    Point GetLR(){return lr;}
    Rect()
    {
        //r1 ul x|0| y|0|   lr x|0| y|0|
        //useless
        //ul.SetX(0);ul.SetY(0);lr.SetX(0);lr.SetY(0);
        cout<<"Rect drf ctor\n";
    }
    
    Rect(int x1,int y1,int x2,int y2)
    :ul(x1,y1),lr(x2,y2)
    {
        //r1 ul x|1| y|2|   lr x|3| y|4|

        // //after ctor chining -> useless
        // ul.SetX(x1);
        // ul.SetY(y1);
        // lr.SetX(x2);
        // lr.SetY(y2);
        cout<<"Rect 4p ctor\n";
    }
    ~Rect(){cout<<"Rect dest\n";}
    Rect(const Rect& old)
    {
        ul=old.ul;
        lr=old.lr;
        cout<<"rect cctor\n";
    }
    void PrintRect()
    {
        cout<<"ul"<<ul.GetX()<<","<<ul.GetY();
        cout<<"lr"<<lr.GetX()<<","<<lr.GetY();
    }
};

int main()
{
    Rect r2(1,2,3,4);
    //o/p after ctor chainig
    //point 2p ctor ul
    //point 2p ctor lr
    //rect 4p ctor

    Rect r1;
    //point ctor ul
    //point ctor lr
    //rect ctor
    //rect dest
    //point des lr
    //point des ul

    Line l2(1,2,3,4);
    l2.PrintLine();
    //o/p
    //pnt def ctor start
    //pnt def ctor end
    //line 4p ctor

    Line l1;
    //o/p
    //point def cotr start
    //point def cotr end
    //line def ctor
    //line dest
    //point des end
    //point des start
    return 0;
}

//////////////////////////////////////////////
//lab assignments
//1-Complex
////cpy ctor [useless]
////= operator [useless]
////c1+c2
////c1+10
////c1+=c2
////c1++
////++c1
////c1>c2

//10+c1 [standalone]

/////////////////////////////////
//2- stack
///cpy ctor [MUST]
///=operator [MUST]
///Stack Reverse(){}

//////////////////////////////////
///3-Composition with [debugging]
//class point ALL
//class Line
//class Rect




//hackerrank



