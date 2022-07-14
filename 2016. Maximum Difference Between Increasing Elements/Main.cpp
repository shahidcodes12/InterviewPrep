//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>

using namespace std;

// Extra Space - O(n) time & O(n) space
int maximumDifferenceES(vector<int> &nums)
{
    int n{(int)nums.size()};

    vector<int> suffixMax(n);

    suffixMax[n - 1] = nums[n - 1];

    for (int i{n - 2}; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }

    int ans{-1};

    for (int i{}; i < n - 1; i++)
    {
        if (suffixMax[i + 1] > nums[i])
        {
            ans = max(suffixMax[i + 1] - nums[i], ans);
        }
    }

    return ans;
}

// Optimal - O(n) time & O(1) space
int maximumDifference(vector<int> &nums)
{
    int ans{-1};

    int n{(int)nums.size()};

    int suffixMax{nums.back()};

    for (int i{n - 2}; i >= 0; i--)
    {
        if (nums[i] < suffixMax)
        {
            ans = max(ans, suffixMax - nums[i]);
        }

        suffixMax = max(nums[i], suffixMax);
    }

    return ans;
}

// Driver Code
int main()
{
    vector<int> arr{7, 1, 5, 4};

    cout << maximumDifference(arr) << "\n";

    return 0;
}