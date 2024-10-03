#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize the binary search range
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size(), n2 = nums2.size();
        int left = 0, right = n1;
        const int k = (n1 + n2 + 1) / 2; // Total number of elements in the left half

        while (left < right) {
            int m1 = left + (right - left) / 2;
            int m2 = k - m1;

            // Adjust the binary search bounds
            if (nums1[m1] < nums2[m2 - 1]) {
                left = m1 + 1;
            } else {
                right = m1;
            }
        }

        int m1 = left;
        int m2 = k - m1;

        // Calculate the left half's maximum element
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], 
                     m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

        // If the total number of elements is odd, return the middle element
        if ((n1 + n2) % 2 == 1) {
            return c1;
        }

        // Calculate the right half's minimum element
        int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1], 
                     m2 >= n2 ? INT_MAX : nums2[m2]);

        // If the total number of elements is even, return the average of the two middle elements
        return (c1 + c2) * 0.5;
    }
};
