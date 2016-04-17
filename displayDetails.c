#include "library.h"

void displayDetails(const head *h){
	printf("File type %c%c\n",h->bftype[0],h->bftype[1]);
	printf("size of file %u\n",h->bfsize );
	printf("Offset %u\n",h->bfoffset );
	printf("header size %u\n",h->size);
	printf("width %d\n",h->width);
	printf("height %d\n",h->height);
	printf("bits per pixel %d\n",h->nbit);
	printf("Image size %u\n",h->sizeImage);
	printf("padding %d\n",calcPadding(h) );
	
}