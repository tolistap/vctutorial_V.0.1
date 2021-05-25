#include<iostream>
#include<vector>
void print_vector(std::vector<std::vector<float>> m1, const int n, const int m);

/*Matrix addition functions*/
void scalar_add_matcpp(std::vector<std::vector<float>> &m3 ,std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m);
void vectorized_add_matcpp(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m);
void vectorized256_add_matcpp(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m);

/*Matrix multiplication functions*/
void scalar_mul_matint(std::vector<std::vector<int>> &m3, std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, const int n, const int k, const int m);
void scalar_mul_matfl(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int k, const int m);
void vectorized128_mul_matcpp(std::vector<std::vector<int>> &m3, std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, const int n, const int k, const int m);

/*Matrix Transposion function*/
std::vector<std::vector<int>> vectorized128i_transpose_mat4x4(std::vector<std::vector<int>> m1);
std::vector<std::vector<int>> vectorized128i_transpose_mat8x8(std::vector<std::vector<int>> m1);
std::vector<std::vector<int>> scalar_transposeint(std::vector<std::vector<int>> m1);
std::vector<std::vector<float>> scalar_transpose(std::vector<std::vector<float>> m1);
std::vector<std::vector<float>> vectorized128_transpose_mat4x4(std::vector<std::vector<float>> m1);
std::vector<std::vector<float>> vectorized256_transpose_matcpp(std::vector<std::vector<float>> m1, const int n, const int m);