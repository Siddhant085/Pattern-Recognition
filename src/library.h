#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma pack(1)

typedef struct header head; //header info
typedef struct pixel pi;//pixel structure
typedef struct processingInfo  pinfo;

head * readHeader(FILE *fp);
pi ** readImage(unsigned long int w,unsigned long int h,unsigned long int offset,FILE *fp,const pinfo *info);
void writeImage(FILE *fp,pi **a,head *head,unsigned long w,unsigned long h,const pinfo *info);
void crop(head *h,pi **a,int sx,int sy,int ex,int ey);


struct pixel{
	char r;
	char g;
	char b;
};

struct header{

	//file header
	char bftype[2];
	unsigned int bfsize;
	unsigned short reserve1;
	unsigned short reserve2;
	unsigned int bfoffset;
	

	//core header
	unsigned int size;
	int width;
	int height;
	short planesCount;
	short nbit;
	unsigned int compression;
	unsigned int sizeImage;
	int xpperm;
	int ypperm;
	unsigned int clrUsed;
	unsigned int clrImp;
};

struct processingInfo{
	int padding;
};