CC = clang
SRC = src/*.c
EXEC = pwdgen 
FLAGS = -Wall -Wextra -std=c99

main: $(SRC)
	$(CC) $(SRC) $(FLAGS) -o $(EXEC)

clean: $(EXEC)
	rm $(EXEC)
