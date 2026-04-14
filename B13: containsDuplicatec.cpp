      --- BAI GIAI ---

C1: Sort
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &a, int low, int high) {
    int i = low - 1;
    int j = high + 1;
    
    int pivot = a[low];
    while (true) {
        do {
            i++;
        } while (a[i] < pivot);
        
        do {
            j--;
        } while (a[j] > pivot);
        
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

bool containsDuplicate(vector<int> &nums) {
    int n = (int)nums.size();
    quickSort(nums, 0, n - 1);
    
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    
    return false;
}

C2: Set
bool containsDuplicate(vector<int> &nums) {
    int n = (int)nums.size();
    set<int> se;
    
    for (int x : nums) {
        se.insert(x);
    }
    
    return se.size() < n;
}

C3: Hash map
