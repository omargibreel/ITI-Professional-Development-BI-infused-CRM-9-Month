#include <iostream>

using namespace std;

int main()
{

//7-  3*3     *    3*2   =  3*2


int mtrx1[3][3]={{-2,7,1},{19,22,1},{4,16,1}};
int mtrx2[3][2]={{-2,7},{19,5},{15,5}};
int fnlMat[3][2];
for(int x =0; x<3;x++){
    for(int y=0 ;y<2;y++){
            fnlMat[x][y]=0;
        for(int z=0 ; z<3;z++){
            fnlMat[x][y]+=mtrx1[x][z]*mtrx2[z][y];
        }
    }
}

  cout << "Final Matrix (3x2):" << endl;
    for (int i = 0; i < 3; i++) {
            for(int j=0;j<2;j++){
        cout << fnlMat[i][j] << "  ";
    }
            cout << endl ;

    }

    return 0;
}
