#include "library.h"

void crop(head *h,pi **a,int sx,int sy,int ex,int ey){
	//sx and sy are the start position from where to crop.
	//ex and ey are the end locations
	//the function crops a rectangular area specified by the above constraints
	//it makes the rest of the image black not changing the size of the image.
	//The image is stored bottom to top and left to right
	for(int i=h->height-1;i>=0;i--){
		for (int j = 0; j < h->width  ; ++j){
			if(!(i<sy && i>ey && j>sx && j<ex)){
				a[i][j].r=0;
				a[i][j].g=0;
				a[i][j].b=0;
			}
		}
	}	
}