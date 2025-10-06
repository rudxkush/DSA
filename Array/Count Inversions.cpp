class Solution {
public:
    long long ans = 0;
    void merge(vector<int>& arr, int l, int mid, int h) {
        int n1 = mid - l + 1;
        int n2 = h - mid;
        
        vector<int> left(n1);
        for(int i = 0 ; i < n1; i++) {
            left[i] = arr[i + l];
        }
      
        vector<int> right(n2);
        for(int i = 0 ; i < n2; i++) {
            right[i] = arr[i + mid + 1];
        }
        
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }
        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];
    }

    void getPairs(vector<int>& arr, int l, int mid, int h) {
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= h && arr[i] > arr[j]) j++;
            ans += (j - (mid + 1));
        }
    }

    void mergeSort(vector<int>& arr, int l, int h) {
        if (l >= h) return;
        int mid = (l + h) >> 1;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        getPairs(arr, l, mid, h);
        merge(arr, l, mid, h);
    }

    int inversionCount(vector<int>& arr) {
        ans = 0;
        mergeSort(arr, 0, arr.size() - 1);
        return ans;
    }
};
