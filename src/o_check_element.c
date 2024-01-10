/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_check_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:25 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 11:25:57 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13)
		|| c == 32 || c)
		return (1);
	return (0);
}

int	validate_symbol(char *str){
	int len = 0;
	int i = 0;

	while (str[i]) {
		if (str[i] == '-' && i == 0)
			len++;
		else if ((str[i] == '+' || str[i] == '.' ) && i == 0)
			len+=2;
		else if ((str[i] == '-' || str[i] == '+') && i != 0)
			return 0;
		else if (str[i] == '.' && (i == ((int)ft_strlen(str) - 1)))
			return 0;
		i++;
	}
	if (len > 1)
		return 0;
	return 1;
}

int is_digit_or_symbol(int c) {
	if (ft_isdigit(c) || c == '-' || c == '+' || c == '.')
		return 1;
	return 0;
}

int validate_not_digit_or_symbol(char *str) {
	int i = 0;

	while (str[i] && str[i] != '\n') {
		if (!is_digit_or_symbol(str[i])) {
			return 0;
		}
		i++;
	}
	return 1;
}

int len_dot(char *str, char c) {
	int i = 0;
	int len = 0;

	while (str[i]) {
		if (str[i] == c)
			len++;
		i++;
	}
	return len;
}

int validate_int(char *num) {
	char	**str = NULL;
	int		i = 0;
	int 	ret = 1;

	str = ft_split(num, ',');
	while (str[i])
	{
		if (validate_not_digit_or_symbol(str[i]) == 0) {
			ret = 0;
		}
		if (validate_symbol(str[i]) == 0) {
			ret = 0;
		}
		if (len_dot(str[i], '.') > 1)
			ret = 0;
		i++;
	}
	int j = 0;
	while (str[j]) {
		free(str[j]);
		j++;
	}
	free(str);
	str = NULL;
	return (ret);
}

int len_size(char **str) {
	int i = 0;

	while (str[i]) {
		i++;
	}
	return (i);
}

int len_xyz(char *str) {
	char **sp;
	int	len;

	len = 0;

	sp = NULL;
	sp = ft_split(str, ',');
	while(sp[len]) {
		free(sp[len]);
		len++;
	}
	free(sp);
	return (len);
}

int len_validate_c(char **str) {
	if (len_size(str) != 3)
		return (0);
	if (len_xyz(str[0]) != 3 || len_xyz(str[1]) != 3 || len_xyz(str[2]) != 1)
		return (0);
	return (1);
}
int len_validate_a(char **str) {
	if (len_size(str) != 2)
		return (0);
	if (len_xyz(str[0]) != 1 || len_xyz(str[1]) != 3)
		return (0);
	return (1);
}
int len_validate_l(char **str) {
	if (len_size(str) != 3)
	{
		printf("if 1\n");
		return (0);
	}
	if (len_xyz(str[0]) != 3 || len_xyz(str[1]) != 1 || len_xyz(str[2]) != 3)
	{
		printf("if 2\n");
		return (0);
	}
	return (1);
}
int len_validate_pl(char **str) {
	if (len_size(str) != 3)
		return (0);
	if (len_xyz(str[0]) != 3 || len_xyz(str[1]) != 3 || len_xyz(str[2]) != 3)
		return (0);
	return (1);
}
int len_validate_sp(char **str) {
	if (len_size(str) != 3)
		return (0);
	if (len_xyz(str[0]) != 3 || len_xyz(str[1]) != 1 || len_xyz(str[2]) != 3)
		return (0);
	return (1);
}
int len_validate_cy(char **str) {
	if (len_size(str) != 5)
		return (0);
	if (len_xyz(str[0]) != 3 || len_xyz(str[1]) != 3 || len_xyz(str[2]) != 1
		|| len_xyz(str[3]) != 1 || len_xyz(str[4]) != 3)
		return (0);
	return (1);
}

int	check_element_c(char *line, int num_c)
{
	char	**str;
	int		i;

	(void) num_c;
	i = 0;
	str = NULL;
	str = ft_split_space(line);
	for (int j =0; str[j];j++)
	{
		printf("str[%d] = %s\n",j,str[j]);
		for (int k = 0; str[j][k]; k++)
			printf("char str[%d][%d] = %d\n", j, k,str[j][k]);
		printf("---------\n");
	}
	if (!len_validate_c(str))
		return (0);
	while (str[i])
	{
		if (validate_int(str[i]) == 0)
			return 0;
		i++;
	}
	remove_split(str);
	return (1);
}
int	check_element_a(char *line, int num_a)
{
	char	**str;
	int		i;

	(void) num_a;
	i = 0;
	str = ft_split_space(line);
	if (!len_validate_a(str))
		return (0);
	while (str[i])
	{
		if (validate_int(str[i]) == 0)
			return 0;
		i++;
	}
	remove_split(str);
	return (1);
}

int	check_element_l(char *line, int num_l)
{
	char	**str;
	int		i;

	(void) num_l;
	i = 0;
	str = ft_split_space(line);
	if (!len_validate_l(str))
		return (0);
	while (str[i])
	{
		if (validate_int(str[i]) == 0)
			return 0;
		i++;
	}
	remove_split(str);
	return (1);
}

int	check_element_pl(char *line, int num_pl)
{
	char	**str;
	int		i;

	(void) num_pl;
	i = 0;
	str = ft_split_space(line);
	if (!len_validate_pl(str))
		return (0);
	while (str[i])
	{
		if (validate_int(str[i]) == 0)
			return 0;
		i++;
	}
	remove_split(str);
	return (1);
}
int	check_element_sp(char *line, int num_sp)
{
	char	**str;
	int		i;

	(void) num_sp;
	i = 0;
	str = NULL;
	str = ft_split_space(line);
	if (!len_validate_sp(str))
		return (0);
	while (str[i])
	{
		if (validate_int(str[i]) == 0)
			return 0;
		i++;
	}
	remove_split(str);
	return (1);
}

int	check_element_cy(char *line, int num_cy)
{
	char	**str;
	int		i;

	(void) num_cy;
	i = 0;
	str = ft_split_space(line);
	if (!len_validate_cy(str))
		return (0);
	while (str[i])
	{
		if (validate_int(str[i]) == 0)
			return 0;
		i++;
	}
	remove_split(str);
	return (1);
}
