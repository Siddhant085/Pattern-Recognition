# Pattern-Recognition
A simple project in C, without using any extra image processing libraries, to read, write and manipulate image files. The main aim is to recognize patterns and crop out recognized parts of a scanned image.


Dependencies
tesseract-ocr
tesseract-ocr-dev
libtesseract-dev
libtesseract3
liblept5
libleptonica-dev

On debian systems execute the following command to get the above packages.
apt-get install tesseract-ocr tesseract-ocr-dev libtesseract-dev libtesseract3 liblept5 libleptonica-dev

# Usage Insructions
Input - Scanned image of the front end of the answer script.
		The image needs to be in 24 - bit BMP format.
		In case a different scanned copy is provided the position and dimensions of the usn box will have to be fed in.

Output- The characters of the USN as predicted by the tesseract will be printed on the terminal.
		Intermediate images of each character in black and white is also generated.

Instructions to run.
Once you are in the src folder.
type the following commands on the terminal.

make
./image
Enter the name of the image file to be read.

The output will be generated on the terminal. The intermediate images can be seen in the src folder.
usn.bmp conatins the cropped out image of the usn box
output10.bmp,output11.bmp,...,output19.bmp are the 10 images containing a character each.

Improvements and Future Enhancements
1. Remove all the limitations.
2. Write an algorithm to find the USN box so that the position of the box need not be provided.
3. Use Machine Learning algorithms to find the USN box even if the dimensions of the box are  not provided. 
4. Use a better tool for handwriting recognition.
5. Train the tool to achieve accuracy of upto 99%.