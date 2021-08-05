/* shellsort: sort v[0]... v[n-1] into increasing order */

/* starting with len(v[])/2, the comparision interval is cut in half
    at each iteration of the outermost looṕ, which means that: "In early
    stages far apart elements are compared, rather than adjacent ones as in
    similar interchange sorts. This tends to eliminate large amounts of
    disorder quickly, so later stages have less work to do" - K&R, page 62. */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap)
                for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j-=gap){
                    temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
            }
}