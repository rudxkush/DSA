int Solution::maxArea(vector<int> &height) {
    int n = (int) height.size();
    int i = 0, j = n - 1;
    int maxArea = 0;
    while(i < j) {
        int length = min(height[i], height[j]);
        int breadth = j - i;
        int area = length * breadth;
        if(area > maxArea) {
            maxArea = area;
        }
        if(height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return maxArea;
}
