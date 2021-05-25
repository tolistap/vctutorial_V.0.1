#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include"LinearAlgebraFNS.h"
#include"PrintFNS.h"
#include"gtest/gtest.h"

TEST(scalar_mul_matint,test4x4_multiplication){
    std::vector<std::vector<int>> M1 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<int>> M4 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    scalar_mul_matint(M3,M1,M2,4,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,4,4,4);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test8x4_multiplication){
    std::vector<std::vector<int>> M1 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    std::vector<std::vector<int>> M4 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    scalar_mul_matint(M3,M1,M2,8,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,8,4,4);
    for (int i = 0;i < 8; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test16x4_multiplication){
    int rows = 16;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test32x4_multiplication){
    int rows = 32;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test64x4_multiplication){
    int rows = 64;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test128x4_multiplication){
    int rows = 128;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test256x4_multiplication){
    int rows = 256;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test512x4_multiplication){
    int rows = 512;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test1000x4_multiplication){
    int rows = 1000;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test1024x4_multiplication){
    int rows = 1024;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test2000x4_multiplication){
    int rows = 2000;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

TEST(scalar_mul_matcpp,test2048x4_multiplication){
    int rows = 2048;
    std::vector<std::vector<int>> M1 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 (rows, std::vector<int> (4, 0));
    std::vector<std::vector<int>> M4 (rows, std::vector<int> (4, 0));
    srand (time(NULL));
    for(int i=0; i<rows; i++){
        for (int j=0; j<4; j++){M1[i][j]=rand() % 1000 + 1 ;}
    }
    scalar_mul_matint(M3,M1,M2,rows,4,4);
    vectorized128_mul_matcpp(M4,M1,M2,rows,4,4);
    for (int i = 0;i < rows; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(M3[i][j],M4[i][j]);}
    }
}

int main(){
    std::cout<<"Call matmul"<<std::endl;
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();

    /*C++ way of handling matrixes*/
    /*
    std::vector<std::vector<float>> A {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    std::vector<std::vector<float>> B {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<float>> C {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    scalar_mul_matfl(C,A,B,3,4,4);
    print_matrix(C);
    std::cout<<"-----------"<<std::endl;
    std::vector<std::vector<int>> M1 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    std::vector<std::vector<int>> M2 {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> M3 {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    vectorized128_mul_matcpp(M3,M1,M2,3,4,4);
    print_matrixint(M3);
    return 0 ;
    */

}