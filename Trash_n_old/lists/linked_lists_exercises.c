#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_list t_list;

struct          s_list
{
  void  *data;
  t_list  *next;
};

t_list  *ft_create_elem(void *data)
{
  t_list  *list;

  list = (t_list*)malloc(sizeof(*list));
  if (list)
  {
    list->data = data;
    list->next = NULL;
  }
  return (list);
}

void  print_list(t_list *list)
{
  t_list *a;

  a = list;
  while (a->next)
  {
    printf(" addr: %d\n", a);
    printf(" data: %s\n", a->data);
    printf(" next: %d\n\n", a->next);
    a = a->next;
  }
  printf(" addr: %d\n", a);
  printf(" data: %s\n", a->data);
  printf(" next: %d\n\n", a->next);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
  t_list  *list;

  if (*begin_list)
  {
      list = *begin_list;
      while (list->next)
        list = list->next;
      list->next = ft_create_elem(data);
  }
  else
    *begin_list = ft_create_elem(data);
}

void  ft_list_push_front(t_list **begin_list, void *data)
{
  t_list  *list;

  if (*begin_list)
  {
     list = ft_create_elem(data);
     list->next = *begin_list;
     *begin_list = list;
  }
  else
  {
    *begin_list = ft_create_elem(data);
  }
}

int ft_list_size(t_list *begin_list)
{
  int i;
  t_list  *list;

  i = 0;
  if (begin_list)
  {
    i = 1;
    list = begin_list;
    while (list->next)
    {
     list = list->next;
     i++;
    }
  }
  return (i);
}

t_list  *ft_list_last(t_list *begin_list)
{
  t_list  *list;

  if (begin_list)
  {
    list = begin_list;
    while (list->next)
      list = list->next;
  }
  return (list);
}

t_list *ft_list_push_params(int ac, char **av)
{
  t_list  *list;
  int     i;

  i = 1;
  list = NULL;
  while (i < ac)
  {
    ft_list_push_front(&list, av[i]);
    i++;
  }
  return (list);
}


void ft_list_clear(t_list **begin_list)
{
  if (*begin_list)
  {
    ft_list_clear(&(*begin_list)->next);
    free(*begin_list);
    *begin_list = NULL;
  }
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
  unsigned int i;
  t_list *list;

  i = 0;
  if (begin_list && nbr > 0)
  {
    list = begin_list;
    while (list)
    {
      i++;
      list = list->next;
    }
    if (i < nbr)
      return NULL;
    else
    {
      i = 0;
      list = begin_list;
      while (i < nbr - 1)
      {
        i++;
        list = list->next;
      }
      return list;
    }
  }
  else
    return NULL;  
}

void ft_list_reverse(t_list **begin_list)
{
  t_list  *l_previous;
  t_list  *l_next;

  if ((*begin_list)->next)
  {
    l_previous = NULL;
    while (*begin_list)
    {
      l_next = (*begin_list)->next;
      (*begin_list)->next = l_previous;
      l_previous = *begin_list;
      *begin_list = l_next;
    }
    *begin_list = l_previous;
  }
}

void  function_f(void *data)
{
  printf("%s,\n", data);
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
  t_list  *list;

  if (begin_list)
  {
    list = begin_list;
    while (list)
    {
      f(list->data);
      list = list->next;
    }
  }
}

int f_cmp(char *s1, char *s2)
{
  return strcmp(s1, s2);
}

void  ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
  t_list  *list;

  if (begin_list)
  {
    list = begin_list;
    while (list)
    {
      if (cmp(list->data, data_ref) == 0)
        f(list->data);
      list = list->next;
    }
  }
}

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
  t_list  *list;

  if (begin_list)
  {
    list = begin_list;
    while (list)
    {
      if (cmp(list->data, data_ref) == 0)
        return (list);
      list = list->next;
    }
  }
  return (NULL);
}

void  ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
  t_list  *list;
  t_list  *previous;

  if (*begin_list)
  {
    list = *begin_list;
    previous = *begin_list;
    while (list)
    {
      if (cmp(list->data, data_ref) == 0)
      {
        if (previous == *begin_list && list == *begin_list)
          *begin_list = list->next;
        else
          previous->next = list->next;
        free(list);
      }
      previous = list;
      list = list->next;
    }
  }
}

void  ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
  t_list  *list;

  if (*begin_list1 && begin_list2)
  {
    list = *begin_list1;
    while ((*begin_list1)->next)
      *begin_list1 = (*begin_list1)->next;
    (*begin_list1)->next = begin_list2;
    *begin_list1 = list;
  }
  else if (!*begin_list1 && begin_list2)
    *begin_list1 = begin_list2;
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
  t_list  *list;
  t_list  *tmp;
  int     diff;

  list = *begin_list;
  diff = 1;
  while (diff > 0)
  {
    diff = 0;
    while ((*begin_list)->next)
    {
      if (cmp((*begin_list)->data, (*begin_list)->next->data) > 0)
      {
       tmp = (*begin_list)->data;
       (*begin_list)->data = (*begin_list)->next->data;
       (*begin_list)->next->data = tmp;
       diff++; 
      }
      *begin_list = (*begin_list)->next;
    }
    *begin_list = list;
  }
}

void ft_list_reverse_fun(t_list *begin_list)
{
  int     i;
  int     k;
  int     j;
  t_list  *list;
  t_list  *ref;
  t_list  *tmp;

  i = 0;
  ref = begin_list;
  list = ref;
  while (begin_list && ++i)
    begin_list = begin_list->next;
  begin_list = ref;
  j = i;
  while (i > j / 2)
  {
    k = 0;
    while (k < i - 1)
    {
      list = list->next;
      k++;
    }
    tmp = begin_list->data;
    begin_list->data = list->data;
    list->data = tmp;
    i--;
    list = ref;
    begin_list = begin_list->next;
  }
}

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
  t_list  *list;
  t_list  *tmp;
  t_list  *l_new;

  list = *begin_list;
  tmp = list;
  while (list)
  {
    if ((cmp(list->data, data) > 0 && (cmp(tmp->data, data) < 0 || cmp(tmp->data, data) == 0))
    || (tmp == list && cmp(list->data, data) > 0)
    || (cmp(list->data, data) <= 0 && list->next == NULL))
    {
      l_new = ft_create_elem(data);
      if (cmp(list->data, data) <= 0 && list->next == NULL)
      {
        l_new->data = data;
        list->next = l_new;
        return ;
      }
      l_new->next = list;
        if (tmp == list)
          *begin_list = l_new;
        else
          tmp->next = l_new;
    }
    tmp = list;
    list = list->next;
  }
}

void  ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
  ft_list_merge(begin_list1, begin_list2);
  ft_list_sort(begin_list1, cmp);
}

int main(int ac, char **av)
{
  t_list  *list;
  t_list  *list2;

  (void)ac;
  (void)av;
  //list = ft_create_elem("Tata");
  //ft_list_push_back(&list, "Titi");
  //ft_list_push_back(&list, "hahaha Tutu dernier");
  //ft_list_push_front(&list, "C'est moi le premier !");  
//  print_list(list);
 // printf("Nb element in list: %d", ft_list_size(list));
   // list = ft_list_push_params(ac, av);
    //print_list(list);
   // ft_list_clear(&list);
   // printf("%d\n", list);
   // print_list(list);
   //printf("*************\n\n");
   //list = ft_list_at(list, 4);
   //printf("%s", list->data);
   //ft_list_reverse(&list);
   //printf("\n***********\n\n");
   //print_list(list);
   // ft_list_foreach(list, &function_f);
   // ft_list_foreach_if(list, &function_f, "Titi", &f_cmp);
   //print_list(ft_list_find(list, "Titi", &f_cmp));
   //ft_list_remove_if(&list, "Titi", &f_cmp);
   //print_list(list);
   list2 = ft_create_elem("Papa");
  ft_list_push_back(&list2, "Pipi");
  ft_list_push_back(&list2, "Pupu");
  ft_list_push_front(&list2, "kawaaa");
  ft_list_merge(&list, list2);
   //print_list(list);
     list = ft_create_elem("aa");
    ft_list_push_back(&list, "aab");
    ft_list_push_back(&list, "ok1");
    ft_list_push_back(&list, "aaa");
    ft_list_push_front(&list, "aaba");
    //ft_list_sort(&list, f_cmp);
    //print_list(list);
    //printf("\n**************\n\n");
    //ft_list_reverse_fun(list);
    //print_list(list);
    //ft_list_sort(&list, &f_cmp);
    //ft_sorted_list_insert(&list, "ok1", &f_cmp);
    //print_list(list);
    ft_sorted_list_merge(&list, list2, &f_cmp);
    print_list(list);

  return (0);
}