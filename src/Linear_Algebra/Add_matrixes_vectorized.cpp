#include<iostream>
#include<vector>
#include<immintrin.h>
#include"PrintFNS.h"

/*In this code file a function for matrix additions vectorized with 2 methods.
  128 version with a 128bits vectors and 256 version with 256bits vectors
*/


/*This method adds two matrixes based in cpp vectors objects*/
void scalar_add_matcpp(std::vector<std::vector<float>> &m3 ,std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){m3[i][j]=m1[i][j]+m2[i][j];} 
    }
}
/*The method to add two matrixes is simple, according to linear algebra first must have the same dimensions
  Asuming the matrixes A and B:

  A = [1, 2, 3, 4          B = [1, 2, 3, 4
       5, 6, 7, 8               5, 6, 7, 8
       9, 10, 11, 12            9, 10, 11 ,12
       13, 14, 15, 16]          13, 14, 15, 16]
  
  The fist element[0][0] of C matrix will be 1+1 = 2 
  
  Vectorized methods are taking 4 elements(128bits) or 8 elements(256 bits) and appling addition
  via _mm_add_ps and _mm256_ad_ps intrinsicts.
  */
 
/*This function is the vectorized 128bits methods witch implements matrix addition*/
void vectorized_add_matcpp(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j+=4){
            /*The _mm_loadu_ps intrinsict loads 128bits(4 floats) in a vector*/
            __m128 c1= _mm_loadu_ps(&m1[i][j]);
            __m128 c2= _mm_loadu_ps(&m2[i][j]);
            /*The _mm_add_ps intrinsict add two 128bits vectors.
              Actualy, adds packed single-precision (32-bit) floating-point 
              elements in a and b, and store the results in dst.*/
            __m128 add = _mm_add_ps(c1,c2);
            /*The _mm_storeu_ps stores a 128bits vector(4 floats in a array or matrix)*/
            _mm_storeu_ps(&m3[i][j],add);
        } 
    }
}


/*This function is the vectorized 256bits methods witch implements matrix addition*/
void vectorized256_add_matcpp(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m){
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j+=8){ 
            /*The _mm256_loadu_ps intrinsict loads 256bits(8 floats) in a vector*/
            __m256 c1= _mm256_loadu_ps(&m1[i][j]);
            __m256 c2= _mm256_loadu_ps(&m2[i][j]);
            /*The _mm_add_ps intrinsict add two 256bits vectors.
              Actualy, adds packed single-precision (32-bit) floating-point 
              elements in a and b, and store the results in dst.*/
            __m256 add = _mm256_add_ps(c1,c2);
            /*The _mm_storeu_ps stores a 256bits vector(8 floats in a array or matrix)*/
            _mm256_storeu_ps(&m3[i][j],add);
        } 
    }
}




