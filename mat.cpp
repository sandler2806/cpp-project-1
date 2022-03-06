#include <iostream>
using namespace std;

#include "mat.hpp"

namespace ariel {
    string mat(int collum,int row,char a,char b) {
        if(row%2==0 || collum%2==0){
            throw invalid_argument( "cMat size is always odd" );
        }
        if(row<1 || collum<1){
            throw invalid_argument( "Mat size is always positive" );
        }
        int rowLength=row;
        int collumLength=collum;
        char sigh=a;
        char** matrix = new char*[row];
        for (int i = 0; i < row; ++i){
            matrix[i] = new char[collum];
        }

        while (row>=1 && collum>=1){
            int startIndex=(collumLength-collum)/2;

            if((collumLength-collum)%4==0){
                sigh=a;
            }
            else{
                sigh=b;
            }

            for (int i = startIndex; i <row+startIndex ; ++i) {
                matrix[i][startIndex]=sigh;
                matrix[i][collumLength-startIndex-1]=sigh;

            }
            for (int i = startIndex; i <collum+startIndex ; ++i) {
                matrix[startIndex][i]=sigh;
                matrix[rowLength-startIndex-1][i]=sigh;
            }
            row-=2;
            collum-=2;
        }
        string ans;
        for (int i = 0; i < rowLength; ++i) {
            for (int j = 0; j < collumLength; ++j) {
                ans+= matrix[i][j];
            }
            ans+='\n';
        }
        for (int i = 0; i < row; ++i){
            delete [] matrix[i];
        }
        delete [] matrix;
        return ans;
    }
}
