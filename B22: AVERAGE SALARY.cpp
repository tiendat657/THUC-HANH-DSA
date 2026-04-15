double average(vector<int>& salary) {
    double sum = 0;
    int n = (int)salary.size();
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (salary[i] < minVal) {
            minVal = salary[i];
        }
        if (salary[i] > maxVal) {
            maxVal = salary[i];
        }
        sum += salary[i];
    }
    
    return (sum - minVal - maxVal) / (n - 2);
}
