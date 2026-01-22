///////////////////////////////////////////////////////////////
//[Inheritance]Every Code below 
////////////////will inherit from public
///////////////////////////////////////////////////////////////
//#include<iostream>
using namespace std;
class Base
{
    protected:
    int x;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    Base(){x=0;}
    Base(int _x){x=_x;}
    ~Base(){}
    void Show()
    {
        cout<<"I'm BASE ...";
    }
};

class Derived:public Base
{
    protected:
    int y;
    public:
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Derived(){x=y=0;}
    Derived(int _x,int _y):Base(_x)
    {
        y=_y;
    }
    ~Derived(){}
    void Show()
    {
        cout<<"I'm Derived ...";
    }
};
int main()
{
    Base b1(3);
    b1.Show(); //I'm Base

    Derived d1(1,2);
    d1.Show(); //i'm derived

    Base* bPtr=&b1;
    (*bPtr).Show(); //i'm base
    bPtr->Show(); //i'm base
    //compiler will retrieve Show()of pointer DT

    Derived* dPtr=&d1;
    dPtr->Show(); //I'm Derived
    //compiler will retrieve Show()of pointer DT

    Base *bPtr2=new Base(5);
    bPtr2->Show(); //i'm base
    //compiler will retrieve Show()of pointer DT
    
    Derived* dPtr2=new Derived(3,4);
    dPtr2->Show(); //I'm Derived
    //compiler will retrieve Show()of pointer DT
    
    return 0;
}

int main()
{
    Base *bPtr=new Derived(3,4);
    //الأب يحتوي جميع ابناؤه
    //u can make pointer of 
    //Parent references object of its childs 

    //inheritance[is a]
    //car is a veichle
    //bus is a veichle

    //derived is a Base
    
    bPtr->Show(); //I'm Base
    //compiler will retrieve Show()of pointer DT

    return 0;
}

class Derived2:public Derived
{
    protected:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived2(){z=0;}
    Derived2(int _x,int _y,int _z)
    :Derived(_x,_y)
    {
        z=_z;
    }
    ~Derived2(){}
    void Show()
    {
        cout<<"I'm Derived2";
    }
};

int main()
{
    Base* bPtr=new Derived2(1,2,3);
    bPtr->Show(); //i'm Base
    //compiler will retrieve Show()of pointer DT

    Derived *dPtr=new Derived2(5,6,7);
    dPtr->Show(); //i'm Derived
    return 0;
}

/////////////////////////////////////////
///Non Sense

//LOGIC
//Base* bPtr=new Derived2(1,2,3);
//dPtr->Show(); //i'm Derived2

//////////////////////////////////////////
class Human
{
    protected:
    string name;
    public:
    void SayName()
    {
        cout<<"No Name";
    }
};
class Male:public Human
{
    public:
    Male(string _name)
    {
        name=_name;
    }
    void SayName()
    {
        cout<<"my name is "<<name;
    }
};
class Female:public Human
{
    public:
    Female(string _name)
    {
        name=_name;
    }
    void SayName()
    {
        cout<<"my name is "<<name;
    }
};
int main()
{
    Male *mPtr=new Male("Ahmed");
    Female *fPtr=new Female("Sara");
    mPtr->SayName(); //my name is Ahmed
    fPtr->SayName(); //my name is Sara

    Human * hPtr=new Female("Samaa");
    hPtr->SayName(); //No Name

    Human *hPtr2=new Male("Ali");
    hPtr2->SayName(); //No Name

    return 0;
}
////////////////////////////////////////////
//Early/Static Binding: [Compile Time]

////when pointer from parent points
///object from its child
////when call overriden method
////Complier will EARLY [compile Time] 
///Retrieve fn copy of Pointer DT
/////not copy of Object DT

//LOGIC
//Base* bPtr=new Derived2(1,2,3);
//dPtr->Show(); //i'm Derived2

///////////////////////////////////////////

///Is there a solution make pointer of Base
//Will Retrieve copy of overriden method 
//that belong to object not pointer???
////YES

/////Late/Dynamic Binding [Run time]
////when pointer from parent points
// object from child
////when call overriden method
////Complier will Later [at run time] 
//Retrieve  fn copy of Object DT
/////not copy of Pointer DT

//how?
///1-fn to be overridden in fst level [parent]
//////must be public and virtual
///2-child Class Must inherits from public
///3-overridden fn at child DT must be public also
///4-make pointer from parent references object from its childs

class Base
{
    protected:
    int x;
    public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    Base(){x=0;}
    Base(int _x){x=_x;}
    ~Base(){}
    virtual void Show()
    {
        cout<<"I'm BASE ...";
    }
};

class Derived:public Base
{
    protected:
    int y;
    public:
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Derived(){x=y=0;}
    Derived(int _x,int _y):Base(_x)
    {
        y=_y;
    }
    ~Derived(){}
    void Show() override   //safety factor
    {
        cout<<"I'm Derived ...";
    }
};

class Derived2:public Derived
{
    protected:
    int z;
    public:
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived2(){z=0;}
    Derived2(int _x,int _y,int _z)
    :Derived(_x,_y)
    {
        z=_z;
    }
    ~Derived2(){}
    void Show() override
    {
        cout<<"I'm Derived2";
    }
};

int main()
{
    Base * bPtr=new Derived(1,2);
    bPtr->Show(); //i'm derived

    Base * bPtr2=new Derived2(1,2,3);
    bPtr2->Show(); //i'm derived2

    Derived * dPtr=new Derived2(1,2,3);
    dPtr->Show(); //i'm derived2

    //Derived2 *dptr2=new Derived2(3,4,5);

    //in Java
    //reference from Parent reference 
    //object from child
    ///call overridden fn => object copy
    //[virtual] implicitly
    return 0;
}


///////////////////////////////////////////////
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

    //fn to be overridden to calculate area for each geoshape
    // virtual double Area()
    // {
    //     return -1;
    // }

    virtual double Area()=0;
};

class Rect:public Geoshape
{
    public:
    Rect()
    { 
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
    double Area() override
    {
        return dim1*dim2;
    }
};

class Square:public Geoshape
{
    public:
    Square()
    {
        cout<<"square def ctor";
    }
    Square(double _dim):Geoshape(_dim) 
    {
        dim1=dim2=_dim;
    }
    ~Square(){cout<<"Sq dest";}
    double Area()
    {
        return dim1*dim2;
    }
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
//
//fail in open close principle
double SumOfAreasV1(Rect *_rPtr,int _rSize,Square *_sPtr,int _sSize,Circle *_cPtr,int _cSize)
{
    double sum=0;
    for (int i = 0; i < _rSize; i++)
    {
        sum+=_rPtr[i].Area();
    }
    for (int i = 0; i < _sSize; i++)
    {
        sum+=_sPtr[i].Area();
    }
    for (int i = 0; i < _cSize; i++)
    {
        sum+=_cPtr[i].Area();
    }
    return sum;
}
//
//double SumOfAreasV2(Geoshape *_gPtrArr[],int _gSize)
//succeed in open close principle
double SumOfAreasV2(Geoshape **_gPtrArr,int _gSize)
{
    double sum=0;
    for (int i = 0; i < _gSize; i++)
    {
        sum+=_gPtrArr[i]->Area();
    }  
    return sum;
}
//
int main()
{
    Rect rarr[3]
    ={Rect(3,4),Rect(2,5),Rect(2,5)};
    Square sarr[2]
    ={Square(10),Square(10)};
    Circle carr[2]
    ={Circle(7),Circle(8)};
    Tri tarr[3]
    ={Tri(3,4),Tri(3,4),Tri(3,4)};

    //cout<<SumOfAreasV1(rarr,3,sarr,2,carr,2); //232

}

int main()
{
    //Geoshape *gPtr=new Rect(2,5);
    //cout<<gPtr->Area(); //10


    Rect rarr[3]
    ={Rect(3,4),Rect(2,5),Rect(2,5)};
    Square sarr[2]
    ={Square(10),Square(10)};
    Circle carr[2]
    ={Circle(7),Circle(8)};
    Tri t1(3,4);

    // Geoshape *gptr1=rarr;
    // Geoshape *gptr2=*rarr[1];
    // Geoshape *gptr3=*rarr[2];

    Geoshape * gPtrArr[]   //|->|->||||
    ={rarr,&rarr[1],&rarr[2],sarr,&sarr[1],carr,&carr[1],&t1};

    //cout<< (*gPtrArr[0]).Area(); //12
    //cout<<gPtrArr[1]->Area();   //10


    cout<<SumOfAreasV2(gPtrArr,8); //
}

///////////////////////////////////////////////
int main()
{
    Geoshape * gPtr;

    Rect r1;
    Geoshape gObj;
    return 0;
}

//abstract class
//=
//at lest one pure virtual fn
//
//virtual fn header only()=0;

//virtual fn may be overrided

//pure virtual fn MUST BE OVERRIDDEN
//if not
//will be inherited in child by its shape


///restrict create object from class
///if it is [ABSTRACT CLASS]

///abstract class:
//////class we cannot create object from it

///how to make class to be abstract?
///class became abstract 
///if it contains at least 
///one pure virtual fn

///pure virtual function?
////virtual function prototype[header] only without body =0; 

///pure virtual fn must be overridden 
///in child class?

//if not...
//child class became also abstract

////////////////////////////////////////////////////
class TypeA
{
    protected:
    int x;
    public:
    //
    //
    //
    virtual void FunOne()=0;
    virtual void FunTwo()=0;
};

class TypeB:public TypeA
{
    protected:
    int y;
    public:
    //
    void FunOne() override    //virtual fn
    {
        cout<<"Hello";
    }
    //implicitly virtual void FunTwo()=0;
};

class TypeC:public TypeB
{
    public:
    void FunTwo() override
    {
        cout<<"Bye";
    }
};

int main()
{
    TypeA objA;//compile Error //abstract
    TypeB objB;//compile Error //abstract
    TypeC objc;
}

//SEARCH   -> virtual dest
int main()
{
    Geoshape *gPtr=new Rect(3,4);
    delete gPtr;
    //o/p
    //geoshape dest called
}


//factory DP

/////////////////////////////////////////////
//template   => generics
template<class AF>
class Stack
{
    private:
    AF* arr;
    int size;
    int tos;
    public:
    //no need for setters &getters
    Stack()
    {
        tos=0;
        size=5;
        arr=new AF[size];
        cout<<"Stack def ctor";
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new AF[size];
        cout<<"Stack 1p ctor";
    }
    //dest  important?YESSSSSSSS Very
    ~Stack()
    {
        //useless [i need it for lab today]
        for (int i = 0; i < size; i++)
        {
            arr[i]=-1;
        }
        //
        delete[] arr;
        cout<<"Stack dest";
    }
    //Stack functions
    void Push(AF value)
    {
        //if(tos!=size)
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
    // tos=1  arr|10||||||
    AF Pop()
    {
        AF result;
        //if(tos!=0)
        if(!this->IsEmpty())
        {
            tos--;
            result=arr[tos];
        }
        else
        {
            cout<<"EMPTY!!!\n";
            //not Effective
            //return -123;
            //effective code
            //throw runtime error [exception] 
        }
        return result;
    }
    //
    int IsFull(){return tos==size;}
    int IsEmpty(){return tos==0;}
    void Print()
    {
        for (int i = 0; i < tos; i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};


int main()
{
    Stack<int> s1;
    s1.Push(2);

    Stack<char> s2;
    s2.Push('A');
}

////////////////////////////////////////////
//static is inherited but cannot be used

////////////////////////////////////////////

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
    //fn to initialize each object
    Complex()
    {
        this->real=3;
        img=4;
    }
    Complex(int _real,int _img)
    {
        this->real=_real;
        img=_img;
    }
    void Initialize(int _num)
    {
        this->real=img=_num;;
    }
    
    //(int)c1
    operator int()
    {
        return this->real;
    } 
};

int main()
{
    Complex c1(3,4);
    //implicit casting
    int real=c1;
    int real2=(int)c1;
    cout<< real; //3
}

///////////////////////////////////////////////
///parameter vs. arguments
//shallow => bitwise copy
///////////////////////////////////////////////
//Lab Assigments:
//[discuss] early vs late binding Base,Derived,Derived2 
//1-Geoshape abstract
////SumOFAreasV1()
////SumOFAreasV2()


hackerrank
leetcode






