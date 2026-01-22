//fn overloading
//dafault argument/s
//constructor
//destructor
//Stack
//static
//Friend function
///////////////////////////////////////////
///overloading
//Function overloading
//Function/S -in the same scope- have same //name but
//IGNORE RETURN TYPE 
//different input parameters number
//Or Different data type ot order

////Add(int,int)
////Add(int)
////Add(char)
////Add(char,double)
////Add(double,char)

//defult Argument :must be from right to left in params
//               if there is  def argument in middle,
//              must ALL of right of it be default also
///////////////////////////////////////////////////////
class Math
{
    public:
    int Add(int x,int y)
    {
        return x+y;
    }
    int Add(int x,int y,int z)
    {
        return x+y+z;
    }
};
int main()
{
    Math obj;
    cout<<obj.Add(1,2);
    cout<<obj.Add(1,2,3);

    return 0;
}

//////////////////////////////////////////////
///default Arguments
//v1
class Math
{
    public:
    //int Mul(int x=1,int y=1,int z=1){}
    int Add(int x=0,int y=0,int z=0)
    {
        return x+y+z;
    }
};
int main()
{
    Math obj;
    cout<<obj.Add(1,2,3); //6
    cout<<obj.Add(1,2);   //3
    cout<<obj.Add(1);     //1
    cout<<obj.Add();      //0
}

//////////////////////////////////////////
//v2
//#inc
//usi
//int Add(){}
//int Add(int x,int y){}
class Math
{
    public:
    int Add(int x,int y=0,int z=0)
    {
        return x+y+z;
    }
};
int main()
{
    Math obj;
    cout<< obj.Add(1,2,3); //6
    cout<< obj.Add(1,2);   //3
    cout<< obj.Add(1);     //1
    cout<< obj.Add();     //Compile Error

    return 0;
}

////////////////////////////////////////
//v3
class Math
{
    public:
    int Add(int x,int y,int z=0)
    {
        return x+y+z;
    }
};
int main()
{
    Math obj;
    cout<< obj.Add(1,2,3); //6
    cout<< obj.Add(1,2);   //3
    cout<< obj.Add(1);     //Compile Error
    cout<< obj.Add();      //Compile Error

    return 0;
}



//////////////////////////////////////
//v4 WRONG
//#include<>
//using ns
int Add(int x=0,int y,int z) //compile Error
{
    return x+y+z;
}
//Error => optional parameters must 
///////////appear after all required parameters
int main()
{
    //cout<< Add(,2,3);
    //cout<<Add(->)
    return 0;
}

///////////////////////////////////////
//v5 [careful] overloading vs. arguments

///Use overloading OR default arguments
class Math
{
    int Add(int x=0,int y=0,int z=0)
    {
        return x+y+z;
    }
    int Add(int x,int y)
    {
        return x+y;
    }
};
int main()
{
    Math obj;
    cout<< obj.Add(1,2,3); //6
    cout<< obj.Add(1); //1
    cout<< obj.Add(); //0
    //till this -> No errors
    cout<< obj.Add(1,2); 
    //here -> compile error -> ambiguty
    return 0;
}

///////////////////////////////////////
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
    //fn to initialize each object
    void Initialize()
    {
        this->real=3;
        img=4;
    }
    void Initialize(int _real,int _img)
    {
        this->real=_real;
        img=_img;
    }
    void Initialize(int _num)
    {
        this->real=img=_num;;
    }
    //
    //->there is hidden fn  called constructor
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

//object created real|3| img|4|
//v1
int main()
{
    Complex c1,c2,c3; //ALL real|#| img|$|
    c1.SetReal(3);
    c1.SetImg(4);
    c2.SetReal(3);
    c2.SetImg(4);
    c3.SetReal(3);
    c3.SetImg(4);
    Complex c4;
    c4.SetReal(3);
    c4.SetImg(4);
    return 0;
}

//v2
int main()
{
    Complex c1,c2,c3;
    c1.Initialize();
    c2.Initialize(5,6);
    c3.Initialize(7);
}

//v3
int main()
{
    Complex c1,c2,c3; //ALL real|3| img|4|
    return 0;
}

/////////////////////////////////////////////
//Constructor:
// special method inside class/struct 
// implicitly exist [hidden]
// will be called automatically -we cannot call it-
// Once we create object from that class/struct

//how to write ctor explicitly?
//1-has same name of class
//2-has no return type nor void
//3-can be overloaded
//4-must be public ->private[design patterns]
class Trial
{
    int x;int y;
    public:
    Trial(){}
    Trial(int _x){}
};
int main()
{
    Trial obj;
}

////////////////////////////////////////////////
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
    //ctors
    //default ctor 
    //generated by o.s
    // if there is no such ctor exists
    Complex(/* Complex *this*/)
    {
        cout<<"complec default ctor";
        this->real=3;
        (*this).img=4;
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
    //

    //destructor    dest  learning purpose
    //useless
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
    Complex c1,c2(5,6),c3(7);
    //o/p
    //complex def ctor
    //complex 2p ctor
    //complex 1p ctor
    //complex dest
    //complex dest
    //complex dest
    return 0;
}
////////////////////////////////////////////
//Destructor

//Destructor:
//Special function inside class/struct will be 
//called automatically
//cannot be called
//implicitly exist
//once O.S will object destructed from Stack
//once object reach end of its scope

///how to write destructor explicitly?
///1-has same name f class starts with ~ tilda 
///2- has no return type nor void
///3- cannot be overloaded -only parameterless copy-
///4- MUST be public


/// what is the real purpose of use dest explicitly?
///1-connect to databse
///2-read/write from file
///3-dynamic allocation
class Trial
{
    int x;int y;
    public:
    Trial(){}
    Trial(int _x){}
    ~Trial(){}

};
int main()
{
    Trial obj;
}
////////////////////////////////////////////
class Draft
{
    int *ptr;
    public:
    Draft()
    {
        ptr=new int[5];
    }
    ~Draft()
    {
        delete[] ptr;
    }
};
//
void TryMe()
{
    Draft o1;
}
//
int main()
{
    TryMe();
    TryMe();
    TryMe();
    return 0;
}

////////////////////////////////////////////
class Stack
{
    private:
    int arr[5];
    int tos;
    public:
    //no need for setters &getters
    Stack()
    {
        cout<<"Stack ctor";
        tos=0;
    }
    //dest  important? NOOOOO
    ~Stack()
    {
        cout<<"Stack dest";
    }
    //Stack functions
    void Push(int value)
    {
        if(tos!=5)
        {
            arr[tos]=value;
            tos++;
        }
        else
        {
            cout<<"FULL!!!\n";
        }
    }
    //
    int Pop()
    {
        int result=-123;
        if(tos!=0)
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
};

int main()
{
    Stack s1;
    // int *ptr=s1.GetArr();
    // ptr[0]=10;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s1.Push(50);
    s1.Push(60);
    s1.Push(70);

    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<s1.Pop();
    //o/p
    //stack ctor
    //full!!!
    //full!!!
    //50
    //40
    //30
    //20
    //10
    //EMPTY -123
    //EMPTY -123
    //Stack dest
    return 0;
}

////////////////////////////////////////////////
//#include<iostream>
using namespace std;
class Stack
{
    private:
    int* arr;
    int size;
    int tos;
    public:
    //no need for setters &getters
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
    void Push(int value)
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
    int Pop()
    {
        int result=-123;
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
    //
    //
    friend void ViewStack(Stack param);
    //
};
//standalone fn
////is there any way to make standalone fn
////to access private members of class??YES
///if it became friend fn
////
///Friend fn:
////standalone fn but can access 
////private members of class it is 
////friend at

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
    Stack s1(10),s2(5);
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
   
    ViewStack(s1); //PASS VALUESSSSSSS
    
    // //s1 tos|4| size|10| arr=>|10|20|30|40|||||||
    // cout<<s1.Pop()
    // cout<<s1.Pop()
    // cout<<s1.Pop()
    // cout<<s1.Pop()
}

///////////////////////////////////////////////
//calculate counter of live objects
class Stack
{
    private:
    int* arr;
    int size;
    int tos;
    //this line of code will be executed once per program call
    static int counter;//Suppose it carry Zero for now
    //
    public:
    //getter for counter
    static int GetCounter()
    {
        return counter;
    }
    //
    //no need for setters &getters
    Stack()
    {
        //
        counter++;
        //
        tos=0;
        size=5;
        arr=new int[size];
        cout<<"Stack def ctor";
    }
    Stack(int _size)
    {
        //
        counter++;
        //
        tos=0;
        size=_size;
        arr=new int[size];
        cout<<"Stack 1p ctor";
    }
    //dest  important?YESSSSSSSS Very
    ~Stack()
    {
        //
        counter--;
        //
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
    void Push(int value)
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
   
    int Pop()
    {
        int result=-123;
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
    //
    //
    friend void ViewStack(Stack param);
    //
};

void ViewStack(Stack param)
{
    for (int  i = 0; i < param.tos; i++)
    {
        cout<<param.arr[i]<<endl;
    }
}

//initialize for any static variable [class variable]
//regardless it is private or not
int Stack::counter=0;
//
int main()
{
    Stack s1,s2(10),s3;
    //TryMe();
    // cout<<s1.counter; //3 //no make sense
    // cout<< Stack::counter; //3

    //compile error after private
    //Stack::counter=33;
    //cout<< Stack::counter; //33

    cout<<s1.GetCounter(); //3 //no make sense
    //after static
    cout<<Stack::GetCounter(); //3
    return 0;
}


///static variable / class variable / shared variable:
///>member variable with keyword static
///>static variable is valriable that o.s 
///will create only one copy of it in Memory[BSS]
///regadless # of objects created from this class
///>life time of class variable till program ends
///>static variable is acceseed by class Name not object name

//template

///////////////////////////////////////////////
//-fno-elide-constructors   
//settings -> compiler -> other compiler options tab
//RVO
///////////////////////////////////////////////
//OBSERVE
//1-class Complex 
//+  ctor()cout,ctor(,)cout,ctor(int)cout ,dest()cout
///in main
////Complex c1,c2,c3
////pass values
////c3=AddComplex(c1,c2); //pass by value
//o/p
//with observe -> NO static variable  with ur eyes
//ctor
//cotr
//des
//des
//des
//# of ctor != # of dest
//Why -> tomorrow


//OBSERVE with ur eyes
//2-class Stack
///int*arr,int size,int tos ,static counter
///ctor() cout
///ctor(size) cout
///dest()  for loop -1 then delete [] arr then cout
///push,pop ,isfull,isempty


///ViewStack(Stack param)
//as standalone and friend fn

//in main write exactly
//Stack s1(10);
//push 4 or 6 times

//ViewStack(s1); //runs successfully
//ViewStack(s1); //fail 
//Why? tomorrow isa

//try to print counter




//3-implement shift  queue
//4-implement  circular queue
