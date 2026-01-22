#include <iostream>

using namespace std;
//Lab Assigments:
//[discuss] early vs late binding Base,Derived,Derived2
//1-Geoshape abstract
////SumOFAreasV1()
////SumOFAreasV2()

//2- abajora via picture {shape** sptr}
class Geoshape
{

protected:
    double dim1;
    double dim2;
public:
    void SetDim(double _dim1)
    {
        dim1=_dim1;
    }
    double GetDim1()
    {
        return dim1;
    }
    void SetDim2(double _dim2)
    {
        dim2=_dim2;
    }
    double GetDim2(){return dim2;};
    Geoshape()
    {
        dim1=dim2=0;
        cout<<"geo def ctor \n";
    }
        Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
        cout<<"geo 2p ctor";
    }
    Geoshape(double _dim)
    {
        dim1=dim2=_dim;
        cout<<"geo 1p ctor";
    }
    ~Geoshape()
    {
        cout<<"Geo Destructor \n";
    }

    virtual double Area()=0;

};

class Rect:public Geoshape
{
    public:
    Rect()
    {
        cout<<"Rect Ctor \n";
    }
     Rect(double _d1,double _d2):Geoshape(_d1,_d2)
    {
        cout<<"Rect Ctor \n";
    }
    ~Rect()
    {
        cout<<"Rect Destructor \n";
    }
    double Area()
    {
        return dim1*dim2;
    }

};

class Square:public Geoshape
{
    public:
    Square()
    {
        cout<<"Square Ctor \n";
    }
    Square(double _d):Geoshape(_d)//Geoshape(_d,_d)
    {
        cout<<"Square Ctor \n";
    }
    ~Square()
    {
        cout<<"Square Destructor \n";
    }
    double Area()
    {
        return dim1*dim2;
    }
};


class Circle:public Geoshape
{
    public:
    Circle()
    {
        cout<<"Circle Ctor \n";
    }
    Circle(double _radius)
    {
        dim1=dim2=_radius;
        cout<<"Circle Ctor \n";
    }
    ~Circle()
    {
        cout<<"Circle Destructor \n";
    }

    double Area()
    {
       return 3.14 * dim1 * dim2;
    }
};
class Tri:public Geoshape
{
    public:
    Tri()
    {
        cout<<"Triangle Ctor \n";
    }
    Tri(double _base,double _height)
    :Geoshape(_height,_base)
    {
        cout<<"Triangle Ctor \n";
    }
    ~Tri()
    {
        cout<<"Triangle Destructor \n";

    }
    double Area()
    {
        return 0.5 * dim1 * dim2;
    }
};
double SumOfAreasV1(Rect *_rptr,int _rSize,Square* _sPtr,int _sSize,Tri *_tPtr,int _tSize)
{
    double sum=0;
    for (int i = 0; i < _rSize; i++)
    {
        sum+=_rptr[i].Area();
    }
    for (int i = 0; i < _sSize; i++)
    {
        sum+=_sPtr[i].Area();
    }
    for (int i = 0; i < _tSize; i++)
    {
        sum+=_tPtr[i].Area();
    }
    return sum;
}




double SumOfAreasV2(Geoshape** _gPtrArr,int _gSize)
{
    double sum=0;
    for (int i = 0; i < _gSize; i++)
    {
        sum+=_gPtrArr[i]->Area();
    }
    return sum;
}

int main()
{


//    cout<<"v1============================================ \n";
//    Rect rarr[3]={Rect(3,4),Rect(2,5),Rect(2,5)};
//    Square sarr[2]={Square(10),Square(10)};
//    Tri tarr[2]={Tri(2,10),Tri(2,10)};
//    Circle c(10);
//    cout<<SumOfAreasV1(rarr,3,sarr,2,tarr,2)<<endl; //232
//
//    //
//    Geoshape *gPtr=new Rect(3,4);
//    cout<<gPtr->Area()<<endl; //12
//
//


    cout<<"v2============================================ \n";

    Rect rarr[3]={Rect(3,4),Rect(2,5),Rect(2,5)};
    Square sarr[2]={Square(10),Square(10)};
    Tri tarr[2]={Tri(2,10),Tri(2,10)};
    Circle c(10);

    Geoshape* gPtrArr[7] ={rarr,&rarr[1],&rarr[2],sarr,&sarr[1],tarr,&tarr[1]};
    cout<<gPtrArr[3]->Area()<<"\n";
    cout<<SumOfAreasV2(gPtrArr,7)<<"\n";


    return 0;
}
