// There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if(n == 0) return m % 2 == 0 ? ((double)A[m / 2] + A[(m - 1) / 2]) / 2 : A[m / 2];
    int median = (m + n - 1) / 2;
    int start = n >= median ? 0 : median - n;
    int end = m > median ? median : m - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        int bigger = median - mid;
        if((bigger == n || A[mid] <= B[bigger]) && (bigger == 0 || A[mid] >= B[bigger - 1])){
            if((m + n) % 2 == 0){
                return ((double)A[mid] + (mid == m - 1 || (bigger != n && A[mid + 1] >= B[bigger]) ? B[bigger] : A[mid + 1])) / 2;
            }else
                return A[mid];
        }else if(bigger != n && A[mid] > B[bigger])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return findMedianSortedArrays(B, n, A, m);
}