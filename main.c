#include "library.h"
int main(){
	FILE *fp;
	fp=fopen("Scan.bmp","rb");
	if(fp==NULL){
		printf("file not found\n");
		return 0;
	}
	head *h=readHeader(fp);
	pinfo info;
	info.padding=0;
	info.padding=calcPadding(h);
/*	if(h->size>40){
		info.extHeader=malloc(sizeof(char)*(h->size-40));
		fread(info.extHeader,1,h->size-40,fp);
	}
*/
//	displayDetails(h);


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
//	int swidth=598,sheight=375,ewidth=568,eheight=73;
	int swidth=620,sheight=372,ewidth=525,eheight=68;
	a=crop(h,a,swidth,h->height-sheight,swidth+ewidth,h->height-sheight-eheight);
	head *newH=changeHeader(h,ewidth,eheight);
//	toJpeg("usn.jpeg",newH,a);
	writeImage(a,newH,&info,"usn.bmp");
	fp=fopen("usn.bmp","rb");
	if(fp==NULL){
		printf("file not found\n");
		return 0;
	}
	
	h=readHeader(fp);
	info.padding=calcPadding(h);
	
	a=readImage(h->width,h->height,h->bfoffset,fp,&info);
	slice(h,a,&info,10);
//	displayDetails(h);
/*	for(int i=0;i<10;i++){
		
		char name[13];
		snprintf(name,sizeof(name),"output1%d.bmp",i);
		crop(h,a,swidth,h->height-sheight,swidth+(ewidth/10),h->height-sheight-eheight);
		keepColor(a,0,0,0,h->width,h->height);
		writeImage(fp,a,h,h->width,h->height,&info,name);
		swidth+=(ewidth/10);
		a=readImage(h->width,h->height,h->bfoffset,fp,&info);
	}*/
	
	fclose(fp);


	return 0;
}