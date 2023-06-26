all:
	clear
	gcc -o main main.c catalogo.c chamadas.c estoque.c jogo.c utils.c
	./main
