#include "library.h"

void slice(head *header,pi **a,pinfo *info,int n){
	int margin=15;
	long unsigned sx=margin;
	long unsigned ex=header->width/n-margin;
	for (int i = 0; i < n; ++i)
	{
		char name[13];
		snprintf(name,sizeof(name),"output1%d.bmp",i);
		pi **ab=crop(header,a,sx,header->height-margin,sx+ex,margin);
		head *newH=changeHeader(header,ex,header->height-2*margin);
		blackWhite(ab,ex,header->height-2*margin);
		writeImage(ab,newH,info,name);
		doTess(name);
	//	free(ab);
		sx+=ex+margin;
	}
}