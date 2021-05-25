/*In this file memchr function was vectorized with diferend aproaches as they will be 
  descruped during their bulid.
*/


#include<string.h>
#include<immintrin.h>
#include<iostream>

void *scalar_memchr(const void *s, int c, size_t n){
    register char *sp=(char *)s;
    for (int i=0;i<n;i++){
        if (sp[i]==c){
            return sp+i;
        }
    }
    return NULL;
}

void *vectorized_memchrw1(const void *s, int c, size_t n){
    register char *sp=(char *)s;
    __m128i t = _mm_set1_epi8(c);
    
    for (int i=0;i<n;i+=16){
        __m128i f = _mm_loadu_si128((__m128i*)&sp[i]);
        __m128i m = _mm_cmpeq_epi8(f,t);  
        register int mask = _mm_movemask_epi8(m);
        if (mask!=0){return &sp[i]+__builtin_ctzl(mask);}
    }
    return NULL;
}

void *vectorized_memchrw2(const void *s, int c, size_t n){
    register char *sp=(char *)s;
    __m128i t = _mm_set1_epi8(c);
    for (int i=0;i<n;i+=16){
        __m128i f =_mm_loadu_si128((__m128i*)&sp[i]);
        register int index = _mm_cmpistri(f,t,_SIDD_CMP_EQUAL_EACH);
        if (index!=16){return &sp[i]+index;}
    }    
    return NULL;
}

void *vectorized_memchr256(const void *s, int c, size_t n){
    register char *sp=(char *)s;
    __m256i t = _mm256_set1_epi8(c);
    /*edw ithele 8 kai oxi 32 giati einai char kai oxi integer
      giati ton char 0073 tha ton sigrinei me ena char 0073 pou
      sigrinei s->s  an to kanw me 16 tha sigrinei to 00730073 me
      to 00690073 pou einai is->ss kai den tha vrei isotita*/   
    for (int i=0;i<n;i+=32){
        __m256i f = _mm256_lddqu_si256((__m256i*)&sp[i]);
        __m256i m = _mm256_cmpeq_epi8(f,t);
        register int mask = _mm256_movemask_epi8(m);
        if (mask !=0){return &sp[i]+__builtin_ctzl(mask);}
    }    
    return NULL;
}

