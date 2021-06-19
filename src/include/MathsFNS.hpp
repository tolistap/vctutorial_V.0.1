#include<iostream>

/*min max Functions*/
template<typename T>
T scalar_max(T* ptr, int n){
    register T max=ptr[0];
    for (int i=1;i<n;i++){if (max<ptr[i]){max=ptr[i];}}    
    return max;
}

template<typename T>
T scalar_min(T* ptr, int n){
    register T min=ptr[0];
    for (int i=1;i<n;i++){if (min>ptr[i]){min=ptr[i];}}
    return min;
}

float max_vectorized128(float* ptr,int n);
float min_vectorized128(float* ptr,int n);
float max_vectorized256(float* ptr,int n);
float min_vectorized256(float* ptr,int n);

/*Comparisons Functions*/
bool classic_comparison(const float *vec1,const float *vec2, const int n);
bool comparison_vectorized128(const float* vec1, const float* vec2 , const int n);
bool comparison_vectorized256(const float* vec1, const float* vec2 , const int n);

/*Dotproduct Functions*/
template <typename T>
T scalar_dot_product(const T* vec, int n){
    register T dot_pr=0;
    for(int i=0;i<n;i++){dot_pr+=vec[i]*vec[i];}
    return dot_pr;
}   

float sum_vec(const float* v, const int n);
int32_t dot_product_vectorized128w1(const int* vec, const int n);
int32_t dot_product_vectorized128w2(const int* vec, const int n);
float dot_product_vectorized128w3(const float* vec, const int n);
int32_t dot_product_vectorized256iw1(const int * vec, const int n);
int32_t dot_product_vectorized256iw2(const int * vec, const int n);

uint8_t Lshift(void * ptr, unsigned int n);