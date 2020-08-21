#ifndef WC_H
# define WC_H

# include "help.h"

struct file
{
	const char	*filename;
	struct file	*next;
};

struct argument
{
	struct file	*files; /* Filenames used as arguments */
	unsigned char	c;   /* bytes */
	unsigned char	m;   /* chars */
	unsigned char	l;   /* lines */
	unsigned char	upl; /* max display */
	unsigned char	w;   /* words */
};

extern struct argument	arguments;

struct wc
{
	int	bytes;
	int	chars;
	int	words;
	int	lines;
};

int	parse_arguments(int argc, char **argv);

#endif
