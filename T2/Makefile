all: clean Arquivos.o DTW.o main.o compile
all2: Arquivos.o DTW.o main.o compile

compile:
	@gcc Arquivos.o DTW.o  main.o -o trab2 -g -lm

Arquivos.o:
	@gcc -c -O3 Arquivos.c

DTW.o:
	@gcc -c -O3 DTW.c

main.o:
	@gcc -c -O3 main.c

clean:
	@rm *.o trab2

run:
	@./trab2
zip:
	@zip Trab2.zip *.c *.h *.txt Relatorio.pdf Makefile
