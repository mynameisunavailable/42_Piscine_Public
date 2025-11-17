#ifndef FT_BTREE_H
#define FT_BTREE_H

typedef struct s_btree
{
	void	*item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif