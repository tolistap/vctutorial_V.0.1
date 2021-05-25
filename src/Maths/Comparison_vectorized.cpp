/*In this file comparisons was made and vectorized with diferend aproaches as they will be 
  descruped during their bulid.
*/
#include <iostream>
#include <immintrin.h> 

bool classic_comparison(const float *vec1,const float *vec2, const int n){
    bool are_equal=true;
    int i=0;
    while (are_equal && i<n){if (vec1[i]!=vec2[i]){are_equal=false;}i++;}   
    return are_equal;
}

/*128 vectorized version, this version was writen with aim to see how cmpeq and
  movemask inttisicts was work.*/
bool comparison_vectorized128(const float* vec1, const float* vec2 , const int n){
    int i=0;
    /*Loads a 16_byte or 128bits registation (first 4 data) 
    to a variabe f using the _mm_loadu_ps instrict */ 
    while (i<n){
        __m128 loc_vec1 = _mm_loadu_ps(&vec1[i]);
        __m128 loc_vec2 = _mm_loadu_ps(&vec2[i]);
        __m128 eq= _mm_cmpeq_ps(loc_vec1,loc_vec2);
        register int mask = _mm_movemask_ps(eq);
        if (mask!=15){
            return false;
        }
        i+=4;
    }
    return true;
}

/*256 vectorized version, this version was writen with aim to see how cmpeq256 and
  movemask256 inttisicts was work.*/
bool comparison_vectorized256(const float* vec1, const float* vec2 , const int n){
    bool are_equal=true;
    int i=0;
    while (are_equal && i<n){
        __m256 loc_vec1 = _mm256_loadu_ps(&vec1[i]);
        __m256 loc_vec2 = _mm256_loadu_ps(&vec2[i]);
        __m256i eq= _mm256_cmpeq_epi64(_mm256_castps_si256(loc_vec1),_mm256_castps_si256(loc_vec2));
        register int mask = _mm256_movemask_ps(_mm256_castsi256_ps(eq));
        if (mask!=255){
            return false;
        }
        i+=8;
    }
    return true;
}

