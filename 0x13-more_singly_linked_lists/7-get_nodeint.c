#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth
 * node of a listint_t linked list
 * @head: pointer of listint_t
 * @index:  index of the node, starting at 0
 * Return: returns the nth node of a listint_t linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp ? temp : NULL);
}

