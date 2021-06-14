#include<iostream>
#include<time.h>
#include<vector>
#include <stdlib.h>  
#include"LinearAlgebraFNS.hpp"
#include"gtest/gtest.h"

/*Test a 4x4 matriax transposure*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4){
    std::vector<std::vector<int>> vec1(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128i_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}

/*Test a 4x4 matriax transposure random matrix*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4_random_matrix){
    std::vector<std::vector<int>> vec1(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));

    srand (time(NULL));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=rand() % 10 + 1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128i_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}
/*Test 4x4 identidy matrix*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4_identidy_matrix){
    std::vector<std::vector<int>> vec1{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128i_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}

/*Test upper triangular matrix*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4_upper_triangular_matrix){
    std::vector<std::vector<int>> vec1{{0,1,1,1},{0,0,1,1},{0,0,0,1},{0,0,0,0}};
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128i_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}

/*Test down triangular matrix*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4_down_triangular_matrix){
    std::vector<std::vector<int>> vec1{{0,0,0,0},{1,0,0,0},{1,1,0,0},{1,1,1,0}};
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128i_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}

/*Test upper down triangular matrix*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4_upper_down_triangular_matrix){
    std::vector<std::vector<int>> vec1{{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128i_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}

/*Test a 4x4 float matriax transposure*/
TEST(vectorized128_transpose_mat4x4,test_transposure4x4){
    std::vector<std::vector<float>> vec1(4, std::vector<float> (4, 0));
    std::vector<std::vector<float>> tr(4, std::vector<float> (4, 0));
    std::vector<std::vector<float>> tr1(4, std::vector<float> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transpose(vec1);
    tr1 = vectorized128_transpose_mat4x4(vec1);
    for (int i = 0;i < 4; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(tr[i][j],tr1[i][j]);}
    }
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}