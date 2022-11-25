#include "squares.h"

/**
* Take 2 points (A&B) and calculates the projected coordinates for the 3 
* squares that it could create (C&D, E&F, G&H). Then checks the list if they exist.
*
*  C_____________A_____________E
*  |            /|\            |
*  |         /   |   \         |
*  |      /      |      \      |
*  |   G         |         H   |
*  |      \      |      /      |
*  |         \   |   /         |
* D|____________\|/____________|F
*
* @param {t_pointsList *} pointsList = the list of points from the input file
* @param {t_squares **} squaresList = the address where to save the list of squares found
* @returns {int} numberOfSquares = returns the number of squares found from the input points
*/
int	findSquares(t_pointsList *pointsList, t_squares **squaresList)
{
	t_pointsList	*A;
	t_pointsList	*B;
	t_pointsList	*C;
	t_pointsList	*D;
	int				vectorAB[2];
	double			middlePoint[2];
	int				rotatedABClockWise[2];
	double			projectedPointOne[2];
	double			projectedPointTwo[2];
	int				numberOfSquares;

	A = pointsList;
	B = A->next;
	C = NULL;
	D = NULL;
	vectorAB[0] = 0;
	vectorAB[1] = 0;
	middlePoint[0] = 0;
	middlePoint[1] = 0;
	rotatedABClockWise[0] = 0;
	rotatedABClockWise[1] = 0;
	numberOfSquares = 0;

	// From two points, calculate the three squares that can be formed and find
	// the remaining points.
	// Then check the list if they exist
	while ((B->next) || (A->next != B))
	{
		vectorAB[0] = B->x - A->x;
		vectorAB[1] = B->y - A->y;
		rotatedABClockWise[0] = vectorAB[1];
		rotatedABClockWise[1] = vectorAB[0] * -1;

		// Find the two squares from which AB forms a side
		projectedPointOne[0] = A->x + rotatedABClockWise[0];
		projectedPointOne[1] = A->y + rotatedABClockWise[1];
		if (A->x == 30 && A->y == 30 && B->x == -30 && B->y == 30)
			printf("First projected pointOne(%f, %f)\n", projectedPointOne[0], projectedPointOne[1]);
		if ((C = isInList(&B->next, projectedPointOne[0], projectedPointOne[1])))
		{
			projectedPointTwo[0] = B->x + rotatedABClockWise[0];
			projectedPointTwo[1] = B->y + rotatedABClockWise[1];
			if ((D = isInList(&B->next, projectedPointTwo[0], projectedPointTwo[1])) && C != D)
			{
				numberOfSquares++;
				squaresListAddBack(squaresList, squaresListNew(A, B, C, D));
			}
		}
		C = NULL;
		D = NULL;
		projectedPointOne[0] = A->x - rotatedABClockWise[0];
		projectedPointOne[1] = A->y - rotatedABClockWise[1];
		if (A->x == 30 && A->y == 30 && B->x == -30 && B->y == 30)
			printf("Second projected pointOne(%f, %f)\n", projectedPointOne[0], projectedPointOne[1]);
		if ((C = isInList(&B->next, projectedPointOne[0], projectedPointOne[1])))
		{
			projectedPointTwo[0] = B->x - rotatedABClockWise[0];
			projectedPointTwo[1] = B->y - rotatedABClockWise[1];
			if ((D = isInList(&B->next, projectedPointTwo[0], projectedPointTwo[1])) && C != D)
			{
				numberOfSquares++;
				squaresListAddBack(squaresList, squaresListNew(A, B, C, D));
			}
		}
		C = NULL;
		D = NULL;
		// Find the square from which AB forms a diagonal
		middlePoint[0] = A->x + (double)vectorAB[0] / 2;
		middlePoint[1] = A->y + (double)vectorAB[1] / 2;
		projectedPointOne[0] = middlePoint[0] + (double)rotatedABClockWise[0] / 2;
		projectedPointOne[1] = middlePoint[1] + (double)rotatedABClockWise[1] / 2;
		if ((C = isInList(&B->next, projectedPointOne[0], projectedPointOne[1])))
		{
			projectedPointTwo[0] = middlePoint[0] - (double)rotatedABClockWise[0] / 2;
			projectedPointTwo[1] = middlePoint[1] - (double)rotatedABClockWise[1] / 2;
			if ((D = isInList(&B->next, projectedPointTwo[0], projectedPointTwo[1])) && C != D)
			{
				numberOfSquares++;
				squaresListAddBack(squaresList, squaresListNew(A, B, C, D));
			}
		}
		// Shift points avoiding to check previous points
		// if we tested the last combination, we stop
		if (B->next)
		{
			B = B->next;
		}
		else
		{
			A = A->next;
			B = A->next;
		}
	}
	return (numberOfSquares);
}
