#include "libft.h"

void	btree_apply_prefix(t_btree *root, void (*apply)(void *))
{
	if (!root)
		return ;
	(*apply)(root->item);
	btree_apply_prefix(root->left, apply);
	btree_apply_prefix(root->right, apply);
}
