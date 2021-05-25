#include<iostream>
#include<immintrin.h>
#include"PrintFNS.h"

/*In this code file a function for dot product calculation was vectorized with 3 methods.
  128 version with a 128bits vectors and 256 version with 256bits vectors.
*/

/* Union typedefs was declared with aim to trick the compiler to see 
   a vector as a 4 or 8 elements array (note: only for this case because 
   the data are integers and floats) with aim to avoid unnecessary stores.
   Prefared not to use const in declerations because the data will be restored 
   in the same array/vector.
*/
typedef union uni128i{__m128i f; int32_t vec[4];} u128i;
typedef union uni128{__m128 f; float vec[4];} u128;
typedef union uni256i{__m256i f; int32_t vec[8];} u256i;


/*scalar version for integer values*/
int32_t scalar_dot_int_product(const int* vec, const int n){
    register int32_t dot_pr=0;
    for(int i=0;i<n;i++){dot_pr+=vec[i]*vec[i];}
    return dot_pr;    
}

/*scalar version for float values*/
float scalar_dot_f_product(const float* vec, const int n){
    register float dot_pr=0;
    for(int i=0;i<n;i++){dot_pr+=vec[i]*vec[i];}
    return dot_pr;    
}


/*First way. In this case the intirict _mm_hadds_epi32() was used.*/
int32_t dot_product_vectorized128w1(const int* vec, const int n){
    uni128i dot_prod;
    __m128i hadd;
    register int32_t sum=0;
    for (int i=0; i<n;i+=4){
        dot_prod.f = _mm_loadu_si128((__m128i*)&vec[i]);
        dot_prod.f= _mm_mullo_epi32(dot_prod.f,dot_prod.f);
        hadd = _mm_hadd_epi32(dot_prod.f,dot_prod.f);
        dot_prod.f = _mm_hadd_epi32(hadd,hadd);
        sum+=dot_prod.vec[0];
    }
    return sum;
}

/*Second way. In this case _mm_hadds_epi32() was not used, the aproach 
  of this case are the same with the scalar method with the following steps:

  First, a vectro was created for the first 4 elements of array vec.
  Second, the elements was raided in the power of 2.
  Third, the elements was shifted.
  Fourth, the elements was added.
  Fifth, the elements was shifted again.
*/

int32_t dot_product_vectorized128w2(const int* vec, const int n){
    uni128i dot_prod;
    register int32_t sum=0;
    __m128i n1;
    for (int i=0; i<n;i+=4){
        dot_prod.f = _mm_loadu_si128((__m128i*)&vec[i]);
        //std::cout<<"proti tetrada:"<<std::endl;
        //print_vec128i(dot_prod.f);
        /*Multiply the first four with his self*/
        dot_prod.f = _mm_mullo_epi32(dot_prod.f,dot_prod.f);
        //std::cout<<"tetrada polaplasiasmeni me ton eauto tis:"<<std::endl;
        //print_vec128i(dot_prod.f);
        n1=_mm_slli_si128(dot_prod.f,4);
        //std::cout<<"tetrada meta to shift:"<<std::endl;
        //print_vec128i(n1);   
        dot_prod.f = _mm_add_epi32(dot_prod.f,n1);
        //std::cout<<"tetrada meta tin prostesi:"<<std::endl;
        //print_vec128i(dot_prod.f);
        n1=_mm_slli_si128(dot_prod.f,8);
        //std::cout<<"tetrada meta ton shift:"<<std::endl;
        //print_vec128i(n1);
        dot_prod.f = _mm_add_epi32(dot_prod.f,n1);
        //std::cout<<"tetrada meta tin prostesi:"<<std::endl;
        //print_vec128i(dot_prod.f);
        sum+=dot_prod.vec[3];
        //sum = _mm_cvtss_f32(dot_prod.f);
    }
    return sum;
}

/*Thired way. In this case the intirict _mm_dp_ps was used.*/
float dot_product_vectorized128w3(const float* vec, const int n){
    u128 dot_prod;  
    register float sum=0;
    for (int i=0; i<n; i+=4){
    dot_prod.f = _mm_loadu_ps(&vec[i]);
    dot_prod.f = _mm_dp_ps(dot_prod.f,dot_prod.f,0xff);
    sum+=dot_prod.vec[0];
    }
    return sum;
}


int32_t dot_product_vectorized256iw1(const int * vec, const int n){
    uni256i dot_prod;
    uni128i x1;
    register int32_t sum=0;
    __m256i n1;
    for (int i=0; i<n;i+=8){
        dot_prod.f = _mm256_loadu_si256((__m256i*)&vec[i]);
        //std::cout<<"proti oktada:"<<std::endl;
        //print_vec256i(dot_prod.f);
        /*Multiply the first four with his self*/
        dot_prod.f = _mm256_mullo_epi32(dot_prod.f,dot_prod.f);
        //std::cout<<"oktada polaplasiasmeni me ton eauto tis:"<<std::endl;
        //print_vec256i(dot_prod.f);
        n1=_mm256_alignr_epi8(dot_prod.f,dot_prod.f,4);
        //std::cout<<"oktada meta to prwto shift:"<<std::endl;
        //print_vec256i(n1);   
        dot_prod.f = _mm256_add_epi32(dot_prod.f,n1);
        //std::cout<<"okatda meta tin prostesi:"<<std::endl;
        //print_vec256i(dot_prod.f);
        n1=_mm256_alignr_epi8(dot_prod.f,dot_prod.f,8);
        //std::cout<<"oktada meta deutero to shift:"<<std::endl;
        //print_vec256i(n1);   
        dot_prod.f = _mm256_add_epi32(dot_prod.f,n1);
        //std::cout<<"okatda meta tin prostesi:"<<std::endl;
        //print_vec256i(dot_prod.f);
        x1.f = _mm256_extracti128_si256(dot_prod.f, 0);
        __m128i x2 = _mm256_extracti128_si256(dot_prod.f, 1);
        //print_vec128i(x1.f);
        //print_vec128i(x2); 
        x1.f = _mm_add_epi16(x1.f,x2);
        //print_vec128i(x1.f);
        sum+=x1.vec[0];
    }
    
    return sum;
}

/*In the second case the vectors splits and then the 128i vectorized way used*/
int32_t dot_product_vectorized256iw2(const int * vec, const int n){
    uni256i dot_prod;
    uni128i x1,x2;
    register int32_t sum=0;
    for (int i=0; i<n;i+=8){
        dot_prod.f = _mm256_loadu_si256((__m256i*)&vec[i]);
        x1.f = _mm256_extracti128_si256(dot_prod.f, 0);
        x2.f = _mm256_extracti128_si256(dot_prod.f, 1);
        sum+=dot_product_vectorized128w2(x1.vec,4) + dot_product_vectorized128w2(x2.vec,4);
    }
    
    return sum;
}