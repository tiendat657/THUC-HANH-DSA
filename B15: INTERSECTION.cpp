C1: TWO SET

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> se1, se2;
    for (int x : nums1) {
        se1.insert(x);
    }
    for (int x : nums2) {
        se2.insert(x);
    }
    
    vector<int> res;
    
    for (int x : se2) {
        if (se1.find(x) != se1.end()) {
            res.push_back(x);
        }
    }
    return res;
}


C2: HASH MAP

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int, int> mp;
    
    for (int x : nums1) {
        mp[x] = 1;
    }
    
    for (int x : nums2) {
        if (mp[x] == 1) {
            res.push_back(x);
            mp[x] = 0;
        }
    }
    
    return res;
}

C3: SORT + TWO POINTERS

void merge(vector<int> &a, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = a[low + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = a[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++; k++;
    }
}

void mergeSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        
        merge(a, low, mid, high);
    } else return;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    
    int n1 = (int)nums1.size();
    int n2 = (int)nums2.size();
    
    mergeSort(nums1, 0, n1 - 1);
    mergeSort(nums2, 0, n2 - 1);

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            if (res.empty() || nums1[i] != res.back()) { // de khong bi trung
                res.push_back(nums1[i]);
            }
            i++; j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return res;
}

  
