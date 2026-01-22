//namespace
/////////////////////////////////////////
//in c++
//#include<???>
namespace BookRead
{
    struct Book
    {
        isbn;
        authorName;
        year;
        title;
    };
}
namespace BookTicket
{
    struct Book
    {
        ticketNo;
        passengerName;
        from;
        to;
    };
}
//
using namespace BookRead;
//using namespace BookTicket;
//
int main()
{
    Book br1;
    Book br2;
    Book br3;
    BookTicket::Book bt1;
}

/////namespace
//logical grouping for one or more
//datatypes with specific name
//to achieve performance and identity


/////////////////////////////////////////
//cPP skelton code
//#include<iostream>//   namespace std{cin,cout,endl}
using namespace std;
int main()
{
    int age;
    /*std::*/cout<<"enter age"<<endl;
    cin>>age;
    cout<<"age="<<age<<endl;
    return 0;
}
/////////////////////////////////////////////
//Exclusive with cpp

//reference:alias name for another variable in memory

int main()
{
    int x=10;   //y x|10|0x10
    int& y=x;
    cout<<x; //10
    cout<<y; //10
    cout<<&x; //0x10
    cout<<&y; //0x10
    x=100;
    cout<<y; //100

    //int& z; //compile error
    return 0;
}
/////////////////////////////////////////////
void SwapV(int x ,int y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
void SwapA(int* x ,int* y)
{
    int tmp=*x;
    *x=*y;
    *y=tmp;
}
void SwapR(int& x ,int& y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

int main()
{
    int a=10,b=20;
    SwapR(a,b);  //pass References
    return 0;
}

////////////////////////////////////////////////
//struct is most like class except 
//any member can be accessed inside main by object name
//private:member can be accessed inside class/struct scope ONLY
//public:member can be accessed inside and outside class/struct scope 
////////////////////////////////////////////////
//#include<iostream>
using namespace std;
struct Employee
{
    private:
    int id;
    int age;
    float salary; 
    //password ->setter only
    public:
    //setters and getters
    //caller -> e1
    //caller -> e2
    void SetId(int _id)
    {
        /*caller e2*/id=_id;
    }
    //caller e1
    int GetId()
    {
        return /*caller e1*/id;
    }
    void SetAge(int _age)
    {
        age=_age;
    }
    int GetAge()
    {
        return age;
    }
    void SetSalary(float _salary)
    {
        if(_salary>=5000&&_salary<=10000)
        {salary=_salary;}
        else
        {
            salary=5000;
        }
    }
    float GetSalary()
    {
        return salary;
    }
    //fn to print employee
    //caller e1 then e2
    void Print()
    {
        cout<<"id="<</*caller*/id<<endl;
        cout<<"age="<<age<<endl;
        cout<<"salary="<<salary<<endl;
    }
};

//oop violation [encapsulation]
int main()
{
    //object/instance from employee
    Employee e1; //30B
    Employee e2; //30B

    e1.id=1;
    e1.age=22;
    e1.salary=1234;

    cout<<e1.id;
    cout<<e1.age;
    cout<<e1.salary;
    return 0;
}

int main()
{
    Employee e1; //e1 id|1| age|| salary||
    Employee e2; //e1 id|2| age|| salary||
    //e1.id=10; //compile error inaccessible
    //cout<<e1.id; //compile error inaccessible
    
    e1.SetId(1);
    e1.SetAge(22);
    e1.SetSalary(1234);

    int tmp;
    float tmpf;
    cout<<"Enter id\n";
    cin>>tmp;
    e2.SetId(tmp);
    cout<<"Enter age\n";
    cin>>tmp;
    e2.SetAge(tmp);
    cout<<"Enter salary\n";
    cin>>tmpf;
    e2.SetSalary(tmpf);

    cout<<e1.GetId()<<endl;
    cout<<e1.GetAge()<<endl;
    cout<<e1.GetSalary()<<endl;

    cout<<e2.GetId()<<endl;
    cout<<e2.GetAge()<<endl;
    cout<<e2.GetSalary()<<endl;

    e1.Print();
    e2.Print();
    return 0;
}
///////////////////////////////////////////////
//class default access modifier -> private 
//struct default access modifier -> public 
///////////////////////////////////////////////
//complex

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
        real=_real;
    }
    //caller -> left
    int GetReal() const /*safety factor*/
    {
        return real;
    }
    void SetImg(int _img)
    {
        img=_img;
    }
    int GetImg() const
    {
        return img;
    }
    void Print()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }

    //member fn to add 2 complex #'s
    // Complex Add(*this,Complex left,Complex right)
    // {
    //     Complex result;
    //     int r=left.real+right.real;
    //     //int i=left.img+right.img;
    //     result.real=r;
    //     result.img=left.img+right.img;
    //     return result;
    // }
    //caller c1 3,4
    Complex Add(const Complex& right)
    {
        Complex result;
        // //
        // right.real=-123;
        // //
        result.real=/*caller*/real+right.real;
        result.img=/*caller*/img+right.img;
        return result;
    }
    //
};
//standalone fn
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex result;
    // ///
    // left.SetReal(-1234);
    // ///
    //result.real=left.real+right.real;
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}
//
int main()
{
    Complex c1;
    Complex c2;
    Complex c3;
    c1.SetReal(3);
    c1.SetImg(4);

    int tmp;
    cout<<"Enter real\n";
    cin>>tmp; //5
    c2.SetReal(tmp);
    cout<<"Enter img\n";
    cin>>tmp; //6
    c2.SetImg(tmp);

    c1.Print();  //3+4i
    c2.Print();  //5+6i

    //c3=c1.Add(c1,c2);  //pass VALUESSSS  Add(3,4|5,6)
    c3=c1.Add(c2);  //pass REFERENCES  Add(3,4|5,6)
    
    c3=AddComplex(c1,c2); //pass by VALUESSS then by References

    c3.Print(); //8+10i
}

///pass by value -> read only
///pass by reference -> read and write


////////////////////////////////////////////////
//this
//inside any member fn [method]
//there is hidden input parameter
//named className* this

//ابعدوا عم المشتبهات
//#include<iostream>
using namespace std;
class Complex
{
    private:
    int real;
    int img;
    public:
    //caller c1 
    void SetReal(/*Complex *this,*/int _real)
    {
        //(*this).real=_real;
        this->real=_real;
        //real=_real;
    }
    int GetReal(/*Complex *this,*/) const 
    {
        return this->real;
    }
    void SetImg(/*Complex *this,*/int _img)
    {
        img=_img;
    }
    int GetImg(/*Complex *this,*/) const
    {
        return (*this).img;
    }
    void Print(/*Complex *this,*/)
    {
        cout<<real<<"+"<<this->img<<"i"<<endl;
    }
    //caller c1 3,4
    Complex Add(/*Complex *this,*/const Complex& right)
    {
        Complex result;
        result.real=this->real+right.real;
        result.img=img+right.img;
        return result;
    }
    //
};
//standalone fn has no *this
Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex result;
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    result.SetReal(r);
    result.SetImg(i);
    return result;
}
//
int main()
{
    Complex c1;
    Complex c2;
    Complex c3;

    c1.SetReal(3); 
    //Compiler
    //Complex::SetReal(&c1,3);

    c3=c1.Add(c2); //c1.Add(&c1,c2);
    c1.Print(); //Complex::Print(&c1);
    return 0;
}

//////////////////////////////////////////////
//Lab Assignments
//class Complex
//{
//real,img
//setters&getters
//print
//Add MEMBER
//};
//Add Standalone

///real img  print
///3     4   3+4i
///3    -4   3-4i
///3     1   3+i
///3    -1   3-i
///0     1   i
///0    -1   -i
///0     0   0
///1     0   1


