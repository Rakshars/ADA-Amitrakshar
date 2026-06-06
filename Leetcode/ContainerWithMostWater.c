int maxArea(int* height, int heightSize)
{
    int f = 0;
    int r = heightSize - 1;
    int maxa = 0;

    while (f < r)
    {
        int h = (height[f] < height[r]) ? height[f] : height[r];

        int a = h * (r - f);

        if (a > maxa)
            maxa = a;

        if (height[f] > height[r])
            r--;
        else
            f++;
    }

    return maxa;
}