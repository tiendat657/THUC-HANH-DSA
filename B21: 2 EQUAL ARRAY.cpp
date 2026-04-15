void heapify(vector<int> &a, int n, int i) {
    int l1 = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && a[left] > a[i]) {
        l1 = left;
    }
    if (right < n && a[right] > a[l1]) {
        l1 = right;
    }
    
    if (l1 != i) {
        swap(a[l1], a[i]);
        
        heapify(a, n, l1);
    }
}

void heapSort(vector<int> &a) {
    int n = (int)a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        
        heapify(a, i, 0);
    }
}

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    heapSort(arr);
    heapSort(target);
    
    return arr == target;
}
