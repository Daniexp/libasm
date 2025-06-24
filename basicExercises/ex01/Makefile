NAME = writeStdout
SRC = main.s
OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ld -o $@ $^


%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

