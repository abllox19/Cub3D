
#VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=ignore.txt
#VALGRIND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=ignore.txt --track-fds=yes --trace-children=yes ./CUBE
#test:
#	$(VALGRIND) ./votre_executable
CFLAGS  = -Wall -Wextra  -Werror
LDFLAGS = -g3 -lreadline

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
LIBFT_PATH = libft/

# Libraries and flags
LIBFT = $(LIBFT_PATH)libft.a

# Source files
CUBE_SRC = main.c check_map.c check_map_utils.c utils.c check_obj.c

# Object files
CUBE_OBJS = $(addprefix $(OBJ_PATH), $(CUBE_SRC:.c=.o))


CUBE_NAME = cub3D

# Rules
all: $(LIBFT) $(CUBE_NAME)

# Build the binary
$(CUBE_NAME): $(CUBE_OBJS) $(LIBFT)
	$(MAKE) -C $(LIBFT_PATH)  # Compile libft if necessary
	$(CC) $(CFLAGS) $(CUBE_OBJS) $(LIBFT) $(LDFLAGS) -o $(CUBE_NAME) -g3

# Build the object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) # Create obj directory if it doesn't exist
	$(CC) $(CFLAGS) -g3 -c $< -o $@

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Cleaning rules
clean:
	$(RM) -r $(OBJ_PATH)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(CUBE_NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re