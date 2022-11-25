#include "squares.h"

/**
* Frees a pointer
*
* @param {void **} ptr = the pointer to free
*/
void	free_safe(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

/**
* Calculates the distance between two give points in 2D
*
* @param {double} a_x = the abscissa of point a
* @param {double} a_y = the ordinate of point a
* @param {double} b_x = the abscissa of point b
* @param {double} b_y = the ordinate of point b
* @returns {double} returns the distance between point a and point b
*/
double	dist_two_pts(double a_x, double a_y, double b_x, double b_y)
{
	double	side_one;
	double	side_two;

	side_one = a_x - b_x;
	side_two = a_y - b_y;
	return (sqrt((side_one * side_one) + (side_two * side_two)));
}