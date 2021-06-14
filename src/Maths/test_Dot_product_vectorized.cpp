/*In this file a variety of test for dot product vectorized functions was created
  starting with 4 elements and ending with 1024. 
  
  Dot product functions was vectorized as explained and descriped in his file with 
  tree diderend aproaches. Moreover, a 256 edition vectorizad.
*/

#include<iostream>
#include"gtest/gtest.h"
#include"MathsFNS.hpp"


/*Tests for dot product vectorized first way function*/
TEST(Test_Dotprod128w1x4,dot_product_vectorized128w1){
    int vec[4];
    for (int i=0;i<4;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,4), dot_product_vectorized128w1(vec,4));
}

TEST(Test_Dotprod128w1x8,dot_product_vectorized128w1){
    int vec[8];
    for (int i=0;i<8;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,8),dot_product_vectorized128w1(vec,8));
}

TEST(Test_Dotprod128w1x16,dot_product_vectorized128w1){
    int vec[16];
    for (int i=0;i<16;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,16),dot_product_vectorized128w1(vec,16));
}

TEST(Test_Dotprod128w1x32,dot_product_vectorized128w1){
    int vec[32];
    for (int i=0;i<32;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,32),dot_product_vectorized128w1(vec,32));
}

TEST(Test_Dotprod128w1x64,dot_product_vectorized128w1){
    int vec[64];
    for (int i=0;i<64;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,64),dot_product_vectorized128w1(vec,64));
}

TEST(Test_Dotprod128w1x100,dot_product_vectorized128w1){
    int vec[100];
    for (int i=0;i<100;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,100),dot_product_vectorized128w1(vec,100));
}

TEST(Test_Dotprod128w1x1024,dot_product_vectorized128w1){
    int vec[1024];
    for (int i=0;i<1024;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,1024),dot_product_vectorized128w1(vec,1024));
}


/*Test for dot product vectorized secont way function*/
TEST(Test_Dotprod128w2x4,dot_product_vectorized128w2){
    int vec[4];
    for (int i=0;i<4;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,4),dot_product_vectorized128w2(vec,4));
}

TEST(Test_Dotprod128w2x8,dot_product_vectorized128w2){
    int vec[8];
    for (int i=0;i<8;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,8),dot_product_vectorized128w2(vec,8));
}

TEST(Test_Dotprod128w2x16,dot_product_vectorized128w2){
    int vec[16];
    for (int i=0;i<16;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,16),dot_product_vectorized128w2(vec,16));
}

TEST(Test_Dotprod128w2x32,dot_product_vectorized128w2){
    int vec[32];
    for (int i=0;i<32;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,32),dot_product_vectorized128w2(vec,32));
}

TEST(Test_Dotprod128w2x64,dot_product_vectorized128w2){
    int vec[64];
    for (int i=0;i<64;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,64),dot_product_vectorized128w2(vec,64));
}

TEST(Test_Dotprod128w2x100,dot_product_vectorized128w2){
    int vec[100];
    for (int i=0;i<100;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,100),dot_product_vectorized128w2(vec,100));
}

TEST(Test_Dotprod128w2x1024,dot_product_vectorized128w2){
    int vec[1024];
    for (int i=0;i<1024;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,1024),dot_product_vectorized128w2(vec,1024));
}


/*Test for dot product vectorized third way function*/
TEST(Test_Dotprod128w3x4,dot_product_vectorized128w3){
    float vec[4];
    for (int i=0;i<4;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,4),dot_product_vectorized128w3(vec,4));
}

TEST(Test_Dotprod128w3x8,dot_product_vectorized128w3){
    float vec[8];
    for (int i=0;i<8;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,8),dot_product_vectorized128w3(vec,8));
}

TEST(Test_Dotprod128w3x16,dot_product_vectorized128w3){
    float vec[16];
    for (int i=0;i<16;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,16),dot_product_vectorized128w3(vec,16));
}

TEST(Test_Dotprod128w3x32,dot_product_vectorized128w3){
    float vec[32];
    for (int i=0;i<32;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,32),dot_product_vectorized128w3(vec,32));
}

TEST(Test_Dotprod128w3x64,dot_product_vectorized128w3){
    float vec[64];
    for (int i=0;i<64;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,64),dot_product_vectorized128w3(vec,64));
}

TEST(Test_Dotprod128w3x100,dot_product_vectorized128w3){
    float vec[100];
    for (int i=0;i<100;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,100),dot_product_vectorized128w3(vec,100));
}


TEST(Test_Dotprod128w3x1024,dot_product_vectorized128w3){
    float vec[1024];
    for (int i=0;i<1024;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<float>(vec,1024),dot_product_vectorized128w3(vec,1024));
}

/*Test for dot product vectorized 256i function*/
TEST(Test_Dotprod256w1x8,dot_product_vectorized256iw1){
    int vec[8];
    for (int i=0;i<8;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,8),dot_product_vectorized256iw1(vec,8));
}

TEST(Test_Dotprod256w1x16,dot_product_vectorized256iw1){
    int vec[16];
    for (int i=0;i<16;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,16),dot_product_vectorized256iw1(vec,16));
}

TEST(Test_Dotprod256w1x32,dot_product_vectorized256iw1){
    int vec[32];
    for (int i=0;i<32;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,32),dot_product_vectorized256iw1(vec,32));
}

TEST(Test_Dotprod256iw1x64,dot_product_vectorized256iw1){
    int vec[64];
    for (int i=0;i<64;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,64),dot_product_vectorized256iw1(vec,64));
}


TEST(Test_Dotprod256w1x1024,dot_product_vectorized256iw1){
    int vec[1024];
    for (int i=0;i<1024;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,1024),dot_product_vectorized256iw1(vec,1024));
}

/*Test for dot product vectorized 256i function*/
TEST(Test_Dotprod256w2x8,dot_product_vectorized256iw2){
    int vec[8];
    for (int i=0;i<8;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,8),dot_product_vectorized256iw2(vec,8));
}

TEST(Test_Dotprod256w2x16,dot_product_vectorized256iw2){
    int vec[16];
    for (int i=0;i<16;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,16),dot_product_vectorized256iw2(vec,16));
}

TEST(Test_Dotprod256w2x32,dot_product_vectorized256iw2){
    int vec[32];
    for (int i=0;i<32;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,32),dot_product_vectorized256iw2(vec,32));
}

TEST(Test_Dotprod256iw2x64,dot_product_vectorized256iw2){
    int vec[64];
    for (int i=0;i<64;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,64),dot_product_vectorized256iw2(vec,64));
}


TEST(Test_Dotprod256w1x1024,dot_product_vectorized256iw2){
    int vec[1024];
    for (int i=0;i<1024;i++){vec[i]=i;}
    ASSERT_EQ(scalar_dot_product<int>(vec,1024),dot_product_vectorized256iw2(vec,1024));
} 

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}