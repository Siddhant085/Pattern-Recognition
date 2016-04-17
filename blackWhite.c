#include "library.h"

void blackWhite(pi **a,unsigned long w,unsigned long h){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			short rr=a[i][j].r;
			short rg=a[i][j].g;
			short rb=a[i][j].b;
			printf("{%u %u %u}\n",rr,rg,rb );
			if(rr>0 && rg>0 && rb>0){
				a[i][j].r=a[i][j].b=a[i][j].g=255;
			}
			else{
				a[i][j].r=a[i][j].b=a[i][j].g=0;
			}
		}
	}
}