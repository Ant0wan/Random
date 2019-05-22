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

void            rb_apply_by_level(t_rb_node *root, void (*applyf)(void *item,
			int current_level, int is_first_elem, int color));

/*	    	TEST UNBALANCED BINARY TREE
 *				
 *					c		
 *			     b	   d	
*/

int main(void)
{
	t_rb_node	b, c, d;

	c.left = &b;
	c.right = &d;
	c.data = "c";
	c.parent = NULL;
	c.color = RB_BLACK;
	b.left = NULL;
	b.right = NULL;
	b.data = "b";
	b.color = RB_RED;
	b.parent = &c;
	d.left = NULL;
	d.right = NULL;
	d.data = "d";
	d.color = RB_RED;
	d.parent = &c;

	char	*s = "e";
//	char	*s = "e", *s1 = "a", *s2 = "b", *s3 = "c", *s4 = "d", *s5 = "e";
//	char	*s6 = "f", *s7 = "g", *s8 = "h";

	t_rb_node	*root;
	root = &c;
	
	rb_insert(&root, (void*)s, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s1, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s2, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s3, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s4, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s5, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s6, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s7, (int (*)(void*, void*))&strcmp);
//	rb_insert(&root, (void*)s8, (int (*)(void*, void*))&strcmp);
	
/*	    	TEST UNBALANCED BINARY TREE
 *				
 *					c(b)		
 *			     b(r)	d(r)	
 *			     		  e(b)
*/

	printf("\n\n");
	//btree_apply_by_level((t_btree*)root, applylevel);
	rb_apply_by_level(root, rbapplylevel);
	rotation(&root, &c, 1);
	rotation(&root, &d, 0);
	printf("\n\n");
	rb_apply_by_level(root, rbapplylevel);
	printf("\n\n");
	set_color(d.right, 1);
	rb_apply_by_level(root, rbapplylevel);

	return (0);
}
