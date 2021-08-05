/* qsort: sort v[left] ... v[right] into increasing order 
    with partition element being the middle one */

/* brief description of the algorithm behaviour:
    1. swap the first elem of v[] with the middle one
    2. put in front of the "first" elem any smaller numbers
    3. after going through all v's elems, swap last swapped 
    elem in front of v[0] with v[0]
    4. now, any number smaller than original v[] middle number
    is encountered behind it and greater nums are in front of it
    5. do the same process with the two new partitions 
    6. stop when a partition is composed by only one number */

/* Example: 
    given v[] = {5,3,7,8,1}, the first iteration
    of the algorithm would result in the following swaps:
    
    0. {5,3,7,8,1}
    initial swap:
    0. {7,3,5,8,1}
    for loop:
    1. {7,3,5,8,1}
    2. {7,3,5,8,1}
    3. {7,3,5,8,1} 
    4. {7,3,5,1,8}
    restore partition elem:
    5. {1,3,5,7,8} */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right)/2);    /* move partition elem */
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}