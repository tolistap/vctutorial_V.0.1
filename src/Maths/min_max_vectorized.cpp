/*In this file min and max functions was vectorized with diferend aproaches as they will be 
  descruped during their bulid.
*/

#include<iostream>
#include<immintrin.h>

/* Union typedefs was declared with aim to trick the compiler to see 
   a vector as a 4 or 8 elements array (note: only for this case because 
   the data are integers and floats) with aim to avoid unnecessary stores.
   Prefared not to use const in declerations because the data will be restored 
   in the same array/vector.
*/
typedef union u128{__m128 f; float vec[4];}uni; 
typedef union u256{__m256 f; float vec[8];}uni1;


float scalar_max(float* ptr,int n){
    register float max=ptr[0];
    for (int i=1;i<n;i++){if (max<ptr[i]){max=ptr[i];}}    
    return max;
}

float scalar_min(float* ptr, int n){
    register float min=ptr[0];
    for (int i=1;i<n;i++){if (min>ptr[i]){min=ptr[i];}}
    return min;
}

/*128 vectorized version, this version was writen with aim to see how max_ps
  intrisict was work.*/
float max_vectorized128(float* ptr,int n){ 
    /*Loads a 16_byte or 128bit registation (first 4 data) 
    to a variabe f using the _mm_loadu_ps instrict */
    __m128 max_vec = _mm_loadu_ps(&ptr[0]);
     
    
    /*Caclulate 4 max elements of array ptr*/
    for (int i=4;i<n; i+=4){
        __m128 temp = _mm_loadu_ps(&ptr[i]);
        /*_mm_max_ps instrinsict calculates max bitween 2 128bit vectors.
          Actualy, compares packed single-precision (32-bit) floating-point 
          elements in a and b, and store packed maximum values in dst.
        */
        max_vec = _mm_max_ps(max_vec, temp);
    }

    /*Crate a uni value with aim to avoid an unnecessary store*/   
    uni temp_max;
    temp_max.f=max_vec;
    return scalar_max(temp_max.vec,4);
    }


/*128 vectorized version, this version was writen with aim to see how min_ps
  intrisict was work.*/
float min_vectorized128(float* ptr,int n){
    /*Loads a 16_byte or 128 bits registation (first 4 data) 
    to a variabe f using the _mm_loadu_ps instrict */
    __m128 min_vec = _mm_loadu_ps(&ptr[0]);

    /*Caclulate 4 max elements of array ptr*/
    for (int i=4;i<n; i+=4){
         __m128 temp = _mm_loadu_ps(&ptr[i]);
         /*_mm_min_ps instrinsict calculates min bitween 2 128bit vectors.
          Actualy, compares packed single-precision (32-bit) floating-point 
          elements in a and b, and store packed minimum values in dst.
        */
         min_vec = _mm_min_ps(min_vec, temp);
    }

    /*Crate a uni value with aim to avoid an unnecessary store*/ 
    uni temp_min;
    temp_min.f=min_vec;
    return scalar_min(temp_min.vec,4);
    }

/*256 vectorized version, this version was writen with aim to see how _mm256_max_ps
  intrisict was work.*/
float max_vectorized256(float* ptr,int n){ 
    /*Loads a 32_byte or 256bits registation (first 8 data) 
    to a variabe f using the _mm_loadu_ps instrict */
    __m256 max_vec = _mm256_loadu_ps(&ptr[0]);

    /*Caclulate 8 max elements of array ptr*/
    for (int i=8;i<n; i+=8){
        __m256 temp = _mm256_loadu_ps(&ptr[i]);
        /*_mm256_max_ps instrinsict calculates max bitween 2 256bit vectors.
          Actualy, compares packed single-precision (32-bit) floating-point 
          elements in a and b, and store packed maximum values in dst.
        */
        max_vec = _mm256_max_ps(max_vec, temp);
        }
        uni1 temp_max;
        temp_max.f=max_vec;
        return scalar_max(temp_max.vec,8);
}

/*256 vectorized version, this version was writen with aim to see how _mm256_min_ps
  intrisict was work.*/
float min_vectorized256(float* ptr,int n){ 
    /*Loads a 32_byte or 256bits registation (first 8 data) 
    to a variabe f using the _mm_loadu_ps instrict */
    __m256 min_vec = _mm256_loadu_ps(&ptr[0]);
    /*Caclulate 8 max elements of array ptr*/
    for (int i=8;i<n; i+=8){
        __m256 temp = _mm256_loadu_ps(&ptr[i]);
        /*_mm256_min_ps instrinsict calculates max bitween 2 256bit vectors.
          Actualy, compares packed single-precision (32-bit) floating-point 
          elements in a and b, and store packed minimum values in dst.
        */
        min_vec = _mm256_min_ps(min_vec, temp);
        }
        uni1 temp_min;
        temp_min.f=min_vec;
        return scalar_min(temp_min.vec,8);
}
