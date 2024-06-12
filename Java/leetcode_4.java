import java.util.Arrays;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        return findMedian(mergeAndSort(nums1, nums2));
    }

    public static int[] mergeAndSort(int[] array1, int[] array2) {
        // Calculate the length of the merged array
        int mergedLength = array1.length + array2.length;
        // Create the merged array
        int[] mergedArray = new int[mergedLength];
        
        // Copy elements from the first array
        System.arraycopy(array1, 0, mergedArray, 0, array1.length);
        // Copy elements from the second array
        System.arraycopy(array2, 0, mergedArray, array1.length, array2.length);
        
        // Sort the merged array
        Arrays.sort(mergedArray);
        
        return mergedArray;
    }

    public static double findMedian(int[] array) {
        int length = array.length;
        if (length % 2 == 0) {
            return ((double) array[length / 2 - 1] + (double) array[length / 2]) / 2.0;
        } else {
            return (double) array[length / 2];
        }
    }
}



class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        // Ensure nums1 is the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = n1;
        int medianPos = (n1 + n2 + 1) / 2;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = medianPos - partition1;

            int maxLeft1 = (partition1 == 0) ? Integer.MIN_VALUE : nums1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? Integer.MAX_VALUE : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? Integer.MIN_VALUE : nums2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? Integer.MAX_VALUE : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((n1 + n2) % 2 == 0) {
                    return ((double)Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2;
                } else {
                    return (double)Math.max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

        throw new IllegalArgumentException("Input arrays are not sorted.");
    }
}

