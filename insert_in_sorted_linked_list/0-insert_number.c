#include "lists.h"

/**
 * insert_node - a function that inserts a number into
 * a sorted singly linked list.
 * @head: a pointer to pointer of the first node of listint_t list.
 * @number: an integer.
 * Return: the address of the new node, or NULL if it failed.
 */

 listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current_node, *next_node;
    int temp;

    new_node = add_nodeint_end(head, number);
    if (new_node == NULL || *head == NULL)
        return NULL;

    for (current_node = *head;
        current_node != NULL; current_node = current_node->next) {
        for (next_node = current_node->next;
            next_node != NULL; next_node = next_node->next) {
            if (current_node->n > next_node->n) {
                temp = current_node->n;
                current_node->n = next_node->n;
                next_node->n = temp;
            }
        }
    }

    return new_node;
}
