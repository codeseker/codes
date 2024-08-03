// Insertion Sort: Insertion Sort works by building a sorted portion of the array one element at a time. It takes the current element and places it in its correct position within the already sorted portion of the array.
for (int i = 1; i < n; i++)
{
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key,
    // to one position ahead of their current position
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
}