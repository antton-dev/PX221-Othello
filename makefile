# Makefile générique pour ce répertoire
# - compile tous les fichiers .c trouvés dans le dossier
# - produit l'exécutable `othello` (modifiable)

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -g

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
TARGET := othello

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

test: run

clean:
	rm -f $(OBJS) $(TARGET)

# Usage:
#  - `make` ou `make all` : compile tout et crée l'exécutable `othello`
#  - `make run` : lance `./othello`
#  - `make clean` : supprime objets et exécutable