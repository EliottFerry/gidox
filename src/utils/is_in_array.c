int char_is_in_array(const char elem, const char *array)
{
    for (int i = 0; array[i]; i++)
        if (elem == array[i])
            return (1);
    return (0);
}