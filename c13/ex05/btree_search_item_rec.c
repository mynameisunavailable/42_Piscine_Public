#include "ft_btree.h"

// void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(char *, char *))
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*res;
	
	res = 0;
	if (!root)
	{
		return (0);
	}	
	if (root->left)
	{
		res = btree_search_item(root->left, data_ref, cmpf);
	}
	if (res != 0)
	{
		return (res);
	}	
	if (cmpf(root->item, data_ref) == 0)
	{
		return (root->item);
	}
	if (res != 0)
	{
		return (res);
	}	
	if (root->right)
	{
		res = btree_search_item(root->right, data_ref, cmpf);
	}	
	if (res != 0)
	{
		return (res);
	}
	return (0);
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
	*(int *) item = *(int *) item + 1;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
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

	void *str = btree_search_item(one, "3", ft_strcmp);
	printf("%s\n", str);
	// printf("%s\n", six->item);
	return (0);
}