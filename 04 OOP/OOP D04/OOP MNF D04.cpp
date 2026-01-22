//string
//struct
//pointer
//pointer to struct
///////////////////////////////////////////////
//no dt called string
//use string as array of characters
//char name[14+1];
//cin>>name; //AliENTER   //|a|l|i|\0|||
//cout<<name; //print till \0
//<string.h>
//gets(name);
//puts(name);

//////////////////////////////////////////
//string.h library
//gets(array of characters);
//puts(array of characters);
//strcpy(Larrayofcharacters,Rarrayofcharacters);
//strcat(Larrayofcharacters,Rarrayofcharacters);
//strcmp(Larrayofcharacters,Rarrayofcharacters); //ascii
//strcmpi(Larrayofcharacters,Rarrayofcharacters); //ascii
//strlen(Larrayofcharacters);  //\0
//atoi(Larrayofcharacters);
//atof(Larrayofcharacters);
///////////////////////////////////////////
int main()
{
    char fname[15]="Ali";//{a,l,i} //5,y,\0
    char lname[15]="Osama";
    char fullName[30];

    strcpy(fullName,fname);
    strcat(fullName," ");
    strcat(fullName,lname);


    // //fullName=fname;
    // fullName[0]=fname[0];
    // fullName[1]=fname[1];
    // fullName[2]=fname[2];
    // fullName[3]=' ';
    // fullName[4]=lname[0];
    
    // char num[10]="22";
    // int x=atoi(num);
    
    return 0;
}
/////fn prototype/////////////////////////////////////////
//#include
//usin
int Add(int left,int right);
int Sub(int,int);
int main()
{
    Add(11,22); //compile error
    return 0;
}
int Add(int left,int right)
{
    return left+right;
}
int Sub(int left,int right)
{
    return left-right;
}
//////////////////////////////////////////////
//struct
//#include
//usin

struct Employee
{
    int id;
    char name[18];
    int age;
    float salary;
};
void PrintEmployee(Employee param)
{
    cout<<"id="<<param.id<<endl;
    cout<<"name="<<param.name<<endl;
    cout<<"age="<<param.age<<endl;
    cout<<"salary="<<param.salary<<endl;
}
int main()
{
    Employee e1; //30B
    e1.id=1;
    strcpy(e1.name,"Ali");
    e1.age=22;
    e1.salary=1234;

    Employee e2;
    cout<<"Enter id\n";
    cin>>e2.id;
    cout<<"Enter name\n";
    cin>>e2.name;
    //gets(e2.name)
    cout<<"Enter age\n";
    cin>>e2.age;
    cout<<"Enter salary\n";
    cin>>e2.salary;

    PrintEmployee(e1);
    PrintEmployee(e2);
    //pass VALUESSSSSS

    return 0;
}
/////////////////////////////////////////////
int main()
{
    Employee employees[3]; //90B
    for (int  i = 0; i < 3; i++)
    {
        cout<<"Enter id\n";
        cin>>employees[i].id;
        cout<<"Enter name\n";
        cin>>employees[i].name;
        //gets(employees[i].name)
        do
        {
            cout<<"Enter age\n";
            cin>>employees[i].age;
        }while(employees[i].age<18||employees[i].age>60);
        cout<<"Enter salary\n";
        cin>>employees[i].salary;
    }
    //
    for (int i = 0; i < 3; i++)
    {
        PrintEmployee(employees[i]);
    }
    return 0;
}

////////////////////////////////////////////////
//Pointer

int main()
{
    int x=10;
    char ch='A';
}

//if i wanna use variable
//carry address another variable
//thats called:

//pointer:
//variable carries address 
//another variable in memory

int main()
{
    int x;  //RUBBISH
    char ch='A';

    //make pointer to integer
    //make variable[pointer] carry address of integer variable 
    int *ptr; //NULL

    //make pointer to char
    char * cptr;
}
//////////////////////////////////////
//make pointer to int then assign address to it
int main()
{
    int x=10;  //RUBBISH
    

    //make pointer to integer
    //make variable[pointer] carry address of integer variable 
    int *ptr; //NULL

    //make ptr carries address of x
    ptr=&x;
    
    
    
    // ptr=x; //RIGHT
    // //logical error will cause
    // //runtime error later
}

//////////////////////////////////////////////////
//pointer to int then access int value via pointer

int main()
{
    int x=10;

    int *ptr;

    ptr=&x;

    //chage value of x
    x=100;


    ///Access place of x via pointer
    *ptr=100;
    //access int place that pointer points at
    
    cout<<*ptr; //100
    ///*ptr  === x
    cout<<*x;
    return 0;
}

int main()
{
    float y=1.2;  
    float *fptr=&y;
    cout<<*y;
}

///////////////////////////////////////////
///size of pointer
///4B
///8B
//different based on application size
///codeblocks 17.12 32Bit   4B
///codeblocks 23.12 64Bit   8B
int main()
{
    int *ptr;     //4or8
    double *dptr;
    char *cptr;
    cout<<sizeof(ptr); //4 or 8
    cout<<sizeof(int*); //4 or 8
    cout<<sizeof(dptr); //4 or 8
    cout<<sizeof(double*); //4 or 8
    cout<<sizeof(cptr); //4 or 8
    cout<<sizeof(char*); //4 or 8
}
//////////////////////////////////////////
///NOT RECOMMENDED
int main()
{
    int x=10;

    float *fptr=&x;  //No Error

    cout<<*fptr; //non sense
}
////////////////////////////////////////////
///arithmatic operation on pointer

int main()
{
    int x=10;
    int *ptr=&x;
    ptr++;

    double y=1.2;
    double *dptr=&y;
    dptr++;

    //cout<<++ptr;  //0x14
    //cout<<ptr+1;  //0x14
    return 0;
}

//////////////////////////////////////////////
//General purpose pointer  ->dynamic allocation
//pointer to void
int main()
{
    int x=10;   //x|10|0x10

    void *ptr; //ptr|0x10|0x30

    ////gpp can not be increased
    //ptr++;

    cout<<sizeof(void*); //4 or 8 

    ptr=&x;

    cout<<x; //10
    cout<<&x;//0x10
    cout<<*x;//compile error
    cout<<ptr;//0x10
    cout<<&ptr;//0x30
    //cout<<*ptr; //?

    int* tmpPtr=ptr;
    cout<<*tmpPtr;//10
}

///////////////////////////////////////////////
//pointer to array of int
int main()
{
    int arr[5]={1,2,3,4,5};
    int *ptr;

    //make ptr carry address fst elemtn of array
    ptr=arr; //T
    ptr=&arr; //T
    ptr=arr[0]; //F
    ptr=&arr[0]; //T

    //recommended
    ptr=arr;

    //v3 Recommended
    //[when pointer points array ,it acts like array [indexer]]
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter # at index "<<i<<endl;
        cin>> ptr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<"# at index "<<i<<"= "<<ptr[i]<<endl;
    }
    ///
    //v2
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

    //v1 REMEMBER to Reassign ptr to arr again after any process
    *ptr=10;
    ptr++;
    *ptr=20;
    ptr++;
    *ptr=30;
    ptr++;
    *ptr=40;
    ptr++;
    *ptr=50;
    ptr++;
    //REMEMBER
    ptr=arr;

    cout<<*ptr;
    ptr++;
    cout<<*ptr;
    ptr++;
    cout<<*ptr;
    ptr++;
    cout<<*ptr;
    ptr++;
    cout<<*ptr;
    ptr++;
    //REMEMBER
    ptr=arr;


    return 0;
}


//array itself -> constant pointer
int main()
{
    int arr[5];

    *(arr+0)=10;
    *(arr+1)=20;
    *(arr+2)=20;
    *(arr+3)=20;
    *(arr+4)=20;

    arr[0]=10;
    arr[1]=10;
    arr[2]=10;
    arr[3]=10;
    arr[4]=10;
}
////////////////////////////////////////////
//point to array of characters
int main()
{
    char name[15];
    char * cptr;
    cptr=name;

    //v1  less used
    *cptr='A';
    cptr++;
    *cptr='l';
    cptr++;
    *cptr='i';
    cptr++;
    *cptr='\0';
    cptr++;
    //REMEMBER
    cptr=name;
    cout<<*cptr;
    cptr++;
    cout<<*cptr;
    cptr++;
    cout<<*cptr;
    cptr++;
    //REMEMBER
    cptr=name;

    //v2
    *(cptr+0)='A';
    *(cptr+1)='l';
    *(cptr+2)='i';
    *(cptr+3)='\0';
    cout<<*(cptr+0);
    cout<<*(cptr+1);
    cout<<*(cptr+2);

    //v3 when pointer points array ,it acts like array [indexer]
    cptr[0]='A';
    cptr[1]='l';
    cptr[2]='i';
    cptr[3]='\0';
    cout<<cptr[0];
    cout<<cptr[1];
    cout<<cptr[2];

    cin>>cptr;
    cout<<cptr;

    //<string.h>
    gets(cptr);
    puts(cptr);
    return 0;
}

/////////////////////////////////////////////
//pointer to pointer to int
int main()
{
    int x=10;

    int *ptr=&x;

    int* *ptrToPtr=&ptr;

    cout<<x;
    cout<<&x;
    cout<<*x; //X

    cout<<ptr;
    cout<<&ptr;
    cout<<*ptr;

    cout<<ptrToPtr;
    cout<<&ptrToPtr;
    cout<<*ptrToPtr; //0x10
    cout<<**ptrToPtr; //10

    return 0;
}

////WRONG/////////////////////////
int main()
{
    int x=10;

    int *ptr=&x;

    int *ptrToPtr=&ptr;

    cout<<x;
    cout<<&x;
    cout<<*x; //X

    cout<<ptr;
    cout<<&ptr;
    cout<<*ptr;

    cout<<ptrToPtr;
    cout<<&ptrToPtr;
    cout<<*ptrToPtr; //0x10
    cout<<**ptrToPtr; //10

    return 0;
}


//////////////////////////////////////////////

void SwapV(int left,int right)
{
    int tmp;
    tmp=left;
    left=right;
    right=tmp;
}
void SwapA(int* left,int* right)
{
    int tmp;
    tmp=*left;
    *left=*right;
    *right=tmp;
}

int main()
{
    int x=3;
    int y=5;
    cout<<"Before Swap\n";
    cout<<"x="<<x; //3
    cout<<"y="<<y; //5
    //SwapV(x,y); //PASS VALUESSSS
    SwapA(&x,&y);
    cout<<"After Swap\n";
    cout<<"x="<<x; //5
    cout<<"y="<<y; //3
    return 0;
}

///////////////////////////////////////////
//NOT Standard
void PrintArray(int param[],int _size){}
void PrintArray(int param[5])
{
    //for loop 
    //print
}

//Standard Way to pass array to fn
void printArray(int *param,int _size){}
void print2DArray(int *param,int _size,int _row){}
int main()
{
    int arr[5]={1,2,3,4,5};

    int arr2[3][4];
    print2DArray(arr2,3,4);

    printArray(arr,5);
}

//////////////////////////////////////////////
//pointer to struct

struct Employee
{
    int id;
    char name[12];
    int age;
};
int main()
{
    Employee e1; //20B

    Employee *empPtr;  //4 or 8B

    empPtr=&e1;

    (*empPtr).id=1;
    strcpy( (*empPtr).name, "Ali");
    (*empPtr).age=22;


    (*empPtr).id=1;
    //-> arrow operator [exclusive with pointer to struct]
    empPtr->id=1;

    (*empPtr).age=22;
    empPtr->age=22;

    strcpy ((*empPtr).name,"Sara");
    strcpy(empPtr->name,"Sara");

    cout<<empPtr->id;

}
/////////////////////////////////////////////
//Lab Assignments
//1- pointer to integer  read & write
//2- pointer to array  read and write   3 ways
//3- pointer to pointer of integer Write ONLY
//4- pass by value/address    swap
//5- pass array as input param []   ,pass pointer
//6- return [] as return type[not supported][compiler error]
    //and return pointer as a return type

//7- pointer to struct of employee   ->

//8- fname, lname -> fullname






