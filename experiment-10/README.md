# Experiment 10: Distinct Subsequences

## 1. Code
Source code is provided in `DistinctSubsequences.cpp`.

## 2. Algorithm
We use Dynamic Programming.

1. Let `m = s.length()` and `n = t.length()`.
2. Create DP table `dp` of size `(m + 1) x (n + 1)`.
3. Meaning of state:
   - `dp[i][j]` = number of ways to form first `j` characters of `t` using first `i` characters of `s`.
4. Base cases:
   - `dp[i][0] = 1` for all `i` (empty `t` can always be formed).
   - `dp[0][j] = 0` for all `j > 0` (non-empty `t` cannot be formed from empty `s`).
5. Transition:
   - If `s[i-1] == t[j-1]`:
     - Take this character + skip this character.
     - `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`
   - Else:
     - Must skip character from `s`.
     - `dp[i][j] = dp[i-1][j]`
6. Final answer is `dp[m][n]`.

## 3. Time and Space Complexity
- Time Complexity: O(m x n)
- Space Complexity: O(m x n)

Where:
- `m` = length of `s`
- `n` = length of `t`

## 4. Dry Run
### Example 1
- Input: `s = "rabbbit"`, `t = "rabbit"`
- Output: `3`

Reason:
There are 3 different ways to delete exactly one `'b'` from `"rabbbit"` to make `"rabbit"`.

### Example 2
- Input: `s = "babgbag"`, `t = "bag"`
- Output: `5`

Possible index choices `(b, a, g)` from `s`:
1. `(0, 1, 3)`
2. `(0, 1, 6)`
3. `(0, 5, 6)`
4. `(2, 5, 6)`
5. `(4, 5, 6)`

So total distinct subsequences = `5`.

## 5. Code Accepted Screenshot
Place your accepted screenshot in this folder with name `accepted.png`.

Example reference in markdown:

![Code Accepted](accepted.png)
