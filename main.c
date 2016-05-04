#include "library.h"
int main(int argc,char *argv){
	FILE *fp;
	char input[100];
	scanf("%s",input);
	char name[strlen(input)+1];
	snprintf(name,sizeof(name),"%s",input);
	fp=fopen(name,"rb");
	if(fp==NULL){
		printf("file not found\n");
		return 0;
	}
	head *h=readHeader(fp);
	pinfo info;
	info.padding=0;
	info.padding=calcPadding(h);



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

//	int swidth=598,sheight=375,ewidth=568,eheight=73;
//	int swidth=620,sheight=372,ewidth=525,eheight=68;//scan
//	int swidth=867,sheight=585,ewidth=775,eheight=75;//daa2,daa3
//	int swidth=895,sheight=585,ewidth=775,eheight=75;//daa5
	int swidth=895,sheight=585,ewidth=785,eheight=80;//daa6
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

	
	fclose(fp);


	return 0;
}