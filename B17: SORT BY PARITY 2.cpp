TWO POINTER

vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0;
    int j = 1;
    int n = (int)nums.size();
    
    while (i < n && j < n) {
        while (i < n && j < n && nums[i] % 2 == 0) {
            i += 2;
        }
        while (i < n && j < n && nums[j] % 2 == 1) {
            j += 2;
        }
        if (i < n && j < n) {
            swap(nums[i], nums[j]);
            i += 2; j += 2;
        }
    }
    
    return nums;
}
