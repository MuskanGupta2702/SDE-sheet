// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>

// TC => O(N log N)
// SC => O(N)

 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.

long long merge(long long arr[], long long temp[], long long low, long long mid, long long high)
{
    long long i = low, j = mid, k = low, inv_count = 0;
    while(i<=mid-1 && j<=high)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            inv_count += mid-i;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid-1)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    for(i = low; i<=high; i++)
        arr[i] = temp[i];
    return inv_count;
}


long long mergeSort(long long arr[], long long temp[], long long low, long long high)
{
    long long mid, inv_count = 0;
    if(low<high)
    {
        mid = (low+high)/2;
        inv_count += mergeSort(arr, temp, low, mid);
        inv_count += mergeSort(arr, temp, mid+1, high);
        inv_count += merge(arr, temp, low, mid+1, high);
    }
    return inv_count;
}


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    return mergeSort(arr, temp, 0, N-1);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends