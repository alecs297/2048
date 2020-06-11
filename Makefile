SRC  = $(wildcard *.c) #fichiers sources
OBJ  = $(SRC:.c=.o) #fichiers objets
CC   = gcc 
PROG = 2048

all : $(PROG)

$(PROG) : $(OBJ) #Compiliation des fichiers .c
	@$(CC) $^ -o $@ -lm && rm -f *.o && echo "Compilé, utilisez './2048' pour lancer le jeu."

.c.o : #Compiliation des fichiers .o
	@$(CC) -Wall -Wextra -c $^ -o $@ -lm 

.PHONY : clean

clean   :
	@rm -f $(OBJ)