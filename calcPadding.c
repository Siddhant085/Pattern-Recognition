#include "library.h"

int calcPadding(const head *head){
	int padding=0;
	if((head->width*3)%4!=0){
		padding=4-(head->width*3)%4;
	}
	else{
		padding=0;
	}
	return padding;
}