#include <iostream>
const int MAXN = 1e4 + 3;
const int MOD = 1e9 + 7;
int n;
int height[MAXN];
int height_max[MAXN];
int dp[MAXN][MAXN];

int getValue(int i, int j)
{
    if (i < 0)
        return 0;
    if (j < 0 || j > height_max[i])
        return 0;
    return dp[i][j];
}
int main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> height[i];
    for (int i = 1; i <= n; ++i)
    {
        if (i <= (n + 1) / 2)
            height_max[i] = i - 1;
        else
            height_max[i] = n - i;
    }

    for (int i = 1; i <= n; ++i)
        if (height[i] > height_max[i])
        {
            printf("0");
            return 0;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= height_max[i] + 2; ++j)
            dp[i][j] = 0;
    dp[1][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (height[i] != -1)
        {
            dp[i][height[i]] = (dp[i][height[i]] + getValue(i - 1, height[i] - 1)) % MOD;
            dp[i][height[i]] = (dp[i][height[i]] + getValue(i - 1, height[i])) % MOD;
            dp[i][height[i]] = (dp[i][height[i]] + getValue(i - 1, height[i] + 1)) % MOD;

            continue;
        }

        for (int j = 0; j <= height_max[i]; ++j)
        {
            dp[i][j] = (dp[i][j] + getValue(i - 1, j - 1)) % MOD;
            dp[i][j] = (dp[i][j] + getValue(i - 1, j)) % MOD;
            dp[i][j] = (dp[i][j] + getValue(i - 1, j + 1)) % MOD;
        }
    }

    printf("%d", dp[n][0]);
}