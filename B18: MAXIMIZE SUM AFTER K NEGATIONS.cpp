void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &a, int low, int high) { // phan hoach Lomuto
    int pivot = a[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[high]);
  
    return i + 1;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    int n = (int)nums.size();
    
    quickSort(nums, 0, n - 1);
    
    for (int i = 0; i < n; i++) { // chuyent at ca so < 0 sang > 0
        if (nums[i] < 0 && k > 0 ) {
            nums[i] = -nums[i];
            k--;
        }
    }
    
    int sum = 0;
    int minVal = INT_MAX;
    for (int x : nums) {
        sum += x; // cong vao tong
        if (x < minVal) { /// tim gia tri be nhat de khi tru no 2x lan se giup sum co gia tri lon nhat
            minVal = x;
        }
    }
    
    if (k % 2 == 1) { // khi minVal = 0 cung se tinh vao truong hop nay
        sum -= 2 * minVal;
    }
    
    return sum;
}
