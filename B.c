#include<stdio.h>
int pell[1000001];
int main() {
	unsigned n;
    scanf("%u",&n);
    for(unsigned j=1;j<=n;j++) {
		unsigned k;
        scanf("%u",&k);
        pell[1]=1; 
        pell[2]=2;
        for(unsigned i=3;i<=k;i++) {
			pell[i]=pell[i-2]+2*pell[i-1];
            pell[i]%=32767;
        }
        printf("%d",pell[k]);
	}
	return 0;
}
