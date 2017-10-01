#include <stdio.h>
unsigned long long buffer[31];
unsigned long long f(unsigned n) {
    if(n == 1)
            return 1;
    else if(n == 2)
            return 2;
    if(buffer[n] == -1) {
        buffer[n] = f(n-1) + f(n-2);
    }   
    return buffer[n];
}
int main(void){
    for(unsigned i=0;i<31;++i)
            buffer[i] = -1; 
    unsigned i;
    while(scanf("%u",&i) != EOF) {
        printf("%llu\n",f(i));
    }   
    return 0;
}
