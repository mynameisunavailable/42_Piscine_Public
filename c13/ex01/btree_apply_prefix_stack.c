#include "ft_btree.h"

#define STACKSIZE 1024

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	t_btree	*stack[STACKSIZE];
	int		i;
	
	i = 0;
	stack[i] = 0;
	i++;
	while (root && (i < (STACKSIZE - 1)))
	{
		applyf(root->item);
		if ((root->right))
		{
			stack[i] = root->right;
			i++;
		}
		if (root->left)
		{
			root = root->left;
		}
		else
		{
			i--;
			root = stack[i];
		}
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
	*(int *) item = *(int *) item + 1;
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
	t_btree	*one = make_node("1");
	t_btree	*two = make_node("2");
	t_btree	*thr = make_node("3");
	t_btree	*four = make_node("4");
	t_btree	*fiv = make_node("5");
	t_btree	*six = make_node("6");
	one->left = two;
	one->right = thr;
	two->left = four;
	two->right = fiv;
	thr->left = six;

	btree_apply_prefix(one, applyf);
	printf("%s\n", one->item);
	printf("%s\n", six->item);
	return (0);
}