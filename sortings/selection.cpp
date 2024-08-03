// Selection Sort : In Selection Sort, you typically find the minimum(or maximum) element from the unsorted portion of the array and swap it with the first unsorted element.

for (int i = 0; i < n - 1; i++)
{
    // Find the minimum element in the unsorted part of the array
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
        {
            minIndex = j;
        }
    }
    // Swap the found minimum element with the first element of the unsorted part
    if (minIndex != i)
    {
        swap(arr[i], arr[minIndex]);
    }
}