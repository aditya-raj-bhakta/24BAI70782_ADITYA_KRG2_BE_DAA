# Time and Space Complexity

## Time Complexity
- **Calculating the Total Sum**: Traversing the array of `n` elements takes $O(n)$ time.
- **Filling the DP Table**: There are nested loops. The outer loop runs `n` times (over the array elements) and the inner loop traverses from `totalSum` down to `arr[i]`. So, in the worst-case, it iterated approximately $O(n \times \text{totalSum})$ times.
- **Finding the Minimum Difference**: A single loop from `totalSum / 2` down to 0 takes $O(\text{totalSum})$ time.
- **Overall Time Complexity**: $O(n \times \text{totalSum})$.

## Space Complexity
- We use a 1D boolean array DP of size `totalSum + 1` to track achievable sums.
- **Overall Space Complexity**: $O(\text{totalSum})$.

Given the constraints (`n <= 100` and `arr[i] <= 1000`):
The maximum `totalSum` can be $100 \times 1000 = 100,000$. 
$O(n \times \text{totalSum}) = O(100 \times 100000) = 10^7$ operations, which executes efficiently within the typical 1-second time limit in competitive programming platforms. The space occupied by an array of 100,000 booleans is minimal (~100KB), which fits perfectly within system constraints.