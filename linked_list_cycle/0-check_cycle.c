#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to a pointer of the start of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
    listint_t *current = list;
    listint_t *following_node = list;

    while (following_node != NULL && following_node->next != NULL)
    {
        current = current->next;
        following_node = following_node->next->next;

        if (current == following_node)
            return 1;
    }

    return 0;
}
