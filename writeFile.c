#include "library.h"

void writeImage(FILE *fp,pi **a,head *headerInfo,unsigned long w,unsigned long h,const pinfo *info,char *name){
	char padding='\0';
	char outname[strlen(name)+1];
	snprintf(outname,sizeof(outname),"%s",name);
	FILE *fpout;
	//ouptup1.bmp
	fpout=fopen(outname,"wb");
	//fwrite(headerInfo,1,sizeof(headerInfo),fpout);
	fwrite(&headerInfo->bftype,1,sizeof(headerInfo->bftype),fpout);
	fwrite(&headerInfo->bfsize,1,sizeof(headerInfo->bfsize),fpout);
	fwrite(&headerInfo->reserve1,1,sizeof(headerInfo->reserve1),fpout);
	fwrite(&headerInfo->reserve2,1,sizeof(headerInfo->reserve2),fpout);
	fwrite(&headerInfo->bfoffset,1,sizeof(headerInfo->bfoffset),fpout);
	fwrite(&headerInfo->size,1,sizeof(headerInfo->size),fpout);
	fwrite(&headerInfo->width,1,sizeof(headerInfo->width),fpout);
	fwrite(&headerInfo->height,1,sizeof(headerInfo->height),fpout);
	fwrite(&headerInfo->planesCount,1,sizeof(headerInfo->planesCount),fpout);
	fwrite(&headerInfo->nbit,1,sizeof(headerInfo->nbit),fpout);
	fwrite(&headerInfo->compression,1,sizeof(headerInfo->compression),fpout);
	fwrite(&headerInfo->sizeImage,1,sizeof(headerInfo->sizeImage),fpout);
	fwrite(&headerInfo->xpperm,1,sizeof(headerInfo->xpperm),fpout);
	fwrite(&headerInfo->ypperm,1,sizeof(headerInfo->ypperm),fpout);
	fwrite(&headerInfo->clrUsed,1,sizeof(headerInfo->clrUsed),fpout);
	fwrite(&headerInfo->clrImp,1,sizeof(headerInfo->clrImp),fpout);
	fwrite(&padding,1,headerInfo->bfoffset-54,fpout);
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
	//fseek(fp,w*h*3,SEEK_CUR);
	/*if(!feof(fp)){
		fread(&c,1,1,fp);
		fwrite(&c,1,1,fpout);
	}*/
	fclose(fpout);

}