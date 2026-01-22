//casting
//pointers revision
//dynamic allocation
//recursive function
////////////////////////////////////////////////////////
int main()
{
    int a=1,b=2,c=3,d=4;
    int* ptrarr[4];  //4*4 or 4*8B
    ///ptrarr |->|->|->|->|   
    //put in fst elemt of array address of a
    //ptrarr=a; //F
    //ptrarr=&a; //F
    //ptrarr[0]=a; //F  //no error => logic error
    //ptrarr[0]=&a; //T


    //Array default values with array declaration
    int* ptrArr[4]={&a,&b,&c,&d};

}

int main()
{
    int arr[4]={1,2,3,4};
    int* ptrArr[4]; //ptrArr|&1|||||

    //put in array of pointers fst element
    //ptrArr=arr; //F
    //ptrArr=&arr;//F
    //ptrArr=arr[0];//F
    //ptrArr=&arr[0];//F
    //ptrArr[0]=arr; //T
    //ptrArr[0]=&arr; //T
    //ptrArr[0]=arr[0]; //F
    //ptrArr[0]=&arr[0]; //T

    //*ptrArr=arr ; //T

    //ptrArr=arr;//F
}
/////////////////////////////////////////////
//Casting [value]
///Convert value from data type to another
// data type
//casting
//value of data type can be converted to another one ,,, True
//latest c,cPP Versions , this will be done Implicitly
//Implicitly =>compiler will do it itself
//Explicitly => you [developer ] will do it yourself


int main()
{
    int x=22; //4B  +-2milliar 
    double y=33; //444,000,000,000  //8B 
    
    //NO COMPILE ERROR +no RUNTIME ERROR
    //implicit casting
    //unsafe casting
    //x=y;

    //NO COMPILE ERROR +no RUNTIME ERROR
    //explicit casting [recommended]
    x=(int)y;

    // ////implicit casting
    // ////safe casting
    // y=x;

    // //explicit casting [useless]
    // //y=(double)x;

    cout<<"x="<<x; //rubbish -2milliar
    cout<<"y="<<y; //444000000000

}

//////////////////////////////////////////
///promotion
///char->int -> long -> float -> double
int main()
{
    // int x=3;
    // char ch='M';
    // int result=x+ch;
    // cout<<result; //80

    int x=3,y=4;
    float z;
    //explicit casting is important
    
    z=x/(float)y;

    cout<<z; //0.75
    return 0;
}

//////////////////////////////////////////
///GP Pointer
int main()
{
    int x=10;
    void *ptr;
    ptr=&x;
    //cout<<*ptr;

    //soln1:
    //implicit casting
    int *tmpPtr=ptr;
    //explicit casting is useless
    //int *tmpPtr=(int*)ptr;
    cout<<*tmpPtr;

    //sol2:
    //explicit casting is MUST
    cout<<   *((int*)ptr)  ; //10

    return 0;
}
//////////////////////////////////////////
//array of 24 students

//array resized to 25 students=> Impossible

//////////////////////////////////////////////////////////////
//dynamic Allocation

//array => fixed size
/////we cannot declare array
//based on specific/different size in runtime
/////array when declared ,
//cannot be modified or deleted ->end of scope

//RUNTIME
////think to allocate dynamic place in runtime
////based on specific value/size
//think of deallocate this place whenever i want


/////dynamic allocation
///allocate specific value/values in runtime
///based on specific size
////deallocate whenever i want to.
///Stored in Heap  =>c,c++,java,c#

//syntax      HLL===>new
//c --->     malloc()

//syntax
//allocate 5 integers
//pointer to fst element allocated = new int[5]

int main()
{
   
    int * ptr=new int[5];  //20 B in heap
    char * ptr=new char[5];

    ///staddard way to allocate array at runtime
    int size;
    cout<<"Enter array size";
    cin>>size; //5
    double * dPtr=new double[size];
}

//////////////////////////////////////////////////////
int main()
{
    int size=5;
    //->
    int *ptr=new int [size];
    //from this moment int *ptr ==new== int ptr[5];
    *(ptr+0)=10;
    *(ptr+1)=20;
    *(ptr+2)=30;
    *(ptr+3)=40;
    *(ptr+4)=50;
    cout<<*(ptr+0);
    cout<<*(ptr+1);
    cout<<*(ptr+2);
    cout<<*(ptr+3);
    cout<<*(ptr+4);

    //when pointer points array , it acts like array [indexer]
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter #\n";
        cin>>ptr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout<<" #= "<<ptr[i]<<endl;
    }

    ptr[6]=400; //T //runtime error

    return 0;
}

////////////////////////////////////////////////////
int main()
{
    int _size=15;
    char * cptr= new char[_size];
    //from this moment char * cptr==new==char cptr[15]

    *(cptr+0)='a';
    *(cptr+1)='l';
    *(cptr+2)='i';
    *(cptr+3)='\0';

    cptr[0]='a';
    cptr[2]='l';
    cptr[3]='i';
    cptr[4]='\0';

    //<string.h>
    gets(cptr);
    puts(cptr);

    cin>>cptr;
    cout<<cptr;
}
////////////////////////////////////////////////////////
//allocate 5 integers
//then deallocate it whenever i want
int main()
{
    int *ptr=new int[5];
    for (int i = 0; i < 5; i++)
    {
        ptr[i]=10;
    }
    
    //deallocate this array here
    //delete[] address fst element of allocated data
    delete[] ptr;
    //
    ////we wanna deallocate place in heap we stored
    //delete[] ptr;
    //////delete[] -> remove protection
    //for allocated bytes
    ///so  any app can write in this place
    ///REMEMBER
    //ptr will still carries 0x10
    // =>undefined address
    //delete[] dosen't remove values/state
    // => remove protection
    //
    //
    ///
    //

    //in delete
    //delete[] ptr;
    //CAREFUL NOT ===> delete ptr;
    //delete[] ptr -> remove array
    //delete ptr -> remove non array[object]
    return 0;
}

///////Dangerous memory leakage/////////////////////////////////////////

void TryMe()
{
    int *ptr=new int[5];

    //remember
    delete [] ptr;
}

int main()
{
    TryMe();
    TryMe();
    TryMe();
    return 0;
}


int * TryMe2()
{
    int *ptr=new int[5];

    return ptr;
}

int main()
{
    int *xptr=TryMe2();
    //loop then print

    delete [] xptr;
    return 0;
}

////////////////////////////////////////////////////
//dynamic allocation for array of pointers
int main()
{
    int col=4;
    int* ptrArr[3];

    ptrArr[0]=new int[col];
    ptrArr[1]=new int[col];
    ptrArr[2]=new int[col];

    //from this moment int* ptrArr[3]; 
    ///=== int ptrArr[3][4];
    **ptrArr=10;

    delete ptrArr; ///WRONG =>cannot remove from Stack
    delete [] ptrArr[0]; 
    delete [] ptrArr[1]; 
    delete [] ptrArr[2]; 


    // //Draft
    // int arr[3][4];
    // cout<< arr;
    // cout<< arr[0];
    // cout<< arr[0][0];
    // //
}

/////////////////////////////////////////////
int main()
{
    int col=4;
    int row=3;
    int ** ptrArr;
    
    ptrArr=new int*[row];

    ptrArr[0]=new int[col];
    ptrArr[1]=new int[col];
    ptrArr[2]=new int[col];

    ///from this moment
    //int ** ptrArr=== int ** ptrArr[3][4]
    ///
    ///
    ///
    delete[] ptrArr[0];
    delete[] ptrArr[1];
    delete[] ptrArr[2];
    delete[] ptrArr;
}

///////////////////////////////////////////

int main()
{
    int col=4;
    int row=3;
    int * ptrArr;
    
    ptrArr=new int*[row];

    ptrArr[0]=new int[col];
    ptrArr[1]=new int[col];
    ptrArr[2]=new int[col];

    ///from this moment
    //int ** ptrArr=== int ** ptrArr[3][4]
    ///
    /////ptrArr[0][0]=kaza;
    ///
    ///
    delete[] ptrArr[0];
    delete[] ptrArr[1];
    delete[] ptrArr[2];
    delete[] ptrArr;
}


////////////////////////////////////////////////
//pointer to struct
struct Employee
{
    int id;
    char name[12];
    int age;
};

int main()
{
    int empSize=3;
    Employee * empPtr= new Employee[empSize];
    ///from this moment  Employee * empPtr ==new==Employee empPtr[3]
    for (int i = 0; i < empSize; i++)
    {
        empPtr[i].id=1;
        strcpy(empPtr[i].name,"Sama");
        empPtr[i].age=22;
    }   

    //empPtr->id=1;
    //(empPtr+1)->id=2;
}

////////////////////////////////////////////////
//recursive fn 
////////////////////////////////////////////////
//Lab Assignments


///1- try dynamic allocation
// for pointer to integer read and write  2ways
///2- try dynamic allocation for Array
// of pointers to integers read and write
//// int *arr[3] -> int arr[3][4]

//3- int **ptrArr;





