#include "squares.h"

/**
* Frees the whole list
*
* @param {t_pointsList *} lst = the list of points from the input file to free
*/
void			pointsListFree(t_pointsList *lst)
{
	t_pointsList		*ptr;

	while (lst != NULL)
	{
		ptr = lst;
		lst = lst->next;
		free_safe((void**)&(ptr));
	}
}

/**
* Creates a new link to add to the chained list of points
*
* @param {int} x = the abscissa
* @param {int} y = the ordinate
* @returns {t_pointsList	*} newlink = returns the new link made from the input data
*/
t_pointsList	*pointsListNew(int x, int y)
{
	t_pointsList	*newlink;

	if (!(newlink = wrmalloc(sizeof(t_pointsList))))
		return (NULL);
	newlink->x = x;
	newlink->y = y;
	newlink->next = NULL;
	return (newlink);
}

/**
* Goes through the list to find the last link
*
* @param {t_pointsList *} lst = the list of points from the input file
* @returns {t_pointsList *} tmp = the last link of the input list
*/
t_pointsList	*pointsListFindLast(t_pointsList *lst)
{
	t_pointsList *tmp;

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
* @param {t_pointsList **} lst = a pointer to the list of points from the input file
* @param {t_pointsList *} new = the new link to add to the list
*/
void			pointsListAddBack(t_pointsList **lst, t_pointsList *new)
{
	if (!*lst)
		*lst = new;
	else
		pointsListFindLast(*lst)->next = new;
}

/**
* Determines the size of the input chained list
*
* @param {t_pointsList *} pointsList = the list of points from the input file
* @returns {int} size = returns the size of the input list
*/
int 			pointsListSize(t_pointsList *pointsList)
{
	int				size;
	t_pointsList	*tmp;

	tmp = pointsList;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/**
* Checks the list to find if the input coordinates are already saved
*
* @param {t_pointsList **} lst = a pointer to the list of points from the input file
* @param {int} x = the abscissa
* @param {int} y = the ordinate
* @returns {int} returns -1 if the coordinates are already saved
*/
t_pointsList	*isInList(t_pointsList **lst, int x, int y)
{
	t_pointsList	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}