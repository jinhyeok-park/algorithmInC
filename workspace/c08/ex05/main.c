#include "ft_strs_to_tab.c"
#include "ft_show_tab.c"

int		main(int ac,char *av[])
{

	struct s_stock_str *str;
	str = ft_strs_to_tab(ac, av);
	ft_show_tab(str);
	return 0;
}


