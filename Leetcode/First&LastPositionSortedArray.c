#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *ans = (int *)malloc(2 * sizeof(int));

    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;

    int l = 0, r = numsSize - 1;

    /* Find first occurrence */
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] >= target)
            r = m - 1;
        else
            l = m + 1;
    }

    if (l >= numsSize || nums[l] != target)
        return ans;

    ans[0] = l;

    /* Find last occurrence */
    r = numsSize - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] <= target)
            l = m + 1;
        else
            r = m - 1;
    }

    ans[1] = r;

    return ans;
}