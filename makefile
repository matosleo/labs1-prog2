# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Define o nome do binario/executavel final
PROG = $(BIN)/exerc2

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binario/executavel final
OBJS = $(OBJ)/dado.o $(OBJ)/jogador.o $(OBJ)/sort.o $(OBJ)/jogo.o $(OBJ)/main.o

all : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

# Alvo para a compilação com informações de debug
# Altera a flag CFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CFLAGS += -g -O0 
debug: all

# Alvo para a construcao do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main.o : $(OBJ)/jogo.o 
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/jogo.o : $(INC)/jogo.h $(OBJ)/jogador.o $(OBJ)/sort.o
	$(CC) $(CPPFLAGS) -c $(SRC)/jogo.cpp -o $@

$(OBJ)/sort.o : $(INC)/sort.h $(OBJ)/jogador.o
	$(CC) $(CPPFLAGS) -c $(SRC)/bubbleSort.cpp -o $@

$(OBJ)/jogador.o : $(INC)/jogador.h $(OBJ)/dado.o
	$(CC) $(CPPFLAGS) -c $(SRC)/jogador.cpp -o $@

$(OBJ)/dado.o : $(INC)/dado.h
	$(CC) $(CPPFLAGS) -c $(SRC)/dado.cpp -o $@

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(PROG) $(OBJS)