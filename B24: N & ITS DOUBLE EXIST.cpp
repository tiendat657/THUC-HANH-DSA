C1: SORT + BS
  
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
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

int binarySearch(vector<int> &a, int target) {
    int left = 0;
    int right = (int)a.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; // khong tim duoc
}

bool checkIfExist(vector<int> &a) {
    int n = (int)a.size();
    
    quickSort(a, 0, n - 1);
    
    for (int i = 0; i < n - 1; i++) {
        int index = binarySearch(a, 2 * a[i]);
        if (index != -1 && index != i) {
            return true;
        }
        if (a[i] == 0) {
            if ((i > 0 && a[i - 1] == 0) || (i < n && a[i + 1] == 0)) {
                return true; // xu ly cho truong hop so 0
            }
        }
    }
    return false;
}

C2: SORT + LOWERBOUND

int lowerBound(vector<int> &a, int target) {
    int n = (int)a.size();
    int left = 0;
    int right = n - 1;
    int ans = n; // mac dinh la n neu khong tim duoc
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (a[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

bool checkIfExist(vector<int> &a) {
    int n = (int)a.size();
    
    quickSort(a, 0, n - 1);
    
    for (int i = 0; i < n - 1; i++) {
        int index = lowerBound(a, 2 * a[i]);
        
        // dam bao co phan tu thoa + phan tu do == target + phan tu do khac phan tu dang xet
        if (index < n && a[index] == 2 * a[i] && index != i) {
            return true;
        }
        if (a[i] == 0) {
        if ((i > 0 && a[i-1] == 0) || (i < n - 1 && a[i+1] == 0)) {
            return true;
        }
    }
    }
    return false;
}
