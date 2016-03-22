#include "library.h"


head * readHeader(FILE *fp){
	head *h=malloc(sizeof(head));
	fread(h->bftype,1,2,fp);
	fread(&h->bfsize,4,1,fp);
	fread(&h->reserve1,1,2,fp);
	fread(&h->reserve2,1,2,fp);
	fread(&h->bfoffset,4,1,fp);
	fread(&h->size,1,4,fp);
	fread(&h->width,4,1,fp);
	fread(&h->height,4,1,fp);
	fread(&h->planesCount,2,1,fp);
	fread(&h->nbit,2,1,fp);
	fread(&h->compression,4,1,fp);
	fread(&h->sizeImage,4,1,fp);
	fread(&h->xpperm,4,1,fp);
	fread(&h->ypperm,4,1,fp);
	fread(&h->clrUsed,4,1,fp);
	fread(&h->clrImp,4,1,fp);
	return h;
}