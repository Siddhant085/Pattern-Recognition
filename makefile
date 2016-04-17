image: main.o readHeader.o readImage.o writeFile.o crop.o findBox.o
	gcc -o image main.o readHeader.o readImage.o writeFile.o crop.o findBox.o
main.o: main.c library.h
	gcc -c main.c
readHeader.o: readHeader.c library.h
	gcc -c readHeader.c
readImage.o: readImage.c library.h
	gcc -c readImage.c
writeFile.o: writeFile.c library.h
	gcc -c writeFile.c
crop.o: crop.c library.h
	gcc -c crop.c
findBox.o: findBox.c library.h
	gcc -c findBox.c
clean:
	rm image main.o readHeader.o readImage.o writeFile.o crop.o findBox.o