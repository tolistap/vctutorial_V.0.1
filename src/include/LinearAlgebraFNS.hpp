#include<iostream>
#include<vector>
void print_vector(std::vector<std::vector<float>> m1, const int n, const int m);

/*Matrix addition functions*/
template<typename T>
void scalar_add_matrixes(std::vector<std::vector<T>>& vec3, std::vector<std::vector<T>> vec1, std::vector<std::vector<T>> vec2){
    for (int i=0; i<(int)vec1.size(); i++){
       for (int j=0; j<(int)vec1[0].size(); j++){ vec3[i][j] = vec1[i][j] + vec2[i][j];}
    }
}
void vectorized_add_matcpp(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m);
void vectorized256_add_matcpp(std::vector<std::vector<float>> &m3, std::vector<std::vector<float>> &m1, std::vector<std::vector<float>> &m2, const int n, const int m);

/*Matrix multiplication functions*/
template<typename T>
void scalar_mul_matrixes(std::vector<std::vector<T>>& vec3, std::vector<std::vector<T>> vec1, std::vector<std::vector<T>> vec2){
    for(int i = 0; i < (int)vec1.size(); i++){
        for(int j = 0; j < (int)vec1[0].size(); j++){
            for (int l = 0; l< (int)vec1[0].size(); l++){vec3[i][j] += vec1[i][l]*vec2[l][j];}
        }
    }
}

void vectorized128_mul_matcpp(std::vector<std::vector<int>> &m3, std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, const int n, const int k, const int m);

/*Matrix Transposion function*/
template<typename T>
std::vector<std::vector<T>> scalar_transpose(std::vector<std::vector<T>> m1){
    std::vector<std::vector<T>> tr((int)m1[0].size(), std::vector<T> ((int)m1.size(), 0));
      for(int i = 0; i < (int)m1.size(); i++){
        for(int j = 0; j < (int)m1[0].size(); j++){
           tr[j][i] = m1[i][j];
        } 
    }
    return tr;
}
std::vector<std::vector<int>> vectorized128i_transpose_mat4x4(std::vector<std::vector<int>> m1);
std::vector<std::vector<int>> vectorized128i_transpose_mat8x8(std::vector<std::vector<int>> m1);
std::vector<std::vector<float>> vectorized128_transpose_mat4x4(std::vector<std::vector<float>> m1);
std::vector<std::vector<float>> vectorized256_transpose_matcpp(std::vector<std::vector<float>> m1, const int n, const int m);