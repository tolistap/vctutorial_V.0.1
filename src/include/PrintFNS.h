#include <immintrin.h>
#include<vector>

void print_vectorchr(std::vector<char> vec);
void print_vector(std::vector<float> vec);
void print_matrix(std::vector<std::vector<float>> m1);
void print_matrixint(std::vector<std::vector<int>> m1);
void print_m128i_hex16x8(const char *label, __m128i vector);
void print_m128i_hex8x16(const char *label, __m128i vector);
void print_m128i_hex4x32(const char *label, __m128i vector);
void print_m128i_hex2x64(const char *label, __m128i vector);
void print_vec128i(__m128i f);
void print_m128_hex16x8(const char *label, __m128 vector);
void print_m128_hex(const char *label, __m128 vector);
void print_vec128(__m128 f);
void print_vec256(__m256 f);
void print_vechex256(__m256 f);
void print_vec256i(__m256i f);
void print_vechex256i(__m256i f);
void print_m256i_hex32x8(const char *label, __m256i vector);
void print_m256i_hex16x16(const char *label, __m256i vector);
void print_m256i_hex8x32(const char *label, __m256i vector);
void print_m256i_hex4x64(const char *label, __m256i vector);