#include<iostream>
#include<vector>
#include<immintrin.h>

/*In this code file a function for matrix transposure vectorized with 1 method.
  128 version with a 128bits vectors for 4x4 matrix.
*/

/*This function is under construction.*/
std::vector<std::vector<float>> vectorized128_transpose_mat4x4(std::vector<std::vector<float>> m1){
  std::vector<std::vector<float>> tr(4, std::vector<float> (4, 0));
  __m128 c1 = _mm_loadu_ps(&m1[0][0]);
  __m128 c2 = _mm_loadu_ps(&m1[1][0]);
  __m128 c3 = _mm_loadu_ps(&m1[2][0]);
  __m128 c4 = _mm_loadu_ps(&m1[3][0]);
  /*For a 4x4 float you can use the _MM_TRANSPOSE4_PS macro witch takes 4 vectors and makes the
    tranposure and saves the new rows in given vectors. 
  */
  _MM_TRANSPOSE4_PS(c1,c2,c3,c4);
  _mm_storeu_ps(&tr[0][0],c1);
  _mm_storeu_ps(&tr[1][0],c2);
  _mm_storeu_ps(&tr[2][0],c3);
  _mm_storeu_ps(&tr[3][0],c4);
  return tr;
}

/*The vectorized matrix transposure is not trivia, generaly in SIMD there is no way(intrinsict) that allows 
  the programer to load 128 or 256 data from matrixes columns. Thus the programer must find new methods to 
  approach the problem. One solution proposed is by packing vectors bits via _mm_unpacklo_epi32 and 
  _mm_unpacklo_epi64 intrisicts
  In the code bellow a 4x4 matrix transposed via the intrinsicts mentoined. 
  */
std::vector<std::vector<int>> vectorized128i_transpose_mat4x4(std::vector<std::vector<int>> m1){
    std::vector<std::vector<int>> tr(m1.size(), std::vector<int> (m1[0].size(), 0));
      /*The _mm_loadu_si128 intrinsict loads 128bits(4 integers) in a vector*/
      __m128i c1 = _mm_loadu_si128((__m128i*)&m1[0][0]);
      __m128i c2 = _mm_loadu_si128((__m128i*)&m1[1][0]);
      __m128i c3 = _mm_loadu_si128((__m128i*)&m1[2][0]);
      __m128i c4 = _mm_loadu_si128((__m128i*)&m1[3][0]);
      /*Now we actualy have the all the 4x4 matrix like:
        c1 = 1,2,3,4
        c2 = 5,6,7,8
        c3 = 9,10,11,12
        c4 = 13,14,15,16
      */
       /*Via _mm_unpacklo_epi_16 and _mm_unpacklo_epi32 intrinsict a new vectro created witch 
       contains the two lowest bits(first and second element) of the vectors was given. 
       Actualy, unpack and interleave 16-bit or 32-bits integers from the high half of a and b, 
       and store the results in dst. */
      __m128i t0 = _mm_unpacklo_epi32(c1,c2);
      /*Thus, the t0 vector will be t0 = 1,5,2,6*/
      __m128i t1 = _mm_unpackhi_epi32(c1,c2);
      /*Thus, the t1 vector will be t1 = 3,7,4,8*/
      __m128i t2 = _mm_unpacklo_epi32(c3,c4);
      /*Thus, the t2 vector will be t2 = 9,13,10,14*/
      __m128i t3 = _mm_unpackhi_epi32(c3,c4);
      /*Thus, the t3 vector will be t3 = 11,15,12,16*/
      __m128i r0 = _mm_unpacklo_epi64(t0,t2); 
      /*Thus, the r0 vector will be r0 = 1,5,9,13*/
      __m128i r1 = _mm_unpackhi_epi64(t0,t2);
      /*Thus, the r1 vector will be r1 = 2,6,10,14*/
      __m128i r2 = _mm_unpacklo_epi64(t1,t3);
      /*Thus, the r2 vector will be r2 = 4,8,12,16*/
      __m128i r3 = _mm_unpackhi_epi64(t1,t3);
      /*Thus, the whole matrix transosed.*/
      _mm_storeu_si128((__m128i*)&tr[0][0],r0);
      _mm_storeu_si128((__m128i*)&tr[1][0],r1);
      _mm_storeu_si128((__m128i*)&tr[2][0],r2);
      _mm_storeu_si128((__m128i*)&tr[3][0],r3); 
    return tr;
}

std::vector<std::vector<int>> vectorized128i_transpose_mat8x8(std::vector<std::vector<int>> m1){
    std::vector<std::vector<int>> tr(m1.size(), std::vector<int> (m1[0].size(), 0));
      __m256i c1 = _mm256_lddqu_si256((__m256i*)&m1[0][0]);
      __m256i c2 = _mm256_lddqu_si256((__m256i*)&m1[1][0]);
      __m256i c3 = _mm256_lddqu_si256((__m256i*)&m1[2][0]);
      __m256i c4 = _mm256_lddqu_si256((__m256i*)&m1[3][0]);
      __m256i c5 = _mm256_lddqu_si256((__m256i*)&m1[4][0]);
      __m256i c6 = _mm256_lddqu_si256((__m256i*)&m1[5][0]);
      __m256i c7 = _mm256_lddqu_si256((__m256i*)&m1[6][0]);
      __m256i c8 = _mm256_lddqu_si256((__m256i*)&m1[7][0]);
      
      __m256i t0 = _mm256_unpacklo_epi32(c1,c2);
      __m256i t1 = _mm256_unpackhi_epi32(c1,c2);
      
      __m256i t2 = _mm256_unpacklo_epi32(c3,c4);
      __m256i t3 = _mm256_unpackhi_epi32(c3,c4);
      
      __m256i t4 = _mm256_unpacklo_epi32(c5,c6);
      __m256i t5 = _mm256_unpackhi_epi32(c5,c6);
      
      __m256i r0 = _mm256_unpacklo_epi64(t0,t2); 
      __m256i r1 = _mm256_unpackhi_epi64(t0,t2);
      
      __m256i r2 = _mm256_unpacklo_epi64(t1,t3);
      __m256i r3 = _mm256_unpackhi_epi64(t1,t3);

      __m256i r4 = _mm256_unpackhi_epi64(t3,t5);
      __m256i r5 = _mm256_unpacklo_epi64(t3,t5);

      _mm256_storeu_si256((__m256i*)&tr[0][0],r0);
      _mm256_storeu_si256((__m256i*)&tr[1][0],r1);
      _mm256_storeu_si256((__m256i*)&tr[2][0],r2);
      _mm256_storeu_si256((__m256i*)&tr[3][0],r3);
      _mm256_storeu_si256((__m256i*)&tr[4][0],r4);
      _mm256_storeu_si256((__m256i*)&tr[5][0],r5); 
    return tr;
}