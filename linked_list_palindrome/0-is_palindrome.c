#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome_helper - Recursively checks if a singly linked list is a
 * palindrome.
 *
 * @start: Pointer to the head of the list
 * @end: Pointer used to traverse the list to the end
 * 
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome_helper(listint_t **start, listint_t *end)
{
    if (end == NULL)
        return 1;

    if (!helper(start, end->next))
        return 0;

    if ((*start)->n != end->n)
        return 0;

    *start = (*start)->next;

    return 1;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 *
 * @head: Double pointer to the head of the list
 * 
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return 1;

    return helper(head, *head);
}
