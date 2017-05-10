all: clean compile
all2: compile

compile: main.o matrizes.o
	@gcc matrizes.o main.o -o trab3 -g
main.o:
	@gcc -c -O2 main.c -g
matrizes.o:
	@gcc -c -O2 matrizes.c -g -lm
clean:
	@rm *.o
run:
	@./trab3
zip:
	@zip Trab3.zip *.c *.h Relatorio.pdf Makefile