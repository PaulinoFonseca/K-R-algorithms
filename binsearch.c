/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(char v[], int x, int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (high >= low){
        mid = (low + high)/2; 
        if (x < v[mid]){
            high = mid-1;
        }
        else if (x > v[mid]){
            low = mid+1;
        }
        else{
            return mid; /* match found */
        }
    }
    return -1; /* no match found */
}