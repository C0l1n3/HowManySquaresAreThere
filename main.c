#include "squares.h"

/**
* Checks the line from the input file for errors and stocks the coordinates found
* in the parameters
*
* @param {char *} line = the line from the input file which we are currently reading
* @param {int *} x = the address where to save the abscissa
* @param {int *} y = the address where to save the ordinate
* @returns {int} returns a number when an error was found corresponding to the character position in the line
*/
int		checkLine(char *line, int *x, int *y)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!line || !line[0])
		return (-1);
	// Check for empty characters
	while ((line[i] == ' ' || line[i] == '\f' || line[i] == '\t')
			|| (line[i] == '\n' || line[i] == '\r' || line[i] == '\v'))
		i++;
	// Check for a  sign
	if (line[i] == '+' || line[i] == '-')
	{
		if (line[i] == '-')
			sign = -sign;
		i++;
	}
	// save the abscissa number
	while ('0' <= line[i] && line[i] <= '9')
		if ((nb = nb * 10 + (line[i++] - '0')) < 0)
			return (-1);
	*x = sign * nb;
	sign = 1;
	nb = 0;
	// Check for empty characters
	while ((line[i] == ' ' || line[i] == '\f' || line[i] == '\t')
			|| (line[i] == '\n' || line[i] == '\r' || line[i] == '\v'))
		i++;
	// Check for a  sign
	if (line[i] == '+' || line[i] == '-')
	{
		if (line[i] == '-')
			sign = -sign;
		i++;
	}
	// save the ordinate number
	while ('0' <= line[i] && line[i] <= '9')
		if ((nb = nb * 10 + (line[i++] - '0')) < 0)
			return (-1);
	*y = sign * nb;
	while ((line[i] == ' ' || line[i] == '\f' || line[i] == '\t')
		|| (line[i] == '\n' || line[i] == '\r' || line[i] == '\v'))
		i++;
	// If we are not at the end of the line at this point, then there is an error
	if (line[i] != 0)
		return (i + 1);
	return (0);
}

/**
* Prints the squares coordinates to cmd
*
* @param {t_pointsList} pointsList = the list of points from the input file
* @param {int} fd = the file descriptor frome the input file
* @returns {int} -1 if an error was found in the file
*/
int		getPoints(t_pointsList **pointsList, int fd)
{
	int				ret;
	char			*line;
	int				lineNumber;
	int				x;
	int				y;
	int				errorChar;

	ret = 0; 
	line = NULL;
	lineNumber = 1;
	x = 0;
	y = 0;
	errorChar = 0;

	while (1)
	{
		// We get each line one by one. if there was an error in the line, we stop and print an error
		// message.
		ret = get_next_line(fd, &line);
		if ((errorChar = checkLine(line, &x, &y)) > 0)
		{
			ft_printf("ERROR FOUND WHILE PARSING FILE\nCHECK LINE %d CHARACTER %d\n", lineNumber, errorChar);
			return (-1);
		}
		// If there is a duplicate point in the list, we skip it
		if (!(isInList(pointsList, x, y)))
		{
			pointsListAddBack(pointsList, pointsListNew(x, y));
			lineNumber++;
		}
		if (!ret)
			break ;
		wrfree(line);

	}
	return (0);
}

/**
* Prints the squares coordinates to terminal
*
* @param {t_squares **} squaresList = the address of the list of squares found
*/
void	printSquares(t_squares **squaresList)
{
	t_squares	*tmp;
	int			listNumber;

	tmp = *squaresList;
	listNumber = 1;
	while (tmp)
	{
		ft_printf("SQUARE %d : A[%d, %d], B[%d, %d], C[%d, %d], D[%d, %d]\n",
			listNumber, tmp->A[0], tmp->A[1], tmp->B[0],
			tmp->B[1], tmp->C[0], tmp->C[1], tmp->D[0],
			tmp->D[1]);
		tmp = tmp->next;
		listNumber++;
	}
}

int 	main(int argc, char **argv)
{
	t_pointsList	*pointsList;
	t_squares		*squaresList;
	int				fd;
	int				numberOfSquares;
	int				errorCode;
	clock_t			start;
	clock_t			end;
	double			cpu_time_used;

	pointsList = NULL;
	squaresList = NULL;
	fd = 0;
	numberOfSquares = 0;
	errorCode = 0;
	start = clock();
	// Check if we have the correct number of arguments
	if (argc > 3 || argc < 2)
	{
		ft_printf("ONLY ONE ARGUMENT\n");
		return (-1);
	}
	// Open input file
	fd = open(argv[1], O_RDONLY);

	// Read file
	if (read(fd, 0, 0) < 0)
	{
		ft_printf("THERE WAS A PROBLEM WHILE TRYING TO OPEN THE FILE\n");
		return (-1);
	}
	// Get the points from the input file in a chained list format
	if ((errorCode = (getPoints(&pointsList, fd))))
		return (-1);
	// If there are not enough points in the file, we stop
	if (pointsListSize(pointsList) < 4)
	{
		ft_printf("NOT ENOUGH POINTS IN FILE\n");
		return (-1);
	}
	ft_printf("File Ok\n");
	// Algorythm to find the squares from the points
	numberOfSquares = findSquares(pointsList, &squaresList);
	ft_printf("number of squares found : %d\n", numberOfSquares);
	// If any squares are found, we print to the terminal
	if (numberOfSquares)
		printSquares(&squaresList);
	pointsListFree(pointsList);
	squaresListFree(squaresList);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("TIME USED : %d seconds\n", (int)cpu_time_used);
	return (0);
}
