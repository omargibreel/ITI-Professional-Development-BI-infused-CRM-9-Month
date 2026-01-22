#include <iostream>

using namespace std;

int main()
{
    //6-multiply 2 matrix
//3*2    *  2*1  =  3*1


// -2   7               -2       =  -4
// 19   22              19
// 4    16



int matrix1[3][2]={{-2,7},{19,22},{4,16}};
int matrix2[2][1]={{-2},{19}};
int finalMat[3][1];
for(int x =0; x<3;x++){
    for(int y=0 ;y<1;y++){
            finalMat[x][y]=0;
        for(int z=0 ; z<2;z++){
            finalMat[x][y]+=matrix1[x][z]*matrix2[z][y];
        }
    }
}

  cout << "Final Matrix (3x1):" << endl;

    for (int i = 0; i < 3; i++) {
        cout <<"  "<< finalMat[i][0] <<"  "<< endl;
    }




    return 0;
}
