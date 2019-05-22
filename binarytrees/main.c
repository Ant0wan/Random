#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "ft_btree.h"
#include "ft_btree_rb.h"

void	applylevel(void *data, int current_level, int is_first_elem){
	printf("%s, %d, %d\n", (char*)data, current_level, is_first_elem);}
void	rbapplylevel(void *data, int current_level, int is_first_elem, int color){
	printf("%s, l:%d, %d, c:%d\n", (char*)data, current_level, is_first_elem, color);}
void donothing(void *ptr){printf("%s\n", (char*)ptr);}
int		sup(int *a, int *b){return (*a - *b);}

void            rb_apply_by_level(t_rb_node *root, void (*applyf)(void *item,
			int current_level, int is_first_elem, int color));

int main(void)
{
	// left, right, parent, data, color
	int			on = 1, el = 11, tw = 2, fo = 4, fi = 5, sev = 7, eig = 8, fourt = 14, fivte = 15;
	t_rb_node	one = {NULL, NULL, &on, &two, RB_BLACK},
				two = {&one, &seven, &eleven, &tw, RB_RED},
				four = {NULL, NULL, &five, &fo, RB_RED},
				five = {&four, NULL, &seven, &fi, RB_RED},
				seven = {&five, &eight, &two, &sev, RB_BLACK},
				eight = {NULL, NULL, &seven, &eig, RB_RED},
				eleven = {&two, &fourteen, NULL, &el, RB_BLACK},
				fourteen = {NULL, &fiveteen, &eleven, &fourt, RB_BLACK},
				fiveteen = {NULL, NULL, &fourteen, &fivte, RB_RED};

	int	s = 4;
	t_rb_node	*root;

	root = NULL;
	rb_insert(&root, (void*)&s, (int (*)(void*, void*))&sup);
	

	printf("\n\n");
	//btree_apply_by_level((t_btree*)root, applylevel);
//	rb_apply_by_level(root, rbapplylevel);
//	rotation(&root, &c, 1);
//	rotation(&root, &d, 0);
//	printf("\n\n");
//	rb_apply_by_level(root, rbapplylevel);
//	printf("\n\n");
//	set_color(d.right, 1);
//	rb_apply_by_level(root, rbapplylevel);

	return (0);
}
