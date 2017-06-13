
#include <stdio.h>

void	ft_print(void)
{
	static int	i = 0;

	printf("the number is:%d\n", i++);
}

int main(void)
{
	for (int i = 0;i < 10;i++)
		ft_print();
	return (0);
}
