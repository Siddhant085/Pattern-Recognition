#include "library.h"
#include <leptonica/allheaders.h>
#include <tesseract/capi.h>
void die(const char *errstr) {
    fputs(errstr, stderr);
    exit(1);
}

void doTess(char *name) {
    char outname[strlen(name)+1];
    snprintf(outname,sizeof(outname),"%s",name);
    TessBaseAPI *handle;
    PIX *img;
    char *text;

    if((img = pixRead(outname)) == NULL)
        die("Error reading image\n");

    handle = TessBaseAPICreate();
    if(TessBaseAPIInit3(handle, NULL, "eng") != 0)
        die("Error initialising tesseract\n");

    TessBaseAPISetImage2(handle, img);
    TessPageSegMode mode= PSM_SINGLE_CHAR;
    TessBaseAPISetPageSegMode(handle,mode);
    TessBaseAPISetVariable(handle,"tessedit_char_whitelist","0123456789PICSME");
    if(TessBaseAPIRecognize(handle, NULL) != 0)
        die("Error in Tesseract recognition\n");

     if((text = TessBaseAPIGetUTF8Text(handle)) == NULL)
        die("Error getting text\n");

    fputs(text, stdout);

    TessDeleteText(text);
    TessBaseAPIEnd(handle);
    TessBaseAPIDelete(handle);
    pixDestroy(&img);
  
    //return 0;
}
/*int main(){
    doTess();
    return 0;
}*/