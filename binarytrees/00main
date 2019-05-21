#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "ft_btree.h"
#include "ft_btree_rb.h"

/*	    	TEST UNBALANCED BINARY TREE
 *				
 *					d		
 *				b		f	
 *			  a  c    e    h
 *						 g   i
 *								j
*/

void	applylevel(void *item, int current_level, int is_first_elem){
	printf("%s, %d, %d\n", (char*)item, current_level, is_first_elem);}

void	donothing(void *ptr){printf("%s\n", (char*)ptr);}

int main(void)
{
	char	*str;
	t_btree	a;
	t_btree	b;
	t_btree	c;
	t_btree	d;
	t_btree	e;
	t_btree	f;
	t_btree	g;
	t_btree	h;
	t_btree	i;
	t_btree	j;

	str = "Hello !";
	a.left = NULL;
	a.right = NULL;
	a.item = "a";
	b.left = &a;
	b.right = &c;
	b.item = "b";
	c.left = NULL;
	c.right = NULL;
	c.item = "c";
	d.left = &b;
	d.right = &f;
	d.item = "d";
	e.left = NULL;
	e.right = NULL;
	e.item = "e";
	f.left = &e;
	f.right = &h;
	f.item = "f";
	g.left = NULL;
	g.right = NULL;
	g.item = "g";
	h.left = &g;
	h.right = &i;
	h.item = "h";
	i.left = NULL;
	i.right = &j;
	i.item = "i";
	j.left = NULL;
	j.right = NULL;
	j.item = "j";

	//btree_apply_prefix(&d, &donothing);
	//btree_apply_infix(&d, &donothing);
	//btree_apply_suffix(&d, &donothing);
	char	*s = "g";
	char	*s1 = "a";
	char	*s2 = "z";
	char	*s3 = "g";
	char	*s4 = "g";
	char	*s5 = "g";
	char	*s6 = "g";
	char	*s7 = "g";
	char	*s8 = "g";
//	char	*s9 = "j";
	t_btree	*root;
	root = &d;
	//root = NULL;
	btree_insert_data(&root, (void*)s, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s1, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s2, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s3, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s4, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s5, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s6, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s7, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	btree_insert_data(&root, (void*)s8, (int (*)(void*, void*))&strcmp);
//	root = &d;
//	printf("\n\n");
//	t_btree	*ptr;
//	ptr = btree_search_item(&d, (void*)s9, (int (*)(void*, void*))&strcmp);
//	printf("%p\n", ptr);
//	printf("%p\n", s2);
//	printf("returned: %s\n", (char*)(ptr->item));

//	if (((t_btree*)ptr)->item)
//	{
//		printf("TT");
//	//	printf("found:%s\n", (char*)(ptr->item));
//	}
	//btree_apply_infix(&d, &donothing);
	//btree_apply_prefix(&d, &donothing);
/*	    	TEST UNBALANCED BINARY TREE AFTER INSERTS
 *				
 *					d		
 *				b		f	
 *			  a  c    e    h
 *			a			 g   i
 *						g		j
 *					   g         z
 *					  g
 *					 g
 *					g
 *				   g
*/
	printf("\n\n");
	//printf("level max:%d\n", btree_level_count(&d));
	btree_apply_by_level(root, applylevel);

	return (0);
}
