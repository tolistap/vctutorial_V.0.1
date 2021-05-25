#include <iostream>
#include<immintrin.h>
#include <stdlib.h>
#include<vector>

void print_vectorchr(std::vector<char> vec){
  for(int i=0; i<vec.size(); i++){std::cout<<vec[i]<<", ";}std::cout<<std::endl;
}
void print_vector(std::vector<float> vec){
  for(int i=0; i<vec.size(); i++){std::cout<<vec[i]<<", ";}std::cout<<std::endl;
}

void print_matrix(std::vector<std::vector<float>> m1){
    for(int i = 0; i < m1.size(); i++){
        for(int j = 0; j < m1[0].size(); j++){std::cout << m1[i][j] << " ";} 
        std::cout<< std::endl;
    }
}

void print_matrixint(std::vector<std::vector<int>> m1){
    for(int i = 0; i < m1.size(); i++){
        for(int j = 0; j < m1[0].size(); j++){std::cout << m1[i][j] << " ";} 
        std::cout<< std::endl;
    }
}


/*Plot _m128i vectors*/
void print_m128i_hex16x8(const char *label, __m128i vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint8_t  data[16];
  /*Store vector's data in data array*/
  _mm_storeu_si128((__m128i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<16; i++){
      printf("%02x ", data[i]);
    } 
    printf("\n");
}

void print_m128i_hex8x16(const char *label, __m128i vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint16_t  data[8];
  /*Store vector's data in data array*/
  _mm_storeu_si128((__m128i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<8; i++){
      printf("%04x ", data[i]);
    } 
    printf("\n");
}


void print_m128i_hex4x32(const char *label, __m128i vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint32_t  data[4];
  /*Store vector's data in data array*/
  _mm_storeu_si128((__m128i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<4; i++){
      printf("%08x ", data[i]);
    } 
    printf("\n");
}

void print_m128i_hex2x64(const char *label, __m128i vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint64_t  data[2];
  /*Store vector's data in data array*/
  _mm_storeu_si128((__m128i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<2; i++){
      printf("%016x ", data[i]);
    } 
    printf("\n");
}

void print_vec128i(__m128i f){
   int32_t vec[4];
   std::cout<<"__m128i= "; 
   _mm_storeu_si128((__m128i*)vec,f);
  for (int i=0; i<4; i++){
   std::cout<<std::dec<<vec[i]<<" ";
  }
  std::cout<<std::endl;
}

/*Print _m128 vectors*/
void print_m128_hex16x8(const char *label, __m128 vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  float  data[4];
  /*Store vector's data in data array*/
  _mm_storeu_si128((__m128i*)data, _mm_castps_si128(vector));
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<4; i++){
      printf("%02x ", data[i]);
    } 
    printf("\n");
}


void print_m128_hex(const char *label, __m128 vector) {
  /**/
  float  data[4];
    _mm_storeu_ps(data, vector);
    printf("%s: ", label);
    for(int i=0; i<4; i++){
      printf("%08x ", data[i]);
    } 
    printf("\n");
}

void print_vec128(__m128 f){
   float vec[4];
   std::cout<<"__m128= ";
   _mm_storeu_ps(vec,f);
  for (int i=0; i<4; i++){
   std::cout<<std::dec<<vec[i]<<" ";
  }
  std::cout<<std::endl;
}


/*Print _m256*/
void print_vec256(__m256 f){
    float vec[8];
    std::cout<<"__m256= ";
    _mm256_storeu_ps(vec,f);
  for (int i=0; i<8; i++){
     std::cout<<std::dec<<vec[i]<<" ";
  }
  std::cout<<std::endl;
}

void print_vechex256(__m256 f){
    int32_t vec[8];
    std::cout<<"__m256 Hex= "<<std::hex;
    _mm256_storeu_si256((__m256i *)vec, (__m256i)f);
  for (int i=0; i<8; i++){
     std::cout<<std::hex<<vec[i]<<" ";
  }
  std::cout<<std::endl<<std::dec;
  
}

void print_vec256i(__m256i f){
    int vec[8];
    std::cout<<"__m256i= ";
    _mm256_storeu_si256((__m256i *)vec,f);
  for (int i=0; i<8; i++){
     std::cout<<std::dec<<vec[i]<<" ";
  }
  std::cout<<std::endl;
}


void print_vechex256i(__m256i f){
    int32_t vec[8];
    std::cout<<"__m256i Hex= ";
    _mm256_storeu_si256((__m256i *)vec,f);
  for (int i=0; i<8; i++){
     std::cout<<std::hex<<vec[i]<<" ";
  }
  std::cout<<std::endl<<std::dec;
}

void print_m256i_hex32x8(const char *label, __m256i vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint8_t  data[32];
  /*Store vector's data in data array*/
  _mm256_storeu_si256((__m256i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<32; i++){
      printf("%02x ", data[i]);
    } 
    printf("\n");
}

void print_m256i_hex16x16(const char *label, __m256i vector){
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint16_t  data[16];
  /*Store vector's data in data array*/
  _mm256_storeu_si256((__m256i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<16; i++){
      printf("%04x ", data[i]);
    } 
    printf("\n");
}

void print_m256i_hex8x32(const char *label, __m256i vector) {
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint32_t  data[8];
  /*Store vector's data in data array*/
  _mm256_storeu_si256((__m256i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<8; i++){
      printf("%08x ", data[i]);
    } 
    printf("\n");
}


void print_m256i_hex4x64(const char *label, __m256i vector){
  /*Define an array with width of exacly 16 bits respectively
    with no padding bits and using 2's complement for negative
    values*/
  uint64_t  data[4];
  /*Store vector's data in data array*/
  _mm256_storeu_si256((__m256i*)data, vector);
  /*Start Printing*/ 
    printf("%s: ", label);
    for(int i=0; i<4; i++){
      printf("%016x ", data[i]);
    } 
    printf("\n");
}