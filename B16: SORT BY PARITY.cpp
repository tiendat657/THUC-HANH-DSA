TWO POINTER

vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0;
    int j = (int)nums.size() - 1;
    
    while (i < j) {
        while (i < j && nums[i] % 2 == 0) {
            i++;
        }
        while (i < j && nums[j] % 2 == 1) {
            j--;
        }
        // sau khi chay xong 2 vong lap kia -> dung tai vi tri can hoan doi
        if (i < j) {
            swap(nums[i], nums[j]);
            i++; j--;
        }
    }
    
    return nums;
}
