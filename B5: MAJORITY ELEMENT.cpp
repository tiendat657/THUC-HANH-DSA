    --- BAI GIAI ---

int majorityElement(vector<int>& nums) {
    // thuat toan Boyer-Moore Voting (thuat toan bau cu)
    
    int candidate = 12345;
    int count = 0;
    
    for (int i = 0; i < (int)nums.size(); i++) {
        if (count == 0) { // khoi tao / doi phe
            candidate = nums[i];
        }
        
        if (candidate != nums[i]) { // neu la phe phan doi
            count--;
        } else { // neu la phe ung ho
            count++;
        }
    }
    return candidate;
}
