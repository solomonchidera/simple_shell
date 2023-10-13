#include <stdio.h>

char *_fgets(char *str, int size, FILE *stream)
{
	int c;
	int i;
	i = 0;

	if (size <= 0 || str == NULL || stream == NULL)
	{
		return NULL;
	}

	while (i < size - 1)
	{
		c = fgetc(stream);

		if (c == EOF)
		{
			break;
		}

		str[i] = (char)c;

		if (c == '\n')
		{
			i++;
			break;
		}

		i++;
	}

	if (i == 0 && c == EOF)
	{
		return NULL;
	}

	return str;
}

int main(void)
{
	char buffer[100];
	printf("Enter a line of text: ");
	_fgets(buffer, sizeof(buffer), stdin);
	printf("You entered: %s", buffer);

	return 0;
}
