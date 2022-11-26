#ifndef SQUARES_H
# define SQUARES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <time.h>

typedef struct			s_pointsList
{
	int					x;
	int					y;
	struct s_pointsList	*next;
}						t_pointsList;

typedef struct			s_lines
{
	char				*line;
	struct s_lines		*next;
}						t_lines;

typedef struct			s_squares
{
	int					A[2];
	int					B[2];
	int					C[2];
	int					D[2];
	struct s_squares	*next;
}						t_squares;


/*
** FIND SQUARES CORE
*/

int						findSquares(t_pointsList *pointsList, t_squares **squaresList);

/*
** GENERAL UTILS
*/

void					free_safe(void **ptr);
double					dist_two_pts(double a_x, double a_y, double b_x, double b_y);

/*
** SQUARES LIST
*/

void					squaresListFree(t_squares *lst);
t_squares				*squaresListNew(t_pointsList *A, t_pointsList *B, t_pointsList *C, t_pointsList *D);
t_squares				*squaresListFindLast(t_squares *lst);
void					squaresListAddBack(t_squares **alst, t_squares *new);

/*
** POINTS LIST
*/

void					pointsListFree(t_pointsList *lst);
t_pointsList			*pointsListNew(int x, int y);
t_pointsList			*pointsListFindLast(t_pointsList *lst);
void					pointsListAddBack(t_pointsList **lst, t_pointsList *new);
int						pointsListSize(t_pointsList *pointsList);
t_pointsList			*isInList(t_pointsList **lst, int x, int y);

#endif