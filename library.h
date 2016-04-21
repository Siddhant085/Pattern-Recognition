#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#pragma pack(1)

typedef struct header head; //header info
typedef struct pixel pi;//pixel structure
typedef struct processingInfo  pinfo;

void doTess(char *name);
void toJpeg(char *name,head *header,pi **a);
head * changeHeader(const head *header,long unsigned width,long unsigned height);
void blackWhite(pi **a,unsigned long w,unsigned long h);
void slice(head *head,pi **a,pinfo *info,int n);
void displayDetails(const head *head);
int findLength(pi **a,int r,int g,int b,unsigned long int width,int length,int error);
int calcPadding(const head *head);
void writeHeader(head *head,FILE *fpout);
head * readHeader(FILE *fp);
pi ** readImage(unsigned long int w,unsigned long int h,unsigned long int offset,FILE *fp,const pinfo *info);
void writeImage(const pi **a,head *head, pinfo *info,char *name);
pi ** crop(head *h,pi **a,int sx,int sy,int ex,int ey);
void keepColor(pi **a,int r,int g,int b,unsigned long int width,unsigned long int height);

struct pixel{
	char r;
	char g;
	char b;
};

struct header{

	//file header
	char bftype[2];
	unsigned int bfsize;//size of bmp file in bytes
	unsigned short reserve1;
	unsigned short reserve2;
	unsigned int bfoffset;//offset to pixel array
	

	//core header
	unsigned int size;//size of the header
	int width;
	int height;
	short planesCount;
	short nbit;
	unsigned int compression;
	unsigned int sizeImage;//size of the raw bitmap data including padding
	int xpperm;
	int ypperm;
	unsigned int clrUsed;
	unsigned int clrImp;
};

struct processingInfo{
	int padding;
	char *extHeader;
};