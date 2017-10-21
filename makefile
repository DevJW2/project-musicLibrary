link: linkedl.o music_lib.o main.o
	gcc -o link linkedl.o music_lib.o main.o
linkedl.o: linkedl.c
	gcc -c linkedl.c
music_lib.o: music_lib.c
	gcc -c music_lib.c
main.o: main.c
	gcc -c main.c
run: link
	./link
clean:
	rm *.o


