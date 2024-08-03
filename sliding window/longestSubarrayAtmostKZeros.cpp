class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;

        int mxLen = 0;
        int zeros = 0;
        int n = nums.size();
        while (right < n)
        {
            int ele = nums[right];
            if (ele == 0)
            {
                zeros++;
            }

            if (zeros <= k)
            {
                mxLen = max(mxLen, (right - left) + 1);
            }
            else
            {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }
            right++;
        }

        return mxLen;
    }
};