#include "ft_btree.h"

#define STACKSIZE 1024

int ft_max(int n1, int n2)
{
    if (n1 < n2)
        return (n2);
    return (n1);
}

typedef struct s_bt_level
{
	int		i;
	int		cur;
	int		res;
	t_btree	*stack[STACKSIZE];
	int		stack_cur[STACKSIZE];
}	t_bt_level;


void	initialise_var(t_bt_level *s)
{
	s->i = 0;
	s->cur = 0;
	s->res = 0;
	s->stack[s->i] = 0;
	s->stack_cur[s->i] = 0;
	s->i += 1;
}

#include <stdio.h>

int	btree_level_count(t_btree *root)
{
	t_bt_level	s;

	initialise_var(&s);
	while (root && (s.i < STACKSIZE - 1))
	{
		s.cur += 1;
		s.res = ft_max(s.cur, s.res);
		if ((root->right))
		{
			s.stack[s.i] = root->right;
			s.stack_cur[s.i] = s.cur;
			s.i++;
		}
		if (root->left)
			root = root->left;
		else
		{
			s.i--;
			root = s.stack[s.i];
			s.cur = s.stack_cur[s.i];
		}
	}	
	return (s.res);
}



#include <stdlib.h>
#include <stdio.h>

t_btree *btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	new->item = item;
	new->left = 0;
	new->right = 0;
	return (new);
}

// void	applyf(void *item)
// {
// 	*(int *) item = *(int *) item + 1;
// }

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
    char *dest_start;
    
    dest_start = dest;
    while(*src)
        *dest++ = *src++;
    *dest = '\0';
    return(dest_start);
}

t_btree	*make_node(void *item)
{
	char	*str = ft_strdup(item);
	return btree_create_node(str);
}

int main()
{
	t_btree	*one = make_node("1");
	t_btree	*two = make_node("2");
	t_btree	*thr = make_node("3");
	t_btree	*four = make_node("4");
	t_btree	*fiv = make_node("5");
	t_btree	*six = make_node("6");
	t_btree	*sev = make_node("7");
	one->left = two;
	one->right = thr;
	two->left = four;
	two->right = fiv;
	thr->left = six;
	four->left = sev;
	// 
	// one->left = two;
	// two->left = four;

	printf("%d", btree_level_count(one));
	// printf("%s\n", one->item);
	// printf("%s\n", six->item);
	return (0);
}