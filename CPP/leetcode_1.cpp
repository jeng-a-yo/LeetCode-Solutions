#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


<<<<<<< HEAD

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap; 

        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (indexMap.count(complement)){
                return {indexMap[complement], i};
            }else{
                indexMap[nums[i]] = i;
            }
        }
        return {};
=======
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        throw invalid_argument("No two sum solution");
>>>>>>> 4dfb8ff6355366dab227ca771f6486265d1c4841
    }
};