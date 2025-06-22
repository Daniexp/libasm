NAME = test
LIB_NAME = libasm.a
SRC =	helloWorld.s \
	ft_strlen.s \
	ft_strcpy.s  \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s

ASM_DIR = asm
ASM_SRC= $(addprefix $(ASM_DIR)/, $(SRC))
OBJ = $(ASM_SRC:.s=.o)
CSRC = main.c
HEADER = libasm.h
COBJ = $(CSRC:.c=.o)

all: $(NAME) 

$(NAME): $(LIB_NAME) $(COBJ) $(HEADER)
	gcc $(COBJ) -L. -lasm -o $(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.s
	nasm -f elf64 $< -o $@

%.o: %.c 
	gcc -c $< -o $@

clean:
	rm -f $(OBJ) $(COBJ)

fclean: clean
	rm -f $(LIB_NAME) $(NAME)

re: fclean all

