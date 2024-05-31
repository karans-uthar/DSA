//User function Template for C++

void rotate(int arr[], int n)
{
    int temp;
    
    temp = arr[n - 1];
    
    for(int i = 1; i < n; i++)
        arr[n - i] = arr[n - (i + 1)];
    
    arr[0] = temp;
}