#include <iostream>
#include <vector>
using namespace std;

#include "mat.hpp"

namespace ariel {
    // mat return string that represents a rug
    string mat(int collum,int row,char a,char b) {
        // check if one number is odd or negative
        if(row%2==0 || collum%2==0){
            throw invalid_argument( "cMat size is always odd" );
        }
        if(row<1 || collum<1){
            throw invalid_argument( "Mat size is always positive" );
        }
        int rowLength=row;
        int collumLength=collum;
        char symbol=a;
        // create matrix of chars
        vector<vector<char>> matrix( row, vector<char>( collum ) );

        // fill the bounds of the matrix until the row\collum number is less than 1
        while (row>=1 && collum>=1){
            // find the index to start fill from
            int startIndex=(collumLength-collum)/2;
            // find which char we should fill at this level
            if((collumLength-collum)%4==0){
                symbol=a;
            }
            else{
                symbol=b;
            }
            // fill the bounds of the matrix for current level
            for (int i = startIndex; i <row+startIndex ; ++i) {
                matrix[i][startIndex]=symbol;
                matrix[i][collumLength-startIndex-1]=symbol;

            }
            for (int i = startIndex; i <collum+startIndex ; ++i) {
                matrix[startIndex][i]=symbol;
                matrix[rowLength-startIndex-1][i]=symbol;
            }
            row-=2;
            collum-=2;
        }
        string ans;
        // convert the matrix to string
        for (int i = 0; i < rowLength; ++i) {
            for (int j = 0; j < collumLength; ++j) {
                ans+=matrix[i][j];
            }
            ans+='\n';
        }

        return ans;
    }
}
