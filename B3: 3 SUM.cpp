      --- BAI GIAI ---
        
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1 // vi tri cuoi mang nums1 thuc su
    int j = n - 1; // vi tri cuoi mang nums2
    int k = m + n - 1; // vi tri cho nhung phan tu lon nhat cua 2 mang
    
    // su dung 3 con tro de duyet nguoc
    while (i >= 0 && j >= 0) {
        if (nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            j--; k--;
        } else {
            nums1[k] = nums1[i];
            k--; i--;
        }
    }

    // truong hop mang nums2 con cac phan tu nho hon tat ca phan tu cua nums1 -> don lai vao dau mang nums1
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--; j--;
    }
}
