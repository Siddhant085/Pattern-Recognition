#include "library.h"

void blackWhite(pi **a,unsigned long w,unsigned long h){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			unsigned char rr=a[i][j].r;
			unsigned char rg=a[i][j].g;
			unsigned char rb=a[i][j].b;
	//		printf("{%u %u %u}\n",rr,rg,rb );
			if(rr>150 && rg>150 && rb>150){
				a[i][j].r=a[i][j].b=a[i][j].g=0;
			}
			else if(rr==0 && rg==0 && rb==0){
				a[i][j].r=a[i][j].b=a[i][j].g=0;
			}
			else{
				a[i][j].r=a[i][j].b=a[i][j].g=255;
			}
		}
	}
}