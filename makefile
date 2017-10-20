link: linkedl.o music_lib.o main.o
	gcc -o link linkedl.o music_lib.o main.o
linkedl.o:
	gcc -c linkedl.c
music_lib.o:
	gcc -c music_lib.c
main.o:
	gcc -c main.c
run: link
	./link
clean:
	rm *.o
	rm *~

