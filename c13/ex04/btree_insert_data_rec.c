#include <stdlib.h>
#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	new->item = item;
	new->left = 0;
	new->right = 0;
	return (new);
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}


#include <stdlib.h>
#include <stdio.h>

void	applyf(void *item)
{
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

	btree_apply_infix(one, applyf);
	// printf("%s\n", one->item);
	// printf("%s\n", six->item);
	return (0);
}