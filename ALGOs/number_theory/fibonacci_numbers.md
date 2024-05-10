## Fibonacci Numbers

Recurrence Relation: `C(n+1) = Σ (C(i) \* C(n-i)) for i = 0 to n; C(0) = 1`

### Ways to calculate Fibonacci Numbers

1. **Iterative**: `O(N)`
2. **Matrix Exponentiation**: `O(log N)`

   ```
   [ [1 1] [1 0] ]^N = [ [F(N+1) F(N)] [F(N) F(N-1)] ]
   ```

Properties:

1. Running Sum of Fibonacci Numbers: `F(0) + F(1) + F(2) + ... + F(N) = F(N+2) - 1`
2. Sum of Squares of Fibonacci Numbers: `F(0)^2 + F(1)^2 + F(2)^2 + ... + F(N)^2 = F(N) * F(N+1)`
3. Convultion of Fibonacci Numbers: `F(N) = F(M)*F(N-M+1) + F(M-1)*F(N-M)`
4. `F(N)|F(M)` if `N|M` (N>2)
5. `gcd(F(N), F(M)) = F(gcd(N, M))`
