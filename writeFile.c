#include "library.h"

void writeImage(const pi **a,head *headerInfo,pinfo *info,char *name){
	unsigned long w = headerInfo->width;
	unsigned long h = headerInfo->height;
	char padding='\0';
	info->padding=calcPadding(headerInfo);
	char outname[strlen(name)+1];
	snprintf(outname,sizeof(outname),"%s",name);
	FILE *fpout;
	//ouptup1.bmp
	fpout=fopen(outname,"wb");
	//fwrite(headerInfo,1,sizeof(headerInfo),fpout);
	headerInfo->bfoffset=54;
	headerInfo->size=40;
	writeHeader(headerInfo,fpout);
//	fwrite(&padding,1,headerInfo->bfoffset-54,fpout);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			//image can be manipulated before writing
			//By changing the order of rgb we can see its effect on the image
			fwrite(&a[i][j].r,1,1,fpout);
			fwrite(&a[i][j].g,1,1,fpout);
			fwrite(&a[i][j].b,1,1,fpout);
		}
		fwrite(&padding,1,info->padding,fpout);
	}
	char c;
	
	fclose(fpout);

}