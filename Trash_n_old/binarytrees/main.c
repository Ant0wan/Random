#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "ft_btree.h"
#include "ft_btree_rb.h"

void	applylevel(void *data, int current_level, int is_first_elem){
	printf("%s, %d, %d\n", (char*)data, current_level, is_first_elem);}
//void	rbapplylevel(void *data, int current_level, int is_first_elem, int color){
//	printf("%s, l:%d, %d, c:%d\n", (char*)data, current_level, is_first_elem, color);}
void	rbapplylevel(void *data, int current_level, int is_first_elem, int color){
	printf("%d, l:%d, %d, c:%d\n", *(int*)data, current_level, is_first_elem, color);}
void donothing(void *ptr){printf("%s\n", (char*)ptr);}
//int		sup(int *a, int *b){return (*a - *b);}

void            rb_apply_by_level(t_rb_node *root, void (*applyf)(void *item,
			int current_level, int is_first_elem, int color));

int main(void)
{
	// left, right, parent, data, color
	int			on = 1, el = 11, tw = 2, fo = 4, fi = 5, sev = 7, eig = 8, fourt = 14, fivte = 15;
	t_rb_node	fourteen, fiveteen, two, one, four, five, seven, eight, eleven;
	
	fourteen =	(t_rb_node){NULL, &fiveteen, &eleven, &fourt, RB_BLACK};
	fiveteen =	(t_rb_node){NULL, NULL, &fourteen, &fivte, RB_RED};
	two =		(t_rb_node){&one, &seven, &eleven, &tw, RB_RED};
	one =		(t_rb_node){NULL, NULL, &two, &on, RB_BLACK};
	four =		(t_rb_node){NULL, NULL, &five, &fo, RB_RED};
	five =		(t_rb_node){&four, NULL, &seven, &fi, RB_RED};
	seven =		(t_rb_node){&five, &eight, &two, &sev, RB_BLACK};
	eight =		(t_rb_node){NULL, NULL, &seven, &eig, RB_RED};
	eleven =	(t_rb_node){&two, &fourteen, NULL, &el, RB_BLACK};

//	int	s = 4;
	t_rb_node	*root;

	root = &eleven;
//	rb_insert(&root, (void*)&s, (int (*)(void*, void*))&strcmp);
	

	printf("\n\n");
//	rb_apply_by_level(root, rbapplylevel);
	rb_apply_by_level(root, rbapplylevel);
	rotation(&root, &seven, 0);
//	rotation(&root, &eleven, 1);
	printf("\n\n");
//	set_color(&four, 0);
	rb_apply_by_level(root, rbapplylevel);

	return (0);
}
