# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    link.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/06/25 18:24:28 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SOURCES_PATH := ./src/

SOURCES :=	compare.c \
			display.c \
			dlist.c \
			error.c \
			files.c \
			insert.c \
			main.c \
			parser.c \
			parser2.c \
			readdir.c \
			readdir2.c \
			sortargv.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

INCLUDES := -I./include/ -I./libft/include/

PATH_LIB = ./libft/

LIB = $(PATH_LIB)libft.a

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

TEST_PATH := ./tools/

TEST_TOOL := perl $(addprefix $(TEST_PATH),test-ls.pl)

TEST_INPUT := $(addprefix $(TEST_PATH),input-ls)
