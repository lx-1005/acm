#include <stdio.h>
#include <string.h>

void* memmove(void* dest, const void* src, size_t n) {
    char * d  = (char*)dest;
    const char * s = (const char*)src;
  
    if (s>d) {
        while (n--) *d++ = *s++;
    }
    else if (s<d) {
        d = d+n-1;
        s = s+n-1;
        while (n--) *d-- = *s--;
    }
	
    return dest;
}

int main() {
    char src[] = "lixuhahaah";
 
    

    printf("%s\n", (char*)memmove(src + 3, src, 6));


    return 0;
}
