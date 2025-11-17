//get start of string append to the end return start of str
char* concat_char(char* string, char c)
{
    char* string_start = string;
    while (*string)
    {
        string++;
    }
    *string = c;
    string++;
    *string = '\0';
    return string_start;
}

//get current pos of location needed to be appended return new end
char* concat_char_insitu(char* string, char c)
{
    *string = c;
    string++;
    *string = '\0';
    return string;
}