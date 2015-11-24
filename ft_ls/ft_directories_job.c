#include "ft_ls.h"

char	**ft_sort_map_by_ascii(char **map)
{
	int j;
	int i;

	j = 0;
	while (map[j])
	{
		i = j + 1;
		while (map[i])
		{
			if (ft_strcmp(map[j], map[i]) > 0)
				ft_strswap(&map[j], &map[i]);
			i++;
		}
		j++;	
	}
	return (map);
}

char	**ft_sort_map_by_ascii_reverse(char **map)
{
	int j;
	int i;

	j = 0;
	while (map[j])
	{
		i = j + 1;
		while (map[i])
		{
			if (ft_strcmp(map[j], map[i]) < 0)
				ft_strswap(&map[j], &map[i]);
			i++;
		}
		j++;	
	}
	return (map);
}

char	**ft_create_map(int i, int argc, char **argv, char *flag)
{
	char **map;
	int j;
	
	j = 0;
	map = (char**)malloc(sizeof(*map) * (g_targets_number + 1)); //not the best, but works
	while (i < argc)
	{
		map[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	map[j] = 0;
//	j = 0;
	map = ft_sort_map_by_ascii(map);
	if (ft_check_if_flag_contains(flag, 'r') == 1)
		map = ft_sort_map_by_ascii_reverse(map);
	return (map);
}

void	ft_directories_job(int i, int argc, char **argv, char *flag)
{
	char **map;
	int j;

	map = ft_create_map(i, argc, argv, flag);
	j = 0;
	while (map[j])
	{
		ft_work_with_d(map[j], flag);
		j++;
	}
}
