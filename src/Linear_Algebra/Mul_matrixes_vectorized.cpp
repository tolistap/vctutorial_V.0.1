#include<iostream>
#include<vector>
#include<immintrin.h>
#include"PrintFNS.h"
#include"LinearAlgebraFNS.h"
#include"MathsFNS.h"


/* Union typedefs was declared with aim to trick the compiler to see 
   a vector as a 4 or 8 elements array (note: only for this case because 
   the data are integers and floats) with aim to avoid unnecessary stores.
   Prefared not to use const in declerations because the data will be restored 
   in the same array/vector.
*/

typedef union uni128i{__m128i f; int32_t vec[4];} u128i;

/*In this code file a function for matrix multiplication vectorized with 2 methods.
  128 version with a 128bits vectors and 256 version with 256bits vectors
*/

/*This method multiplies two matrixes based in cpp vectors objects for integer type matrixes*/
void scalar_mul_matint(std::vector<std::vector<int>> &m3, std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, const int n, const int k, const int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for (int l = 0; l<k; l++){
                m3[i][j] += m1[i][l]*m2[l][j];
                }
        } 
    }
}

/*This method multiplies two matrixes based in cpp vectors objects for float type matrixes*/
void scalar_mul_matfl(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int k, const int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for (int l = 0; l<k; l++){
                m3[i][j] += m1[i][l]*m2[l][j];
                }
        } 
    }
}

/*This function is the vectorized 128bits methods witch implements matrix addition for integer types matrixes*/
void vectorized128_mul_matcpp(std::vector<std::vector<int>> &m3, std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, const int n, const int k, const int m){
    /* Assuming two matrixes, a 8x4 matrix A and a 4x4 matrix B. According to linear algebra this two matrixes multipled as following 
      A = [1, 2, 3, 4            B = [1, 2, 3, 4
           5, 6, 7, 8                 5, 6, 7, 8
           9, 10, 11, 12              9, 10, 11,12
           13, 14, 15,16              13, 14, 15, 16]
           17, 18, 19, 20
           21, 22, 23, 24
           25, 26, 27, 28
           29, 30, 31, 32]

    The furst element of vector C will be 1*1 + 2*5 + 3*9 + 4*13 = 2 + 10 + 27 + 52 = 91 
        In vectorization there is no way(intrinsict) to select matrixe's column. Because of this 
    an easy way is to transpose the B matrix and calculate the above bitween lines
    Thus, B matrix transposure are needed.
        The above "formula" is the dot product bitween the first lines of matrix A and B. Hence the
    code bellow are similar (actualy the same) with the dot product calculation. 
    */
    std::vector<std::vector<int>> tr = vectorized128i_transpose_mat4x4(m2);
    u128i dot_prod;
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){ 
            /*The _mm_loadu_si128 intrinsict loads 128bits(4 integers) in a vector*/
            __m128i c1 = _mm_loadu_si128((__m128i*)&m1[i][0]);
            __m128i c2 = _mm_loadu_si128((__m128i*)&tr[j][0]);
            /*The _mm_mullo_epi32 intrinsict multiplies per 32bits in c1 and c2 vectors
              Actualy, multiplys the packed 32-bit integers in a and b, producing intermediate 
              64-bit integers, and store the low 32 bits of the intermediate integers in dst.
            */
            dot_prod.f= _mm_mullo_epi32(c1,c2);
            /*The _mm_hadd_epi32 intrinsict adds two vectors c1 and c2 per 32 bit.
              Actualy, executes horizontally add adjacent pairs of 32-bit integers in a and b, 
              and pack the signed 32-bit results in dst.
              */
            __m128i hadd = _mm_hadd_epi32(dot_prod.f,dot_prod.f);
            dot_prod.f = _mm_hadd_epi32(hadd,hadd);
            m3[i][j] = dot_prod.vec[0];
        }
    } 
}





