// Quick Sort: Again Divide and conquer but it divides on the basis of pivot element we consider a pivot element and make sure all the smaller element than pivot should be in left side of the array and all the element greater than pivot should be in the right side and by this it is divide and conquer

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    = > 3

      swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        3 QuickSort(arr, l, pi - 1);
        0, 2 QuickSort(arr, pi + 1, r);
        4 5
    }
}
