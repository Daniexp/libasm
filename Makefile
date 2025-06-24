NAME = test
LIB_NAME = libasm.a
SRC =	ft_strlen.s \
	ft_strcpy.s  \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s

ASM_DIR = asm
ASM_SRC= $(addprefix $(ASM_DIR)/, $(SRC))
OBJ = $(ASM_SRC:.s=.o)
C_DIR = src
CSRC = main.c \
       utils.c \
       test.c
C_SRC= $(addprefix $(C_DIR)/, $(CSRC))
CFLAGS = -Wextra -Werror -Wall -lasm -L. -Iinc
COBJ = $(C_SRC:.c=.o)

all: $(NAME) 

$(NAME): $(LIB_NAME) $(COBJ)
	gcc $(CFLAGS) $(COBJ) $(LIB_NAME) -o $(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.s
	nasm -f elf64 $< -o $@

%.o: %.c 
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(COBJ)

fclean: clean
	rm -f $(LIB_NAME) $(NAME)

re: fclean all

