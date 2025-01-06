class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();
        if (n < 2) return ans; // No pairs possible
        
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        int closest_sum = INT_MAX;
        int best_left = 0, best_right = 0;

        while (left < right) {
            int curr_sum = arr[left] + arr[right];
            if (abs(curr_sum - target) < abs(closest_sum - target)) {
                closest_sum = curr_sum;
                best_left = left;
                best_right = right;
            }

            if (curr_sum == target) {
                ans = {arr[left], arr[right]};
                break;
            } else if (curr_sum < target) {
                left++;
            } else {
                right--;
            }
        }

        if (ans.empty()) {
            ans = {arr[best_left], arr[best_right]};
        }
        
        return ans;
    }
};


// Best left vali cheez is new
// we can take a track of elements through carrying a sum of closest sum and at last if ans is empty then put best left and best right ele.
