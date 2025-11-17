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