//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>

using namespace std;

// Brute Force - O(n^2) time & O(1) space
vector<int> twoSumBF(vector<int> &nums, int target)
{
    vector<int> res;

    int size = (int)nums.size();

    for (int idx1 = 0; idx1 < size; idx1++)
    {
        for (int idx2 = idx1 + 1; idx2 < size; idx2++)
        {
            if (nums[idx1] + nums[idx2] == target)
            {
                res.push_back(idx1);
                res.push_back(idx2);
                break;
            }
        }
    }

    return res;
}

// Optimal - O(n) time & O(n) space
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> valueMap;

    int size{(int)nums.size()};

    for (int idx1{}; idx1 < size; idx1++)
    {
        int remain = target - nums[idx1];

        if (valueMap.count(remain))
        {
            return vector<int>({valueMap[remain], idx1});
        }

        valueMap[nums[idx1]] = idx1;
    }

    return vector<int>({0, 0});
}

// Driver Code
int main()
{
    vector<int> nums{2, 7, 11, 15};

    int target{9};

    vector<int> res = twoSum(nums, target);

    for (auto &num : res)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}