/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:48:32 by dsas              #+#    #+#             */
/*   Updated: 2022/12/26 15:48:55 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_count(const char *str, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] != '\0' && !(str[i] == c))
			i++;
	}
	return (counter);
}

static char	*add_str(const char *str, char c, int *i)
{
	int		str_len;
	char	*result;
	int		j;

	str_len = 0;
	j = 0;
	while (str[*i + str_len] != '\0' && !(str[*i + str_len] == c))
	{
		str_len++;
	}
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!result)
		return (NULL);
	while (str[*i] != '\0' && !(str[*i] == c))
	{
		result[j] = str[*i];
		j++;
		(*i)++;
	}
	result[j] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		split_amount;
	int		i;
	int		string_counter;

	string_counter = 0;
	i = 0;
	split_amount = split_count(s, c);
	result = (char **)malloc (sizeof(char *) * (split_amount + 1));
	if (!result)
		return (NULL);
	if (split_amount == 0)
	{
		result[0] = NULL;
		return (result);
	}
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			result[string_counter++] = add_str(s, c, &i);
	}
	result[string_counter] = NULL;
	return (result);
}

// #include <stdio.h>

// int main()
// {
// 	char **test;
// 	test = ft_split("dan,", ",");
// 	int i = 0;
// 	while (test[i] != NULL)
// 		printf("%s\n", test[i++]);
// }
