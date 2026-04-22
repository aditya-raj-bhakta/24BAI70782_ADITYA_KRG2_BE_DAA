# Dry Run

**Problem Name:** Minimum Sum Partition  
**Example Input:** `arr[] = {1, 6, 11, 5}`  
**Number of elements ($n$):** `4`

## Step 1: Calculate Total Sum
`totalSum` = $1 + 6 + 11 + 5 = 23$

## Step 2: Initialize DP Table
Create `dp` array of size `totalSum + 1` = $24$, initialized to `false` except for `dp[0]` which is `true`.
`dp[0]` = `true`

## Step 3: Fill DP Table

### Iteration 1 `i = 0`, `arr[0] = 1`
Inner loop `j` from `23` down to `1`:
- For `j = 1`: `dp[1] = dp[1] || dp[0] = false || true = true`
**Active sums so far:** `{0, 1}`

### Iteration 2 `i = 1`, `arr[1] = 6`
Inner loop `j` from `23` down to `6`:
- For `j = 7`: `dp[7] = dp[7] || dp[7 - 6] = dp[7] || dp[1] = false || true = true`
- For `j = 6`: `dp[6] = dp[6] || dp[6 - 6] = dp[6] || dp[0] = false || true = true`
**Active sums so far:** `{0, 1, 6, 7}`

### Iteration 3 `i = 2`, `arr[2] = 11`
Inner loop `j` from `23` down to `11`:
- Since active sums shifted by `11`, new active sums will form:
  - `0 + 11 = 11`
  - `1 + 11 = 12`
  - `6 + 11 = 17`
  - `7 + 11 = 18`
- `dp[11] = dp[12] = dp[17] = dp[18] = true`
**Active sums so far:** `{0, 1, 6, 7, 11, 12, 17, 18}`

### Iteration 4 `i = 3`, `arr[3] = 5`
Inner loop `j` from `23` down to `5`:
- Active sums shift by `5`:
  - `0 + 5 = 5`
  - `1 + 5 = 6` (already true)
  - `6 + 5 = 11` (already true)
  - `7 + 5 = 12` (already true)
  - `11 + 5 = 16`
  - `12 + 5 = 17` (already true)
  - `17 + 5 = 22`
  - `18 + 5 = 23`
- `dp[5] = dp[16] = dp[22] = dp[23] = true`
**Final active possible sums:** `{0, 1, 5, 6, 7, 11, 12, 16, 17, 18, 22, 23}`

## Step 4: Find the Minimum Difference
Start `j` from `totalSum / 2` = $23 / 2 = 11$.
Check if `dp[j]` is `true`, decrementing `j`.

- `j = 11`
- check `dp[11]` $\rightarrow$ `true` 

We found the largest possible sum $\le 11$ that can be formed by a subset.

## Step 5: Compute Difference
The two subset sums are `j = 11` and `totalSum - j` = $23 - 11 = 12$.
Difference = $|sum(S_1) - sum(S_2)|$ = $|11 - 12|$ = $|2 - j|$ = $23 - 2(11)$ = **$1$**

## Output
**Answer is 1.**