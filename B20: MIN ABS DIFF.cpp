void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &a, int low, int high) {
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        do {i++;} while (a[i] < pivot);
        do {j--;} while (a[j] > pivot);
        
        if (i >= j) return j;
        
        swap(a[i], a[j]);
    }
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        
        quickSort(a, low, pi);
        quickSort(a, pi + 1, high);
    }
}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> v;
    
    int n = (int)arr.size();
    quickSort(arr, 0, n - 1);
    
    int minDiff = INT_MAX; // tim minDiff
    for (int i = 0; i < n - 1; i++) {
        int curDiff = arr[i + 1] - arr[i]; // ta chac chan no se khong am
        
        if (curDiff < minDiff) {
            minDiff = curDiff;
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        int curDiff = arr[i + 1] - arr[i];

        if (curDiff == minDiff) { // neu cap do co hieu = minDiff -> cho vao vector pair
            v.push_back({arr[i], arr[i + 1]});
        }
    }
    
    return v;
}
