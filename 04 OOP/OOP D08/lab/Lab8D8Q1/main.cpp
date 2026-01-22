#include <iostream>
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
using namespace std;
class Complex{
private:
    int real;
    int img;
public:
    void SetReal(int _real)
    {
        real=_real;
    }
    int GetReal() const
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

    Complex()
    {
        real=0;
        img=0;
        cout<<"welcome empty ctor() \n";
    }
    Complex(int _real,int _img)
    {
        real=_real;
        img=_img;
        cout<<"welcome ctor(real,img) \n";
    }
    Complex(int _num)
    {
        real=img=_num;
        cout<<"welcome ctor(num) \n";
    }

///cpy ctor [useless]
    Complex(const Complex& oldComp)
    {
        real=oldComp.real;
        img=oldComp.img;
        cout<<"copy ctor \n";

    }
    ~Complex()
    {
        cout<<"dest called\n";
    }

     void print()
    {
        if(real == 0 && img==0)
            cout<<0<<endl;

        else if(real==0)
        {
            if(img==1)
                cout<<"i \n";
            else if(img==-1)
                cout<<"-i \n";
            else
                cout<<img<<"i \n";
        }
        else if(img==0)
            cout<<real<<"\n";
        else{
            cout<<real;
            if(img==1)
                cout<<"+i \n";
            else if(img==-1)
                cout<<"-i \n";
        else {
            if(img>0)
                cout<<"+"<<img<<"i\n";
            else
                cout<<img<<"i\n";
            }
        }
//
    }

    Complex Add(const Complex right)
    {
        Complex result;
        result.real=this->real+right.real;
        result.img=this->img+right.img;
        return result;
    }

    ////= operator [useless]
    Complex& operator=(const Complex&right)
    {
        real=right.real;
        img=right.img;
        return *this;
    }
    ////c1+c2
    Complex operator+(const Complex& right)
    {
        return Complex(real+right.real,img+right.img);
    }

    ////c1+10
    Complex operator+(int _num)
    {
        return Complex(real + _num, img);
    }
    ////c1+=c2
    Complex operator+=(const Complex& right)
    {
        real +=right.real;
        img+= right.img;
        return *this;
    }
    ////c1++
    Complex operator++(int)
    {
        return Complex(real++,img++);
    }
    ////++c1
     Complex operator++()
    {
        real++;
        img++;
        return *this;
    }
    ////c1>c2
    int operator>(const Complex& right)
    {
        return real>right.real && img>right.img;
    }

    //10+c1 [standalone]
    friend Complex AddComplex(const Complex left,const Complex right);
   friend Complex operator+(int _num, const Complex& right);

};


Complex operator+(int _num, const Complex& right)
{
    return Complex(right.real+_num,right.img+_num);
}



    Complex AddComplex(const Complex left,const Complex right)
{
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    Complex result(r,i);
    result.SetReal(r);
    result.SetImg(i);
    return result;
}

Complex operator+(int _num,Complex right)
{
    return right+ _num;
}

int main()
{
    int r1,r2,i1,i2;

    cout<<"Welcome proooooooo \n\nplz enter the real part of first complex : ";
    cin>>r1;
    cout<<"plz enter the imaginary part of first complex : ";
    cin>>i1;
//    cout<<"plz enter the real part of second complex : ";
//    cin>>r2;
//    cout<<"plz enter the imaginary part of second complex : ";
//    cin>>i2;

//
//    complex01.SetReal(r1);
//    complex01.SetImg(i1);
//    complex02.SetReal(r2);
//    complex02.SetImg(i2);

    Complex c1(r1,i1);
    Complex c2(5);
    Complex c3;
    c3=c1  +  c2;
    Complex c4 ;
    c4 = c2+10;
    c4.print();
    cout<<"c1 = ";
    c1.print();
    cout<<"c2 = ";
    c2.print();
    cout<<"c3 = ";
    c3.print();

    c3=++c1;
    cout<<"c3 = ";
    c3.print();

    cout<<"c1 = ";   /// dest called
    c1.print();


    c3=c1++;
    cout<<"c3 = ";
    c3.print();
    cout<<"c1 = ";
    c1.print();

    c3=10+c1;
    cout<<"c3 = ";
    c3.print();
    c1+=c2;
     cout<<"c2 = ";
    c2.print();
    cout<<"c1 = ";
    c1.print();

      if(c1>c2)
    {
        cout<<"B \n";
    }

    c3=c1;
    cout<<"c3 = ";
    c3.print();
    cout<<"c1 = ";
    c1.print();
    return 0;
}
