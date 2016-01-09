#include "libft.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void *))
{
	if (!root)
		return ;
	btree_apply_prefix(root->left, apply);
	btree_apply_prefix(root->right, apply);
	(*apply)(root->item);
}
