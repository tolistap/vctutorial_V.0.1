#include<iostream>

/*min max Functions*/
float scalar_max(float* ptr,int n);
float scalar_min(float* ptr, int n);
float max_vectorized128(float* ptr,int n);
float min_vectorized128(float* ptr,int n);
float max_vectorized256(float* ptr,int n);
float min_vectorized256(float* ptr,int n);

/*Comparisons Functions*/
bool classic_comparison(const float *vec1,const float *vec2, const int n);
bool comparison_vectorized128(const float* vec1, const float* vec2 , const int n);
bool comparison_vectorized256(const float* vec1, const float* vec2 , const int n);

/*Dotproduct Functions*/
int32_t scalar_dot_int_product(const int* vec, const int n);
float scalar_dot_f_product(const float* vec, const int n);
float sum_vec(const float* v, const int n);
int32_t dot_product_vectorized128w1(const int* vec, const int n);
int32_t dot_product_vectorized128w2(const int* vec, const int n);
float dot_product_vectorized128w3(const float* vec, const int n);
int32_t dot_product_vectorized256iw1(const int * vec, const int n);
int32_t dot_product_vectorized256iw2(const int * vec, const int n);