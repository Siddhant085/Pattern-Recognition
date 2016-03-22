#include "library.h"

pi ** readImage(unsigned long int w,unsigned long int h,unsigned long int offset,FILE *fp,const pinfo *info){
	pi **a = (pi **)(malloc)(h*sizeof(pi *));
	for(int i=0;i<h;i++){
		a[i]=(pi *)malloc(w*sizeof(pi));
	}
	fseek(fp,offset,SEEK_SET);
	for(int i=0;i<h;i++){
		assert(i>=0 && i<h);
		for(int j=0;j<w;j++){
			assert(j>=0 && j<w);
			assert(!feof(fp));
			fread(&a[i][j].r,1,1,fp);
			fread(&a[i][j].g,1,1,fp);
			fread(&a[i][j].b,1,1,fp);
		}
		fseek(fp,info->padding,SEEK_CUR);
	}
	return a;
}