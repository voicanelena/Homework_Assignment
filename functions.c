#include<stdio.h>
#include<string.h>

#define MIN(a, b, c) (((a) < (b)) ? (((a) < (c)) ? (a) : (c)) : (((b) < (c)) ? (b) : (c)))

int min_operations_to_correct(char *S, char *grammar_rule) {
    // lengths of the input string and the grammar rule
    int m = strlen(grammar_rule);
    int n = strlen(S);

    // initialize a 2D array to store the minimum operations for substrings
    int dp[m + 1][n + 1];

    // initialize the first row and column of the table
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    // fill the table using dynamic programming
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (grammar_rule[i - 1] == S[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = MIN(dp[i - 1][j] + 1,     // deletion
                               dp[i][j - 1] + 1,     // insertion
                               dp[i - 1][j - 1] + 1); // substitution
        }
    }

    // return the minimum number of operations required
    return dp[m][n];
}
