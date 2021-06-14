#include <iostream>
#include <time.h>
#include <vector>
#include "gtest/gtest.h"
#include "LinearAlgebraFNS.hpp"

/*Vectorized addition 128 edition tests*/
TEST(Test_Matrix_addition128x4,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (4, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (4, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (4, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (4, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,4);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<4; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x8,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (8, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (8, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (8, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (8, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,8);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<8; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x16,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (16, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (16, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (16, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (16, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,16);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<16; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x32,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (32, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (32, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (32, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (32, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,32);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<32; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x64,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (64, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (64, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (64, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (64, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,64);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<64; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x128,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (128, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (128, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (128, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (128, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,128);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<128; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x256,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (256, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (256, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (256, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (256, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,256);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<256; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x512,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (512, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (512, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (512, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (512, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,512);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<512; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x1024,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (1024, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (1024, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (1024, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (1024, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,1024);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<1024; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition128x2048,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (2048, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (2048, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (2048, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (2048, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized_add_matcpp(vec4,vec1,vec2,100,2048);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<2048; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

/*Vectorized addition 256 edition tests*/
TEST(Test_Matrix_addition256x8,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (8, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (8, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (8, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (8, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,8);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<8; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x16,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (16, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (16, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (16, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (16, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,16);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<16; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x32,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (32, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (32, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (32, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (32, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,32);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<32; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x64,vectorized_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (64, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (64, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (64, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (64, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,64);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<64; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x128,vectorized256add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (128, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (128, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (128, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (128, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,128);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<128; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x256,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (256, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (256, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (256, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (256, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,256);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<256; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x512,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (512, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (512, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (512, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (512, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,512);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<512; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x1024,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (1024, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (1024, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (1024, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (1024, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,1024);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<1024; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}

TEST(Test_Matrix_addition256x2048,vectorized256_add_matcpp){
    std::vector<std::vector<float>> vec1( 100 , std::vector<float> (2048, 3.14));
    std::vector<std::vector<float>> vec2( 100 , std::vector<float> (2048, 0.86));
    std::vector<std::vector<float>> vec3( 100 , std::vector<float> (2048, 0));
    std::vector<std::vector<float>> vec4( 100 , std::vector<float> (2048, 0));
    
    scalar_add_matrixes(vec3,vec1,vec2);
    vectorized256_add_matcpp(vec4,vec1,vec2,100,2048);
    for (int i = 0;i < 100; i++){
        for (int j = 0; j<2048; j++) {ASSERT_EQ(vec3[i][j],vec4[i][j]);}
    }
}


int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}