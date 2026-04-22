# Algorithm - Minimum Sum Partition

The problem asks us to partition an array into two subsets $S_1$ and $S_2$ such that the absolute difference of their sums, $|sum(S_1) - sum(S_2)|$, is minimized. This can be viewed as an extension of the Subset Sum problem.

## Approach (Dynamic Programming)

1. **Calculate Total Sum:** Find the sum of all elements in the array. Let it be `totalSum`.
2. **Setup DP Array:** We want to find a subset whose sum is as close to `totalSum / 2` as possible. We use an array `dp` of boolean values of size `totalSum + 1`, where `dp[j]` represents whether a subset with sum `j` is possible.
3. **Initialize DP:** `dp[0]` is initialized to `true` (an empty subset has sum `0`). Initialize the rest to `false`.
4. **State Transition:** 
   Iterate through each element `arr[i]` of the array:
   Iterate backwards `j` from `totalSum` down to `arr[i]`:
   - Set `dp[j] = dp[j] || dp[j - arr[i]]`
   - This means a sum of `j` is possible either if it was already possible previously (without `arr[i]`), or if the sum `j - arr[i]` was possible and we just add `arr[i]` to it.
5. **Find Minimum Difference:** 
   Our goal is to make one of the subsets have a sum `j` bounded by `totalSum / 2` to minimize the difference.
   Iterate `j` backwards from `totalSum / 2` to `0`:
   - When we hit the first `j` for which `dp[j]` is `true`, we have narrowed down our largest possible subset sum $\le$ `totalSum / 2`.
   - The subsets will have sums `j` and `totalSum - j`.
   - The absolute minimized difference is `(totalSum - j) - j` = `totalSum - 2 * j`.
6. **Return Result:** Return the computed minimum difference `totalSum - 2 * j`.