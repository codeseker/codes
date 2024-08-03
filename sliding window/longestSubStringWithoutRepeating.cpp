class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int mxLen = 0;
        unordered_map<char, bool> mpp;

        int n = s.size();
        while (right < n)
        {
            char ch = s[right];
            if (mpp[ch] == false)
            {
                mxLen = max(mxLen, (right - left) + 1);
                mpp[ch] = true;
                right++;
            }
            else
            {
                // just go with one
                mpp[s[left]] = false;
                left++;
            }
        }

        return mxLen;
    }
};