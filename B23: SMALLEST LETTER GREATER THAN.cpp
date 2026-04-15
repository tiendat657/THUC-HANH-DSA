char nextGreatestLetter(vector<char>& letters, char target) {
    int n = (int)letters.size();
    int low = 0;
    int high = n - 1;
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (letters[mid] > target) {
            ans = mid;
            high = mid - 1; // tim kiem ben trai
        } else low = mid + 1;
    }
    
    return letters[ans];
}
