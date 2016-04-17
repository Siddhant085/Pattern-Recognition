#include "library.h"

int main(){
	FILE *fp;
	fp=fopen("debian.bmp","rb");
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

	//displaying file header details
//	printf("%c%c\n",h->bftype[0],h->bftype[1]);
//	printf("%d\n",info.padding);
//	printf("%u\n",h->bfoffset);


	//displaying image header details
//	printf("%u\n",h->size);
	printf("width %d\n",h->width);
	printf("height %d\n",h->height);
	printf("bits per pixel %d\n",h->nbit);
//	printf("%lu\n",sizeof(head));


	pi **a=readImage(h->width,h->height,h->bfoffset,fp,&info);
	//The image is stored bottom to top and left to right
	int swidth,sheight,ewidth,eheight;
	printf("Enter the starting width and height: ");
	scanf("%d %d",&swidth,&sheight);
	printf("Enter the width and height to be cropped: ");
	scanf("%d %d",&ewidth,&eheight);
	crop(h,a,swidth,h->height-sheight,swidth+ewidth,h->height-sheight-eheight);
	writeImage(fp,a,h,h->width,h->height,&info);

	fclose(fp);


	return 0;
}