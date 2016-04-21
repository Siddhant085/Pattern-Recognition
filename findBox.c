#include "library.h"

int findLength(pi **a,int r,int g,int b,unsigned long int width,int length,int error){
	unsigned char ce=50;//error in color values
	int h=0;
	int i=length+2*error;
	int found=0;
	int blue=0;
	while(i<width && !found){
		for(int k=h;k<h+error && !found;k++){
			int ctr=0;
			int j=i;
			blue = 0;
			while((j>i-4*error && !blue) || (j>i-length-2*error && blue)){
			//for(int j=i;j<i+length+2*error;j--){
				j--;
				assert(j>0 );
				assert(j<width);
				unsigned char rr=a[k][j].r;
				unsigned char rg=a[k][j].g;
				unsigned char rb=a[k][j].b;
				
		//		printf("%d %d\n",(j>i-4*error && !blue),(j>i-length-2*error && blue && j>0));
				printf("%u %u %u %d\n",b-ce,(rb),b+ce,ctr);
				if(((0)<=rr && rr<((r+ce))) && (((b-ce))<rb && rb<((b+ce))) && (((g-ce))<rg && ((rg<g+ce)))){
				//if(rr!=-1 && rg!=-1 && rb !=-1){
		//			printf("%c %c %c %d\n",rr,rg,rb,ctr);
				//	a[k][j].r=a[k][j].b=a[k][j].g=0;
					ctr++;
					blue=1;

					printf("blue{%u %u %u}, ",(int)rr,(int)rg,(int)rb );
				}
				else{
					blue=0;
					printf("%c ",'.' );
			//		printf("{%d %d %d}, ",(int)rr,(int)rg,(int)rb );
					//a[k][j].r=a[k][j].b=a[k][j].g=0;
				}
				if(ctr>length-4*error)
					found=1;
			}
		}
		printf("\n");
		if(blue){
			i+=length/2;
		}
		else{
			i+=length;
		}

	}
	if(found)
		return i;
	else
		return 0;

}

void keepColor(pi **a,int r,int g,int b,unsigned long int width,unsigned long int height){
	int ce=50;
/*	r=255-r;
	g=255-g;
	b=255-b;*/
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			char rr=a[i][j].r;
			char rg=a[i][j].g;
			char rb=a[i][j].b;
			//if ((((r-ce))<rr && rr<((r+ce))) && (((b-ce))<rb && rb<((b+ce))) && (((g-ce))<rg && ((rg<g+ce))))
			if(i==height/2)
			{
			//	a[i][j].r=a[i][j].b=a[i][j].g=0;
			//	printf("%d %d %d\n",(int)rr,(int)rg,(int)rb);
			}
			if(rr<50 && rb<50&& rg<50){
				a[i][j].r=a[i][j].b=a[i][j].g=0;
			}
			else{
				a[i][j].r=a[i][j].b=a[i][j].g=255;
			}
		}
	}
}