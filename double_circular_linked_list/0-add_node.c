#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * Return: the address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last_node;
	char *copy_str;

	if (!list || !str)
		return (NULL);

	copy_str = strdup(str);
	if (!copy_str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
	{
		free(copy_str);
		return (NULL);
	}

	new_node->str = copy_str;

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		last_node = (*list)->prev;
		new_node->next = *list;
		new_node->prev = last_node;
		last_node->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

 /**
 * add_node_begin - Add a new node to the beginning of a double circular
 *                  linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * Return: the address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = add_node_end(list, str);
	if (!new_node)
		return (NULL);

	*list = new_node;

	return (new_node);
}
