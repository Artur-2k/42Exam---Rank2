void ft_swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int j = 0;
	int swaped = 0;

	while (i < size - 1)
	{
		swaped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swaped = 1;
			}
			j++;
		}
		if (!swaped)
			break ;
		i++;
	}
}
