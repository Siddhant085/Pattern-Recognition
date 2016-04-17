#include "library.h"

void writeHeader(head *head,FILE *fpout){
	fwrite(&head->bftype,1,sizeof(head->bftype),fpout);
	fwrite(&head->bfsize,1,sizeof(head->bfsize),fpout);
	fwrite(&head->reserve1,1,sizeof(head->reserve1),fpout);
	fwrite(&head->reserve2,1,sizeof(head->reserve2),fpout);
	fwrite(&head->bfoffset,1,sizeof(head->bfoffset),fpout);
	fwrite(&head->size,1,sizeof(head->size),fpout);
	fwrite(&head->width,1,sizeof(head->width),fpout);
	fwrite(&head->height,1,sizeof(head->height),fpout);
	fwrite(&head->planesCount,1,sizeof(head->planesCount),fpout);
	fwrite(&head->nbit,1,sizeof(head->nbit),fpout);
	fwrite(&head->compression,1,sizeof(head->compression),fpout);
	fwrite(&head->sizeImage,1,sizeof(head->sizeImage),fpout);
	fwrite(&head->xpperm,1,sizeof(head->xpperm),fpout);
	fwrite(&head->ypperm,1,sizeof(head->ypperm),fpout);
	fwrite(&head->clrUsed,1,sizeof(head->clrUsed),fpout);
	fwrite(&head->clrImp,1,sizeof(head->clrImp),fpout);
}