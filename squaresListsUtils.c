#include "squares.h"

/**
* Frees the whole list
*
* @param {t_squares *} lst = the list of squares to free
*/
void		squaresListFree(t_squares *lst)
{
	t_squares		*ptr;

	while (lst != NULL)
	{
		ptr = lst;
		lst = lst->next;
		free_safe((void**)&(ptr));
	}
}

/**
* Creates a new link to add to the chained list of squares
*
* @param {t_pointsList *} A = point A
* @param {t_pointsList *} A = point B
* @param {t_pointsList *} A = point C
* @param {t_pointsList *} A = point D
* @returns {t_squares	*} newlink = returns the new link made from the input data
*/
t_squares	*squaresListNew(t_pointsList *A, t_pointsList *B, t_pointsList *C, t_pointsList *D)
{
	t_squares	*newlink;

	if (!(newlink = wrmalloc(sizeof(t_squares))))
		return (NULL);
	newlink->A[0] = A->x;
	newlink->A[1] = A->y;
	newlink->B[0] = B->x;
	newlink->B[1] = B->y;
	newlink->C[0] = C->x;
	newlink->C[1] = C->y;
	newlink->D[0] = D->x;
	newlink->D[1] = D->y;
	newlink->next = NULL;
	return (newlink);
}

/**
* Goes through the list to find the last link
*
* @param {t_squares *} lst = the list of squares
* @returns {t_squares *} tmp = the last link of the input list
*/
t_squares	*squaresListFindLast(t_squares *lst)
{
	t_squares *tmp;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/**
* Adds a link to the end of the input list
*
* @param {t_squares **} lst = a pointer to the list of squares
* @param {t_squares *} new = the new link to add to the list
*/
void		squaresListAddBack(t_squares **lst, t_squares *new)
{
	if (!*lst)
		*lst = new;
	else
		squaresListFindLast(*lst)->next = new;
}