#include "library.h"

head * changeHeader(const head *header,long unsigned width,long unsigned height){
	head *h=(head *)malloc(sizeof(head));
	h->bftype[0]=header->bftype[0];
	h->bftype[1]=header->bftype[1];
	h->reserve1=header->reserve1;
	h->reserve2=header->reserve2;
	h->bfoffset=header->bfoffset;
	h->size=header->size;
	h->width=width;
	h->height=height;
	h->planesCount=header->planesCount;
	h->nbit=header->nbit;
	h->compression=header->compression;
	h->xpperm=header->xpperm;
	h->ypperm=header->ypperm;
	h->clrUsed=header->clrUsed;
	h->clrImp=header->clrImp;
	int padding=calcPadding(h);
	h->sizeImage=h->width*h->height*3+padding*h->height;
	h->bfsize=h->sizeImage+h->bfoffset;

	return h;
}