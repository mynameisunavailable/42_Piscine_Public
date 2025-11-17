TARGET_FILE = src/ft_tail

$(TARGET_FILE):
	cc -Wall -Werror -Wextra -Iinclude `find . -name "*.c"` -o $@

all: $(TARGET_FILE)

clean:
	rm -f $(TARGET_FILE)

fclean: clean

rebuild: clean all

.PHONY: all clean fclean rebuild