#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
				int (*cmpf)(void *, void *))
{
	void	*item;

	if (!root)
		return (NULL);
	item = btree_search_item(root->left, data_ref, cmpf);
	if (item)
		return (item);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
