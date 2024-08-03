// Binary Search: It is an searching technique which works on divide and conquer approach in this we eliminate one half and search in other half, the most important thing to note is that the input should always be sorted, and It is the most fast searching algorithm.

// 1, 2, 3 4 5 6 7 8 9 10 key = > 9 divide = start + (end - start) / 2 = > to avoid from int overflow arr[mid] compare = > equal to key, less tha equal to key, greater than key ar[mid] == key = > return mid // true
// arr[mid]<key =>
// start = mid + 1(left half eliminate)
// arr[mid] > key = > end = mid - 1(right half eliminate)

int start = 0,
    end = n - 1;

while (start <= end)
{
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }
}
TC = > O(Log2N)
