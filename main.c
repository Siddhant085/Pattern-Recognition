#include "library.h"

int main(){
	FILE *fp;
	fp=fopen("SS.bmp","rb");
	if(fp==NULL){
		printf("file not found\n");
		return 0;
	}
	head *h=readHeader(fp);
	pinfo info;
	info.padding=0;
	if((h->width*3)%4!=0){
		info.padding=4-(h->width*3)%4;
	}
/*	if(h->size>40){
		info.extHeader=malloc(sizeof(char)*(h->size-40));
		fread(info.extHeader,1,h->size-40,fp);
	}
*/
	//displaying file header details
//	printf("%c%c\n",h->bftype[0],h->bftype[1]);
//	printf("%d\n",info.padding);
//	printf("%u\n",h->bfoffset);


	//displaying image header details
	printf("total size %u\n",h->size-40);
	printf("width %d\n",h->width);
	printf("height %d\n",h->height);
	printf("bits per pixel %d\n",h->nbit);
	printf("Image size %u\n",h->sizeImage);
	printf("Offset %u\n",h->bfoffset );
	printf("Color used %lu\n",sizeof(h) );
//	printf("%lu\n",sizeof(head));


	pi **a=readImage(h->width,h->height,h->bfoffset,fp,&info);
	//The image is stored bottom to top and left to right
/*	int swidth,sheight,ewidth,eheight;
	printf("Enter the starting width and height: ");
	scanf("%d %d",&swidth,&sheight);
	printf("Enter the width and height to be cropped: ");
	scanf("%d %d",&ewidth,&eheight);
	crop(h,a,swidth,h->height-sheight,swidth+ewidth,h->height-sheight-eheight);
	writeImage(fp,a,h,h->width,h->height,&info);
*/
//	int gotit = findLength(a,0,149,223,h->width,570,40);
//	printf("found at%d\n", gotit);
//	keepColor(a,20,150,200,h->width,h->height);
	int swidth=598,sheight=375,ewidth=568,eheight=73;
//	crop(h,a,swidth,h->height-sheight,swidth+ewidth,h->height-sheight-eheight);
/*	for(int i=0;i<10;i++){
		
		char name[13];
		snprintf(name,sizeof(name),"output1%d.bmp",i);
		crop(h,a,swidth,h->height-sheight,swidth+(ewidth/10),h->height-sheight-eheight);
		keepColor(a,0,0,0,h->width,h->height);
		writeImage(fp,a,h,h->width,h->height,&info,name);
		swidth+=(ewidth/10);
		a=readImage(h->width,h->height,h->bfoffset,fp,&info);
	}*/
	writeImage(fp,a,h,h->width,h->height,&info,"writeTest.bmp");
	fclose(fp);


	return 0;
}