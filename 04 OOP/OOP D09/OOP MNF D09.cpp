//1-Inheritance
//2-Aggregation[association]
////////////////////////////////////////////////////

//Inheritance:
///>Extending methods and fields from
///class to another one

///>new datatype =>receiving methods and fields
///Was created actually in another datatype

//////////////////////////////////////////////////////////
///TypeA
////x
////y
////funOne()
////funTwo()

///TypeB
////y
////z
////funTwo()
////funThree()

//Solution//////////////////////////////
///Base
////y
////FunTwo()

///TypeA Inherits Base
////x
////funOne()


///TypeB Inherits Base
////z
////funThree()   
///////////////////////////////////////////
class Parent
{
    private:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}
    int GetX() const{return x;}
    int GetY()const {return y;}
    //c1 call this ctor to initialize inherited members
    Parent()
    {
        x=y=0;
        cout<<"Parent def ctor\n";
    }
    //c2 call this ctor to initialize inherited members
    Parent(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"Parent 2p ctor\n";
    }
    ~Parent(){cout<<"Parent dest";}
    Parent(const Parent& old)
    {
        x=old.x;y=old.y;
        cout<<"Parent cctor";
    }
    int SumXY()
    {
        return x+y;
    }
};
//public: types of inheritance
class Child:public Parent
{
    //x,y,setx,sety,getx,gety,sumxy
    private:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        //c1  x|0| y|0| z|?|
        z=0;
        //c1  x|0| y|0| z|0|
        //x=0;y=0; //compile error inaccessible
        //useless
        // this->SetX(0);
        // SetY(0);
        cout<<"Child def ctor";
    }
    Child(int _xM,int _yE,int _z)
    :Parent(_xM,_yE)
    {
        //c2  x|1| y|2| z|?|
        z=_z;
        //c2  x|1| y|2| z|3|
        //useless after ctor chaining
        //SetX(_x);
        //this->SetY(_y);
        //c2  x|1| y|2| z|3|
        cout<<"Child 3p ctor";
    }
    ~Child(){cout<<"Child dest";}
    Child(const Child& old)//:Parent(old.GetX(),old.GetY())
    {
        z=old.z;
        SetX(old.GetX());
        this->SetY(old.GetY());
        cout<<"child cctor";
    }
    int SumXYZ()
    {
        return z+SumXY();
        return z+GetX()+this->GetY();
        //return x+y+z;//error
    }

};

int main()
{
    //Always access public MEMBERS ONLY


    Child c2(1,2,3);
    cout<<c2.SumXYZ(); //6
    cout<<c2.SumXY(); //3
    //o/p
    //parent ctor
    //child ctor
    //child dest
    //parent dest

    Child c1;
    //o/p
    //parent def ctor
    //child def ctor



    Parent p1(3,4); //8B
    //Child c1; //12B  c1 x|| y|| z||
}

//Rules//////////////////////////////////////////////////////////
//>1-Child Inherits EVERYTHING from parent  except?
//   public ,private  YESSSSS

//>2-public:member can be accessed inside & outside class or struct
//>3-private:member can be accessed inside class or struct ONLY

//>4- [search]  ctor ?   , static ? 
///////////////////////////////////////////////////////////////////

//Is there any way to access private members
//in child DT? YES if it became protected

//protected: [smart private]  [inheritance]
///member can be accessed
///inside class scope
///and accessed inside chain of inheritance
///ONLY

///SumXY()   , SumXYZ    ,  SumXYZA   XXXXX

///////////////////////////////////////////////
class Parent
{
    protected:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}
    int GetX() const{return x;}
    int GetY()const {return y;}
    //c1 call this ctor to initialize inherited members
    Parent()
    {
        x=y=0;
        cout<<"Parent def ctor\n";
    }
    //c2 call this ctor to initialize inherited members
    Parent(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"Parent 2p ctor\n";
    }
    ~Parent(){cout<<"Parent dest";}
    Parent(const Parent& old)
    {
        x=old.x;y=old.y;
        cout<<"Parent cctor";
    }
    int Sum()
    {
        return x+y;
    }
};
//public: types of inheritance
class Child:public Parent
{
    //x,y,setx,sety,getx,gety,sumxy
    protected:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Child()
    {
        z=0;
        //useless
        x=0;
        y=0;
        cout<<"Child def ctor";
    }
    Child(int _xM,int _yE,int _z)
    :Parent(_xM,_yE)
    {
        z=_z;
        //if there is no ctor chaining
        x=_xM;
        y=_yE;
        cout<<"Child 3p ctor";
    }
    ~Child(){cout<<"Child dest";}
    Child(const Child& old)//:Parent(old.GetX(),old.GetY())
    {
        z=old.z;
        x=old.x;
        y=old.y;
        cout<<"child cctor";
    }
    int Sum()
    {
        return x+y+z; //MCU
        return z+Parent::Sum();
        return z+Sum(); //Stack overflow
    }
};

int main()
{
    Parent p1(1,2); //x   y
    cout<< p1.Sum(); //3

    Child c1(1,2,3);
    cout<<c1.Sum(); //6
    cout<<c1.Parent::Sum(); //3 //Nonsense

    //p1.x=10; //Compile error inaccessible
    return 0;
}

////////////////////////////////////////
//overriding: [inheritance]
//method has same name,same parameter
//but body/implementation
//is different in child DT;

////////////////////////////////////////////

class Geoshape
{
    protected:
    double dim1;
    double dim2;
    public:
    void SetDim1(double _dim1){dim1=_dim1;}
    double GetDim1(){return dim1;}
    void SetDim2(double _dim2){dim2=_dim2;}
    double GetDim2(){return dim2;}
    Geoshape()
    {
        dim1=dim2=0;
        cout<<"Geo def ctor";
    }
    Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;dim2=_dim2;
        cout<<"Geo 2p ctor";
    }
    Geoshape(double _dim)
    {
        dim1=dim2=_dim;
        cout<<"Geo 1p ctor";
    }
    ~Geoshape(){cout<<"geo dest";}
};

class Rect:public Geoshape
{
    //fields??? NOOO
    public:
    Rect()//:Geoshape(0,0)
    {
        //useless
        //dim1=dim2=0;
        cout<<"Rect def ctor";
    }
    Rect(double _d1,double _d2)//:Geoshape(_d1,_d2)
    {  
        dim1=_d1;
        dim2=_d2;
        cout<<"rect 2p ctor";
    }
    ~Rect()
    {cout<<"Rect dest";}
    double Area()
    {
        return dim1*dim2;
    }
};

class Square:protected Geoshape
{
    //dim1 ,dim2 ,setd1, setd2 getd1 getdim2
    public:
    Square()
    {
        cout<<"square def ctor";
    }
    Square(double _dim):Geoshape(_dim) //:Geoshape(_dim,_dim)
    {
        //#1  no ctor chaining
        dim1=dim2=_dim;
    }
    ~Square(){cout<<"Sq dest";}
    double Area()
    {
        return dim1*dim2;
    }
    //
    void SetDim1(double _dim1){dim1=dim2=_dim1;}
    void SetDim2(double _dim2){dim2=dim1=_dim2;}
    //
};

class SquareV2:public Rect
{
    public:
    SquareV2(){}
    SquareV2(double _d1)
    {
        dim1=dim2=_d1;
    }
    ~SquareV2(){}
};

class Circle:public Geoshape
{
    public:
    Circle(){}
    Circle(double _radius):Geoshape(_radius)
    {}
    ~Circle(){}
    double Area()
    {
        return 3.14 * dim1 * dim2;
    }
};

class Tri:public Geoshape
{
    public:
    Tri(){}
    Tri(double _base,double _height)
    :Geoshape(_height,_base)
    {}
    ~Tri(){}
    double Area()
    {
        return  0.5 * dim1 * dim2;
    }
};

int main()
{
    SquareV2 s2;
    //o/p
    //geo ctor
    //rect ctor
    //sqv2 ctor
    //sqv2 dest
    //rect dest
    //geo dest


    Rect r1;
    //o/p
    //geo def ctor
    //rect def ctor

    Rect r2(3,4);
    //o/p
    //geo def ctor
    //rect 2p ctor
}

//issue with square,circle
int main()
{
    Square s1(10);  //s1 dim1|10| dim2|10|
    //s1.Geoshape::SetDim1(3);  //s1 dim1|3| dim2|3|
    s1.SetDim2(4);  //s1 dim1|3| dim2|4|
    cout<<s1.Area(); //12

    return 0;
}

///////////////////////////////////////
//TYPES OF INHERITANCE
//A. Public [MOST USED] [All MUST:Public]

class Parent
{
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        //x,y,z
        x=y=z=0;
    }
    int sum()
    {
        return x+y+z;
    }

};
class Child :public Parent
{
    //x,y,z,sss,ggg,sum
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        //y=z=a=b=c=0;  //x
    }
    int sum()
    {
        return getX()+y+z+a+b+c;
        return Parent::sum()+a+b+c;
    }
};

class SubChild:public Child
{
    ///  
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //y=z=b=c=j=k=l=0; //x,a
    }
    int sum()
    {
        return j+k+l+Child::sum();
    }
};

main()
{
    Parent p;
    //p. PUBLIC ONLY  z sss ggg sum 

    Child c;
    //c. PUBLIC ONLY  z,c,  Parent::sssggg ,chils::sssggg ,sum 

    SubChild sc; //PUBLIC ONLY z,c,l 
}

/////////////////////////////////////////////////////////
//B. Protected
class Parent
{
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        //x,y,z
        x=y=z=0;
    }
    int sum()
    {
        return x+y+z;
    }

};
class Child :protected Parent
{
    //x,y,z,sss,ggg,sum
    //x private still private cannot access
    //y protected still protected can be accessed
    //z ,sss,ggg,sum public promotes to protected can be accessed
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        //y=z=a=b=c=0; //x
    }
    int sum()
    {
        //
    }
};

class SubChild:protected Child
{
    //x,a private still priv cannot access
    //y protected still prot can be accessed
    //z protected still prot can be accessed
    //b protected still prot can be accessed
    //c public promotes to prot can be accessed
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //y=z=b=c=j=k=l=0;  //x,a
    }
    int sum()
    {
        
    }
};

main()
{
    Child c;
    //c. setZ

    SubChild sc;  //l
    //sc.x,y,z,a,b,c ???? XXXX
    //sc.setC() 
}


/////////////////////////////////////////////
//C. Private  RARELY USED
class Parent
{
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        //x,y,z
        x=y=z=0;
    }
    int sum()
    {
        return x+y+z;
    }

};
class Child :private Parent
{
    ////x,y,z,sss,ggg,sum
    //x priv [not accessed here]
    //y protected promotes to private [accessed here]
    //z public promotes to private [accessed here]  
    //setters&getters  sum became private [accessed here]
    
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        //y,z,a,b,c ,parent::setters
    }
    int sum()
    {
        return y+z+a+b+c+getX();
    }
};

//(P)x,y,z [private]  ,a b c
class SubChild: private Child
{
    //x private [not accessed] 
    //y private [not accessed]
    //z private [not accessed]
    //a private [not accessed]
    //b private [accessed]
    //c private [accessed]
    //child setter and getter private [accessed]
    //parent setter and getter private [not accessed]
    //sum() parent private [not accessed]
    //sum() child private [accessed]
    int j;
    protected:
    int k;
    public:
    int l; 
    SubChild()
    {
        //xN yN zN aN bT cT
    }
    int sum()
    {
        
    }
};

int main()
{
    Child c1;  //c //setter&getters of child
    SubChild sc1; //l
}

//////////////////////////////////////////////

//Most Commonly used class:public class ONLY
//C# java ONLY class: class   public

//RARELY USED
//child:protected Parent
//class Utility{public color(){} };
//class Button:protected utility {};
//main()
//button b1;

//child:private parent
//class Timer{start() ,Stop()};
//class Exam:private Timer{};

//////////////////////////////////////////////
class Point
{
    private:
    int x;
    int y;
    public:
    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}
    int GetX(){return x;}
    int GetY(){return y;}
    Point()
    {
        x=y=0;
        cout<<"Point def ctor";
    }
    Point(int _x,int _y)
    {
        x=_x;y=_y;
        cout<<"Point 2p ctor";
    }
    ~Point(){cout<<"Point dest";}
    Point(const Point& old){x=old.x;y=old.y;cout<<"cpy ctor";}
};

void TryMe(Point& p1){}
int main()
{
    Point p1(3,4); //Stack

    Point* pPtr=new Point(3,4);  //heap
    //o/p
    //point 2p ctor
    delete pPtr; //remove one object
    //point dest

    //anonymous object
    Point(3,4);
    //compiler will create it and remove it at same time
    
    Point parr[3]; 
    //point def ctor
    //point def ctor
    //point def ctor

    Point parr2[3]={Point(3,4),Point(5,6),Point(7,8)};
    //point 2p ctor
    //point 2p ctor
    //point 2p ctor


    Point *pPtr2=new Point[3];
    //point def ctor
    //point def ctor
    //point def ctor
    pPtr2[0].SetX(3);
    pPtr2[0].SetY(4);
    delete[] pPtr2;
    //point dest
    //point dest
    //point dest
    
    return 0;
}

//////////////////////////////////////////////
//Aggregation/Association
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
        cout<<"Point def ctor\n";
    }
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
        cout<<"Point 2p ctor\n";
    }
    ~Point() 
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
        cout<<"Line def ctor\n";
    }
    Line(int x1,int y1,int x2,int y2)
    {
        start.SetX(x1);
        start.SetY(y1);
        end.SetX(x2);
        end.SetY(y2);
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
        cout<<"Rect drf ctor\n";
    }
    
    Rect(int x1,int y1,int x2,int y2)
    :ul(x1,y1),lr(x2,y2)
    {
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


class Picture
{
    Line *lPtr;
    int lSize;
    //
    //
    public:
    Picture()
    {
        lPtr=NULL;
        lSize=0;
        //
        //
    }
    //set relationship
    void SetLines(Line *_lPtr,int _lSize)
    {
        lPtr=_lPtr;
        lSize=_lSize;
    }

    void Execute()
    {
        for (int i = 0; i < lSize; i++)
        {
            lPtr[i].PrintLine();
        } 
        //
    }
};

int main()
{
    Line larr[3]={Line(1,2,3,4),Line(),Line()};

    Picture p1;

    //set relationship betw. picture & lines
    p1.SetLines(larr,3);

    p1.Execute();

    //remove relationship
    p1.SetLines(NULL,0);
    return 0;
}

///////////////////////////////////////////////
//lab assignments
//1- types of inheritance [discuss]
//2- class geoshape and all of its childs
//3-association class picture






