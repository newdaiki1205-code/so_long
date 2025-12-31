#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
    {
        // if(s[i] == '\n')
        //     break;
        i++;
    }
	if(s[i - 1] == '\n')
		i--;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		// if(s[i] == '\n')
        //     break;
        str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
