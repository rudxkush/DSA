class Solution {
  public:
    void merge(int arr[], int l, int mid, int h) {
        int n1 = mid - l + 1; 
        int n2 = h - mid;
        int left[n1], right[n2];
        // copy the elements!
        for(int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for(int i = 0; i < n2; i++) {
            right[i] = arr[mid + 1 + i];
        }
        
        int i = 0, j = 0, k = l;
        while(i < n1 && left[i] < 0) arr[k++] = left[i++]; 
        while(j < n2 && right[j] < 0) arr[k++] = right[j++];
        
        while(i < n1) arr[k++] = left[i++];
        while(j < n2) arr[k++] = right[j++];
    }
    void mergeSort(int arr[], int l, int h) {
        if(l >= h) return ;
        int mid = (l + h) >> 1;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
        return ;
    }
    void Rearrange(int arr[], int n) {
        mergeSort(arr, 0, n - 1);
    }
};

// -3, 3, -2, 2
// 0.  m  m+1 n-1
// 0. 1.   2. 3
