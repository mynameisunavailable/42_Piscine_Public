unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	bitmask_ckrep(char* word, unsigned char* mask)
{
	unsigned char *c;
	
    while (*word)
    {
		c = (unsigned char *)word;
        if ((mask[*c / 8]) & (1U << (*c % 8)))
            return (1);
        else
            mask[*c / 8] = mask[*c / 8] | (1U << (*c % 8));
        word++;
    }
    return (0);
}

int	ft_is_white_space(char base)
{
	if (base == ' ' || base == '\f' || base == '\n'
		|| base == '\r' || base == '\t' || base == '\v')
		return (1);
	return (0);
}

void ft_reverse_string(char *string, char *reverse_string, int length)
{
    int index;
    
    index = 0;
    while (length > 0)
    {
        reverse_string[index] = string[length - 1];
        length--;
        index++;
    }
    reverse_string[index] = '\0';
}
