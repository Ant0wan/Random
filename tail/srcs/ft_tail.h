#ifndef __FT_TAIL_H_
#	define __FT_TAIL_H_

#define ERRMSG_1 "tail: "
#define ERRMSG_2 "cannot open \'"
#define ERRMSG_3 "\' for reading: No such file or directory"
#define ERRMSG_4 "error reading \'"
#define ERRMSG_5 "\' Is a directory"

/*
** Function prototypes
*/

void	ft_putstr(char *str);

void	ft_input_term(void);

void	ft_tail(char *file_name);

#endif
