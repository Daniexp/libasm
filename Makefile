NAME = test
LIB_NAME = libasm.a
SRC =	helloWorld.asm \
	ft_strlen.asm \
	ft_strcpy.asm  \
	ft_strcmp.asm \
	ft_write.asm

ASM_DIR = asm
ASM_SRC= $(addprefix $(ASM_DIR)/, $(SRC))
OBJ = $(ASM_SRC:.asm=.o)
CSRC = main.c
HEADER = mylib.h
COBJ = $(CSRC:.c=.o)

all: $(LIB_NAME) $(COBJ) $(HEADER)
	gcc $(COBJ) -L. -lasm -o $(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.asm
	nasm -f elf64 $< -o $@

%.o: %.c 
	gcc -c $< -o $@

clean:
	rm -f $(OBJ) $(COBJ)

fclean: clean
	rm -f $(LIB_NAME) $(NAME)

re: fclean all

