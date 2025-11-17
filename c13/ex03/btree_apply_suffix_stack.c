#include "ft_btree.h"

#define STACKSIZE 1024

typedef struct s_stack
{
	t_btree	*stack[STACKSIZE];
	int		i;
}	t_stack;

int	initialise_stack(t_stack *new)
{
	new->i = 0;
	return (0);
}

void	load_stack(t_stack *new, void *stuff)
{
	if (new->i >= STACKSIZE)
	{
		return ;
	}
	new->stack[new->i] = stuff;
	new->i++;
}

void	*push_stack(t_stack *new)
{
	if (new->i == 0)
		return (0);
	new->i--;
	return new->stack[new->i];
}


void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	t_stack	stack_r;
	t_stack	stack_f;
	
	initialise_stack(&stack_r);
	initialise_stack(&stack_f);
	load_stack(&stack_r, root);
	while (stack_r.i > 0)
	{
		root = push_stack(&stack_r);
		if (root->left)
		{
			load_stack(&stack_r, root->left);
		}
		if (root->right)
		{
			load_stack(&stack_r, root->right);
		}
		load_stack(&stack_f, root);
	}
	while (stack_f.i > 0)
	{
		root = push_stack(&stack_f);
		applyf(root->item);
	}	
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

void	applyf(void *item)
{
	printf("%s\n", item);
	((char *)item)[1] = ((char *)item)[1] + 1;
}

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

#include <stdio.h>//
void	print_stack(t_stack *new)
{
	int	c;

	c = 0;
	printf("i = %d: ", new->i);
	while (c < new->i && new->stack[c])
	{
		printf("%s, ", new->stack[c]->item);
		c++;
	}
	printf("\n");
}

int main()
{
	t_btree	*one = make_node("10");
	t_btree	*two = make_node("20");
	t_btree	*thr = make_node("30");
	t_btree	*four = make_node("40");
	t_btree	*fiv = make_node("50");
	t_btree	*six = make_node("60");
	one->left = two;
	one->right = thr;
	two->left = four;
	two->right = fiv;
	thr->left = six;

	btree_apply_suffix(one, applyf);
	printf("%s\n", one->item);
	printf("%s\n", six->item);
	return (0);
}