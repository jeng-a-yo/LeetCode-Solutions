/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



// Solution 1

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

// Solution 2

typedef struct {
    int val;
    int idx;
} mapEntry;
 
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));

    // Creating a hash table-like structure using mapEntry
    mapEntry* map = (mapEntry*)malloc(numsSize * sizeof(mapEntry));
    for (int i = 0; i < numsSize; i++) {
        map[i].val = -1;
        map[i].idx = -1;
    }
    
    // Loop to find the two sum
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        for (int j = 0; j < i; j++) { // Checking only till current index
            if (map[j].val == complement) {
                result[0] = map[j].idx;
                result[1] = i;
                free(map);
                return result;
            }
        }
        map[i].val = nums[i];
        map[i].idx = i;
    }

    *returnSize = 0;
    free(map);
    return result;
}

// ------------------------------------------------------------------------------------------------

