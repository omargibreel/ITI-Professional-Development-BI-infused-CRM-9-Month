#include <iostream>

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

    friend Complex AddComplex(const Complex left,const Complex right);
};

    Complex AddComplex(const Complex left,const Complex right)
{
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImg()+right.GetImg();
    Complex result(r,i);
    result.SetReal(r);
    result.SetImg(i);
    return result;
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

    Complex complex01(r1,i1);
    Complex complex02(5);
    Complex complex03;
    complex03 = AddComplex(complex01,complex02);

    complex03.print();
    complex01.print();
    complex02.print();


    return 0;
}
