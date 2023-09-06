#include <stdio.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;



char	c;
c = 'C';



char	*str;
str = (char *)malloc(sizeof(char) * 2);
str[0] = c;
str[1] = '\0';



int	main(void)
{
	t_node first;
	t_node second;
	t_node third;

	first.num = 1;
	first.next = &second;
	second.num = 2;
	second.next = &third;
	third.num = 3;
	third.next = NULL;

}

int	main(void)
{
	t_node *first;
	t_node *second;
	t_node *third;

	first = (t_node *)malloc(sizeof(t_node));
	second = (t_node *)malloc(sizeof(t_node));
	third = (t_node *)malloc(sizeof(t_node));

	first->num = 1;
	first->next = second;
	second->num = 2;
	second->next = third;
	third->num = 3;
	third->next = NULL;
}