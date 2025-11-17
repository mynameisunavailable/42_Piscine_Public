#include "ft_btree.h"

#define QUEUESIZE 1024

typedef	struct s_circular_buffer
{
	t_btree	*buf[QUEUESIZE];
	int		buf2[QUEUESIZE];
	int		size;
	int		front;
	int		back;
	int		(*enqueue)(struct s_circular_buffer *, void *, int);
	int		(*dequeue)(struct s_circular_buffer *);
} t_cir_buffer;

int	enqueue(t_cir_buffer *queue, void *new, int num)
{
	if (queue->size == QUEUESIZE)
		return (999);
	queue->buf[queue->back] = new;
	queue->buf2[queue->back] = num;
	queue->back = (queue->back + 1) % QUEUESIZE;
	queue->size++;
	return (0);
}

int	dequeue(t_cir_buffer *queue)
{
	int	temp;
	
	if (queue->size <= 0)
		return (-1);
	temp = queue->front;
	queue->front = (queue->front + 1) % QUEUESIZE;
	queue->size--;
	return (temp);
}

int	initialise_cirbuf(t_cir_buffer *new)
{
	new->size = 0;
	new->front = 0;
	new->back = 0;
	new->enqueue = enqueue;
	new->dequeue = dequeue;
	return (0);
}

int	check_depth(int depth, int *prev_depth)
{
	int	first_ele;

	if (*prev_depth != depth)
	{
		first_ele = 1;
		*prev_depth = depth;
	}
	else
	{
		first_ele = 0;
	}
	return (first_ele);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_cir_buffer	queue;
	t_btree			*curr;
	int				i;
	int				depth;
	int				prev_depth;

	if (!root)
		return ;
	initialise_cirbuf(&queue);
	prev_depth = -1;
	queue.enqueue(&queue, root, 0);
	while (queue.size > 0)
	{
		i = queue.dequeue(&queue);
		curr = queue.buf[i];
		depth = queue.buf2[i];
		applyf(curr->item, depth, check_depth(depth, &prev_depth));
		if (curr->left)
			queue.enqueue(&queue, curr->left, depth + 1);
		if (curr->right)
			queue.enqueue(&queue, curr->right, depth + 1);
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

	btree_apply_level_order(one, applyf);
	printf("%s\n", one->item);
	printf("%s\n", six->item);
	return (0);
}