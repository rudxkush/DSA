    int start = 0, end = (int) nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] >= nums[start]) {  // Left Ascending Segment
            if (nums[start] <= target && target < nums[mid]) { // nums[start] <= target < nums[mid] -> end = mid - 1
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {                                // Right Ascending Segment
            if (nums[mid] < target && target <= nums[end]) { // nums[end] >= target > nums[mid] -> start = mid + 1
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
