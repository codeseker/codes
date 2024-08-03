class Solution
{
public:
    int totalFruits(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0;
        int right = 0;
        int mxLen = 0;
        unordered_map<int, int> mpp;

        while (right < n)
        {
            int curr = arr[right];
            mpp[curr]++;
            while (mpp.size() > 2)
            {
                mpp[arr[left]]--;
                if (mpp[arr[left]] == 0)
                {
                    mpp.erase(arr[left]);
                }
                left++;
            }
            mxLen = max(mxLen, right - left + 1);
            right++;
        }

        return mxLen;
    }
};