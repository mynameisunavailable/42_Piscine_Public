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

t_btree *btree_create_node(void *item);

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	t_stack	stack_l;
	t_stack	stack_r;
	int		right;
	
	right = 1;
	initialise_stack(&stack_l);
	initialise_stack(&stack_r);
	do
	{
		while (root && right == 1)
		{
			load_stack(&stack_l, root);
			if (root->right)
			{
				load_stack(&stack_r, root->right);
			}
			root = root->left;
		}
		print_stack(&stack_l);
		print_stack(&stack_r);
		if ((stack_r.i))
		{
			root = push_stack(&stack_r);
			right = 1;
		}
		else
		{
			root = push_stack(&stack_l);
			applyf(root->item);
			right = 0;
		}
	} while (stack_l.i > 0 || stack_r.i > 0);
}
// void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
// {
// 	t_stack	stack_l;
// 	t_stack	stack_r;
// 	t_btree	*tempnull;

// 	tempnull = btree_create_node("0");
// 	initialise_stack(&stack_l);
// 	initialise_stack(&stack_r);
// 	// load_stack(&stack_l, root);
// 	// root = root->left;
// 	do
// 	{
// 		while (root)
// 		{
// 			// printf("load: %s\n", root->item);
// 			load_stack(&stack_l, root);
// 			if (root->right)
// 			{
// 				load_stack(&stack_r, root->right);
// 			}
// 			root = root->left;
// 		}
// 		print_stack(&stack_l);
// 		print_stack(&stack_r);
// 		root = push_stack(&stack_l);
// 		printf("process: %s\n", root->item);
// 		if (!(root->left))
// 		{
// 			applyf(root->item);
// 			root = push_stack(&stack_r);
// 		}		
// 		else
// 		{
// 			print_stack(&stack_l);
// 			print_stack(&stack_r);
// 			root = push_stack(&stack_r);
// 			printf("process: %s\n", root->item);
// 			applyf(root->right->item);
// 			// root = push_stack(&stack_l);
// 			root = tempnull;
// 		}
// 	} while ((stack_l.i > 0) || (stack_r.i > 0));
// }

// if (root->left)
// {
// 	applyf(root->left->item);
// }
// if (root->right)
// {
// 	applyf(root->right->item);
// }


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