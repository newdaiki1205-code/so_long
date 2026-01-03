#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if(!s)
		return 0;
	i = 0;
	while (s[i] != '\0')
        i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
        str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
