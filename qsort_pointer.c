/* qsort for an array of pointers
    the behaviour of the algorithm is similar
    to that basic version that works with int, floats
    and related types

    the main difference is that the comparison
    between the middle element of partison and the
    other partision elems is done by using strcmp, since
    we are evaluating strings 

    if more explanation is demanded, please look up
    to qsort.c documentation in this same directory */

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char  *v[], int i, int j);
    int str_cmp(char *s, char *t);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right)/2);    /* move partition elem */
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
        if (str_cmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* return < 0 if s < t, 0 if s == t, >0  if s > t */
int str_cmp(char *s, char *t)
{
    int i;

    for( ; (*s == *t) && (*s) && (*t); s++, t++)
        ;
    return *s - *t;
}