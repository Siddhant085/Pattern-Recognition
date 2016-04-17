#include "library.h"

void writeImage(FILE *fp,pi **a,head *headerInfo,unsigned long w,unsigned long h,pinfo *info,char *name){
	char padding='\0';
	info->padding=calcPadding(headerInfo);
	printf("%d\n",info->padding);
	char outname[strlen(name)+1];
	snprintf(outname,sizeof(outname),"%s",name);
	FILE *fpout;
	//ouptup1.bmp
	fpout=fopen(outname,"wb");
	//fwrite(headerInfo,1,sizeof(headerInfo),fpout);
	writeHeader(headerInfo,fpout);
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