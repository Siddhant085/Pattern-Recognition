#include "library.h"

pi ** crop(head *h,pi **a,int sx,int sy,int ex,int ey){
	//sx and sy are the start position from where to crop.
	//ex and ey are the end locations
	//the function crops a rectangular area specified by the above constraints
	//it makes the rest of the image black not changing the size of the image.
	//The image is stored bottom to top and left to right
	pi **ab = (pi **)(malloc)(ey*sizeof(pi *));
	for(int i=0;i<sy;i++){
		ab[i]=(pi *)malloc(ex*sizeof(pi));
	}
	//make a new pixel array containing only the required pixels
	for(int i=h->height-1;i>=0;i--){
		for (int j = 0; j < h->width  ; ++j){
			if((i<sy && i>ey && j>sx && j<ex)){
				ab[i-ey][j-sx].r=a[i][j].r;
				ab[i-ey][j-sx].g=a[i][j].g;
				ab[i-ey][j-sx].b=a[i][j].b;
			}
		}
	}
	// change header information according to the crop size
	h->width=ex-sx;
	h->height=sy-ey;
	int padding=calcPadding(h);
	h->sizeImage=h->width*h->height*3+padding*h->height;
	h->bfsize=h->sizeImage+h->bfoffset;
	return ab;
}