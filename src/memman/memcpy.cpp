#include<string.h>
#include<stdint.h>
#include<iostream>
#include<immintrin.h>
#include"PrintFNS.h"

void *scalar_memcpy(void *dest, const void *src, size_t n){
    register char *d=(char *)dest;
    register const char *s=(char *)src;
    for (int i=0;i<n;i++){d[i]=s[i];}
    return dest;
}

void *vectorized_memcpy128i(void *dest, const void *src, size_t n){
    register char *d=(char *)dest;
    register const char *s=(char *)src;
    register size_t len=n;
    register int n1 = ((intptr_t)s & 0xF);
    register int n2 = ((intptr_t)d & 0xF);
    
    
    /*
    std::cout<<"function n1 = "<<n1<<" ~ "<<std::hex<<(intptr_t)d<<std::endl;
    std::cout<<"function n2 = "<<n2<<" ~ "<<(intptr_t)s<<std::dec<<std::endl;
    */

    if (n2!= 0) {
        /* unaligned pre-pass */
        scalar_memcpy(d,s,16-n1);
        s+=16-n2;
        d+=16-n2;
        len-=n2;
    }
    
    /*
    __m128i kk = _mm_set_epi8(s[cpos+15],s[cpos+14],s[cpos+13],s[cpos+12],s[cpos+11],s[cpos+10],s[cpos+9],s[cpos+8],s[cpos+7],s[cpos+6],s[cpos+5],s[cpos+4],s[cpos+3],s[cpos+2],s[cpos+1],s[cpos]);
    print_m128i_hex16x8("kk",kk);
    */

   register int k = len/16;
   for (int i=0;i<k;i++){
        _mm_store_si128((__m128i*)d, _mm_loadu_si128((__m128i*)s));
        s+=16;
        d+=16;
    }

    len-=k*16;
    if (len !=0){
        scalar_memcpy(d,s,len);
    }

    return d;
}