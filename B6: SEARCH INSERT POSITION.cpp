      --- BAI GIAI ---
        
int searchInsert(vector<int>& nums, int target) {
        // tuong tu binary search
    int l = 0, r = (int)nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l ) / 2;
        if (nums[m] == target) {
            return m;
        } else if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l; // l la vi tri can chen: phan tu nho nhat >= target
}
