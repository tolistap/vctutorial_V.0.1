#include <string.h>

/*Memory chr functions*/
//void *scalar_memsetcpp(std::vector<char>*s, int c, size_t n); // προσπαθησα να το περασω ετσι
void *scalar_memchr(const void *s, int c, size_t n);
void *vectorized_memchrw1(const void *s, int c, size_t n);
void *vectorized_memchrw2(const void *s, int c, size_t n);
void *vectorized_memchr256(const void *s, int c, size_t n);

/*Memory set functions*/
void *scalar_memset(void *s, int c, size_t n);
void *vectorized_memset128i(void *s, int c, size_t n);
void *vectorized_memset256i(void *s, int c, size_t n);

/*Memory cpy functions*/
void *scalar_memcpy(void *dest, const void *src, size_t n);
void *vectorized_memcpy128i(void *dest, const void *src, size_t n);