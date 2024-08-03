// Reverse array / string
// 1 2 3 4 5 6 7 => 7 6 5 4 3 2 1
int start = 0, end = n - 1;
while (start <= end)
{
    swap(arr[start], arr[end]);
    start++, end--
}

// string/array Palindrome
// abbba

int start = 0, end = n - 1;
while (start <= end)
{
    if (str[start] != str[end])
    {
        return false;
    }
    start++, end--
}