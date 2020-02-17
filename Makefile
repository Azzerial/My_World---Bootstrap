##   __  __       __      __       _    _
##  |  \/  |_  _  \ \    / /__ _ _| |__| |
##  | |\/| | || |  \ \/\/ / _ \ '_| / _` |
##  |_|  |_|\_, |   \_/\_/\___/_| |_\__,_|
##          |__/
##
## A CSFML world terraforming tool.
## Made by Robin Mercier © Lord Estropié, 2020
##

rwildcard = $(wildcard $1$2)$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRC = $(call rwildcard,src/,*.c)

OBJ = $(SRC:.c=.o)

OUT = application

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -Iinclude/

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

.SUFFIXES: .c .o
.c.o:
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES) $(LDFLAGS)

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(CFLAGS) $(INCLUDES) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re: fclean all
