// Fibonaaci Series => 0 1 1 2 3 5 8 13 21 ....
// Either to print the series, either find me the nth fibonaci number

int n = 6 int prev2 = 0, prev1 = 1;
cout << prev2 << " " << prev1 << " ";
int cnt = 0;
while (cnt < n - 2)
{
    int curr = prev2 + prev1;
    prev2 = prev1;
    prev1 = curr;
    cnt++;
}