#include "maintest.h"

int nlen(int c)
{
	int count = 0;

	if (c == 0)
		return (1);

	while (c != 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

int _abs(int c)
{
	int i;

	if (c < 0)
		i = -c;
	else
		i = c;
	return (i);
}

int d_spec(int c)
{
	int len = nlen(c);
	int sign, i, j;
	char *str;


	/*if negative*/
	if (c < 0)
	{
		sign = -1;
	}

	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (1);

	str[len] = '\0';
	j = len;
	j--;
	for (i = 0; i < len; i++)
	{
		str[j] = _abs(c % 10) + '0';
		c /= 10;
		j--;
	}

	if (sign == -1)
		write(1, "-", 1);

	write(1, str, len);
	free(str);

	return (len + (sign == -1));
}


