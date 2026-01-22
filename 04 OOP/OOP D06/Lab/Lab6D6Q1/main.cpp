#include <iostream>

using namespace std;
class Complex{
private:
    int real;
    int imaginary;
public:
    void SetReal(int _real){
    real=_real;
    }
    int GetReal()const{
        return  real;
    }
    void SetImaginary(int _imaginary){
        imaginary=_imaginary;
    }
    int GetImaginary()const{
        return imaginary;
    }

    void print()
    {
        if(real == 0 && imaginary==0)
            cout<<0<<endl;

        else if(real==0)
        {
            if(imaginary==1)
                cout<<"i \n";
            else if(imaginary==-1)
                cout<<"-i \n";
            else
                cout<<imaginary<<"i \n";
        }
        else if(imaginary==0)
            cout<<real<<"\n";
        else{
            cout<<real;
            if(imaginary==1)
                cout<<"+i \n";
            else if(imaginary==-1)
                cout<<"-i \n";
        else {
            if(imaginary>0)
                cout<<"+"<<imaginary<<"i\n";
            else
                cout<<imaginary<<"i\n";
            }
        }
//
    }

    Complex Add(const Complex& right)
    {
        Complex result;
        result.real=this->real+right.real;
        result.imaginary=this->imaginary+right.imaginary;
        return result;
    }
};

    Complex AddComplex(const Complex& left,const Complex& right)
{
    Complex result;
    int r=left.GetReal()+right.GetReal();
    int i=left.GetImaginary()+right.GetImaginary();
    result.SetReal(r);
    result.SetImaginary(i);
    return result;
}
int main()
{
    Complex complex01;
    Complex complex02;
    int r1,r2,i1,i2;
    cout<<"Welcome proooooooo \n\nplz enter the real part of first complex : ";
    cin>>r1;
    cout<<"plz enter the imaginary part of first complex : ";
    cin>>i1;
    cout<<"plz enter the real part of second complex : ";
    cin>>r2;
    cout<<"plz enter the imaginary part of second complex : ";
    cin>>i2;
    complex01.SetReal(r1);
    complex01.SetImaginary(i1);
    complex02.SetReal(r2);
    complex02.SetImaginary(i2);
    Complex complex03 =complex01.Add(complex02);
    complex03.print();
    return 0;
}
