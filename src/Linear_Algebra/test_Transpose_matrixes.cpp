#include<iostream>
#include<time.h>
#include<vector>
#include <stdlib.h>  
#include"LinearAlgebraFNS.h"
#include"PrintFNS.h"
#include"gtest/gtest.h"

/*Test a 4x4 matriax transposure*/
TEST(vectorized128i_transpose_mat4x4,test_transposure4x4){
    std::vector<std::vector<int>> vec1(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr(4, std::vector<int> (4, 0));
    std::vector<std::vector<int>> tr1(4, std::vector<int> (4, 0));
    for(int i=0; i<4; i++){
        for (int j=0; j<4; j++){vec1[i][j]=i+1;}
    }
    tr = scalar_transposeint(vec1);
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
    tr = scalar_transposeint(vec1);
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
    tr = scalar_transposeint(vec1);
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
    tr = scalar_transposeint(vec1);
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
    tr = scalar_transposeint(vec1);
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
    tr = scalar_transposeint(vec1);
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
    /*
    std::vector<std::vector<int>> vec = {{1,2,3,4,5,6,7,8},{9,10,11,12,13,14,15,16},
                                        {17,18,19,20,21,22,23,24},{25,26,27,28,29,30,31,32},
                                        {33,34,35,36,37,38,39,40},{41,42,43,44,45,46,47,48},
                                        {49,50,51,52,53,54,55,56},{57,58,59,60,61,62,64,64}};
    std::vector<std::vector<int>> tr;
    

    tr = vectorized128i_transpose_mat8x8(vec);  
    print_matrixint(tr);
    return 0;
    */
}