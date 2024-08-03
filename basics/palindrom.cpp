// Palindrome Number 121 => 121
// Number => reverse number
// compare revernumber and originalnum (if same true)

// Reverse Number:
// n%10 => lastDigit eliminate lastDigit => n/10

int num = 121 int tempNum = 121;
int reverseNumber = 0;
while (tempNum != 0)
{
    int lastDigit = tempNum % 10;
    reverseNumber = reverseNumber * 10 + lastDigit;
    tempNum = tempNum / 10;
}

if (num == reverseNumber)
{
    return true
}
else
{
    return false;
}
TC = > O(LOG10N)
