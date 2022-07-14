//
// Author : Mohammed Shahid M A
//

#include <iostream>
#include <vector>

using namespace std;

// Extra Space - O(n) time & O(n) space
vector<int> productExceptSelfES(vector<int> &nums)
{
    int size{(int)nums.size()};
    vector<int> res(size);

    vector<int> prefixProduct(size);
    vector<int> suffixProduct(size);

    prefixProduct[0] = nums[0];
    suffixProduct[size - 1] = nums[size - 1];

    for (int i{1}; i < size; i++)
    {
        prefixProduct[i] = prefixProduct[i - 1] * nums[i];
    }

    for (int i{size - 2}; i >= 0; i--)
    {
        suffixProduct[i] = suffixProduct[i + 1] * nums[i];
    }

    res[0] = suffixProduct[1];

    res[size - 1] = prefixProduct[size - 2];

    for (int i{1}; i < size - 1; i++)
    {
        res[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
    }

    return res;
}

// Optimal - O(n) time & O(1) space
vector<int> productExceptSelf(vector<int> &nums)
{
    int size{(int)nums.size()};

    vector<int> result(nums);

    for (int i{1}; i < size; i++)
    {
        result[i] = result[i] * result[i - 1];
    }

    int suffixProduct{1};

    for (int i{size - 1}; i > 0; i--)
    {
        result[i] = result[i - 1] * suffixProduct;

        suffixProduct *= nums[i];
    }
    result[0] = suffixProduct;

    return result;
}

// Driver Code
int main()
{
    vector<int> arr{1, 2, 3, 4};

    vector<int> res = productExceptSelf(arr);

    for (auto &a : res)
    {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}