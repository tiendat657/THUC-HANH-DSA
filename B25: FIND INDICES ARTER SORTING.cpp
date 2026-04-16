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

vector<int> targetIndices(vector<int>& a, int target) {
    int n = (int)a.size();
    vector<int> res;
    quickSort(a, 0, n - 1);
    
    int index = lowerBound(a, target);
    if (index < n && a[index] == target) {
        res.push_back(index);
        if (index != n - 1) {
            for (int i = index + 1; i < n; i++) {
                if (a[i] == target) {
                    res.push_back(i);
                }
            }
        }
    }
    
    return res;
}
