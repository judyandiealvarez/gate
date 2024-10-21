all: gate

gate: obj/main.o obj/MC33886.o obj/MC_Config.o obj/argparse.o
	gcc -o bin/gate obj/main.o obj/MC33886.o obj/MC_Config.o obj/argparse.o -l:libbcm2835.a -L:/usr/local/include

obj/MC_Config.o: src/MC_Config.c
	gcc -c src/MC_Config.c -o obj/MC_Config.o

obj/MC33886.o: src/MC33886.c
	gcc -c src/MC33886.c -o obj/MC33886.o

obj/argparse.o: src/argparse.c
	gcc -c src/argparse.c -o obj/argparse.o

obj/main.o: src/main.c
	gcc -c src/main.c -o obj/main.o

clean: 
	rm -f obj/* bin/*
