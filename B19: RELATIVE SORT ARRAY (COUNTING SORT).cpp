vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int n = (int)arr1.size();
    vector<int> count(1001, 0);
    
    vector<int> res;
    for (int x : arr1) {
        count[x]++; // vi gioi han chi den 1000, ta bo arr1 vao mang danh dau
        // khi bo vao count, no da duoc sap xep tang dan
    }
    
    for (int x : arr2) { // duyet arr2
        while (count[x] > 0) { // khi gap 1 phan tu co trong arr2
            res.push_back(x); // ta bo tat ca phan tu do vao mang res
            count[x]--;
        }
    }
    
    for (int i = 0; i < 1001; i++) {
        while (count[i] > 0) {
            res.push_back(i); // cac phan tu khong co trong arr2 -> bo vao res
            count[i]--;
        }
    }
    
    return res;
}
