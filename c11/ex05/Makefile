DEST_NAME = do-op

$(DEST_NAME):
	cc -Wall -Werror -Wextra $(shell find . -name "*.c") -o $(DEST_NAME)

all: $(DEST_NAME)

clean:
	rm -f $(DEST_NAME)

fclean: clean

remake: clean all

.PHONY: all clean fclean