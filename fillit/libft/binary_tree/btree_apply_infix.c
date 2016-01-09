#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*apply)(void *))
{
	if (!root)
		return ;
	btree_apply_prefix(root->left, apply);
	(*apply)(root->item);
	btree_apply_prefix(root->right, apply);
}
