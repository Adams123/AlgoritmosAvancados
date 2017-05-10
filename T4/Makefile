all: clean compile
all2: compile

compile: AAAA.o
	@gcc AAAA.o -o AAAA -g -lm
main.o:
	@gcc -c -O2 AAAA.c -g -lm
clean:
	@rm *.o
run:
	@./AAAA

zip:
	@zip AAAA.zip *.c *.h Relatorio.pdf Makefile