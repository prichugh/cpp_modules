#include <iostream>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 1;
	int j = 0;
	if (argc < 2)
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[i] != NULL)
		{
			while (argv[i][j] != '\0')
			{
				argv[i][j] = std:: toupper(argv[i][j]);
				std:: cout << argv[i][j];
				j++;
			}
			i++;
			j = 0;
		}
	}
	std:: cout << "\n";
	return (0);
}
