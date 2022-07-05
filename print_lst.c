#include "push_swap.h"

void	print_lst(t_list *a, t_list *b)
{
	t_list *temp;
	
	temp = a->next;
	while (temp != NULL)
	{
		printf("A position: (%d) ", temp->position);
		printf("content: %d\n", temp->content);
		temp = temp->next;
	}
	temp = b->next;
	while (temp != NULL)
	{
		printf("B position: (%d) ", temp->position);
		printf("content: %d\n", temp->content);
		temp = temp->next;
	}
	
}
