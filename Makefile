
NAME			:=	tree.out

INCLUDES_DIR	:=	./includes/
SRC_DIR			:=	./src/
TESTS_DIR		:=	./tests/
OBJS_DIR		:=	./objs/

CC				:=	clang++
CFLAGS			:=	-Wall -Wextra -Werror
CFLAGS			+=	-g3
CFLAGS			+=	-std=c++98

RM				:=	rm -rf

SRC				:=

TESTS			:=	$(TESTS_DIR)main.cpp\
					$(TESTS_DIR)testes_lais.cpp

OBJS			:=	$(addprefix $(OBJS_DIR), $(notdir $(TESTS:.cpp=.o)))

HEADER			:=	$(INCLUDES_DIR)btree.tpp\
					$(INCLUDES_DIR)tests.hpp\
					$(INCLUDES_DIR)btree_create_note.tpp\
					$(INCLUDES_DIR)btree_insert_data.tpp\
					$(INCLUDES_DIR)btree_apply_prefix.tpp\
					$(INCLUDES_DIR)btree_apply_infix.tpp\
					$(INCLUDES_DIR)btree_apply_suffix.tpp\
					$(INCLUDES_DIR)btree_search_item.tpp\
					$(INCLUDES_DIR)btree_level_count.tpp\
					$(INCLUDES_DIR)compare.tpp\
					$(INCLUDES_DIR)print_item.tpp

INCLUDES		:= $(addprefix -I, $(INCLUDES_DIR))

$(OBJS_DIR)%.o:	$(TESTS_DIR)%.cpp
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@

$(OBJS):		| $(OBJS_DIR)

$(OBJS_DIR):
				mkdir $(OBJS_DIR)

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

PHONY:			all clean fclean re
