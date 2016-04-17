#include "library.h"

pi ** crop(head *h,pi **a,int sx,int sy,int ex,int ey){
	//sx and sy are the start position from where to crop.
	//ex and ey are the end locations
	//the function crops a rectangular area specified by the above constraints
	//The image is stored bottom to top and left to right
	pi **ab = (pi **)(malloc)((sy-ey)*sizeof(pi *));
	for(int i=0;i<sy-ey;i++){
		ab[i]=(pi *)malloc((ex-sx)*sizeof(pi));
	}
	//make a new pixel array containing only the required pixels
	for(int i=h->height-1;i>=0;i--){
		for (int j = 0; j < h->width  ; ++j){
			if((i<sy && i>ey && j>sx && j<ex)){
				ab[i-ey-1][j-sx-1].r=a[i][j].r;
				ab[i-ey-1][j-sx-1].g=a[i][j].g;
				ab[i-ey-1][j-sx-1].b=a[i][j].b;
			}
		}
	}
	// change header information according to the crop size
	
	return ab;
}