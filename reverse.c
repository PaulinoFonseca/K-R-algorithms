/* reverse the string s in place */
void reverse(char s[])
{
    char *i;
    int temp;

    i = s;                          /* saving the address of the beginning of the array */
    while(*s){                      /* increment s until the end of the string '\0' is reached */
        ++s;
    }
    --s;                            /* throwing away '\0' from reversing, since it will still save the end of the string */

    for ( ; i <= s; ++i, --s){      /* swapping string members, until all of them have been swapped (unless the '\0' terminator) */
        temp = *s, *s = *i, *i = temp;
    }
    return;
}