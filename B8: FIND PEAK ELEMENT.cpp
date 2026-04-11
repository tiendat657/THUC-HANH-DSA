      --- BAI GIAI ---
int findPeakElement(vector<int>& nums) {
    int l = 0, r = (int)nums.size() - 1;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (nums[m] < nums[m + 1]) { // dang len doc (con so lon nua)
            l = m + 1;
        } else {
            r = m; // (nums[m] < nums[m + 1]): co the dang dung o dinh va xuong doc
        }
    }
    
    return l; // khi l == r thi do chinh la peak
}
