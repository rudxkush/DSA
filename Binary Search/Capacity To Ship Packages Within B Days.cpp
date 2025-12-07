bool isPossible(vector<int> &weights, int capacity, int number_of_days) {
    int sum = 0, usedDays = 1;
    
    for(int weight : weights) {
        if(weight > capacity) return false; 
    
        if(sum + weight > capacity) {
            usedDays++;
            sum = 0;
        }
        sum += weight;
    }
    
    return usedDays <= number_of_days;
}

int Solution::solve(vector<int> &weights, int number_of_days) {
    int start = 0, end = 0;

    for(int weight : weights) {
        start = max(start, weight);
        end += weight;
    }
    
    while(start < end) {
        int mid = start + (end - start) / 2;
        
        if(isPossible(weights, mid, number_of_days)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    
    return start;
}
