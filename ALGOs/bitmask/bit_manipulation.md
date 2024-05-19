### Compiler Functions

```cpp
int a;
builtin_clz(a); // Count Leading Zeroes
builtin_ctz(a); // Count Trailing Zeroes
builtin_popcount(a); // Count set bits

long long x;
builtin_popcountll(x);
```

### Short Techniques & Tricks

```cpp
// Check if ith bit is set
((n>>i) & 1)
(n & (1LL<<i))

// Unset rightmost set bit
(n & (n-1))

// Check if number is odd
(n & 1)

// Multiply by 2
(n << 1)

// Divide by 2
(n >> 1)

// Find the rightmost unset bit
log2(n ^ (n | (n+1)))
```

### Some expressions

`A+B = A&B + A|B = 2*(A&B) + A^B`

### XOR

```cpp
// Given N, find cumulative XOR: 1^2^....^N  [N <= 1e18]
switch(N%4){
    case 0:
        return N;
    case 1:
        return 1;
    case 2:
        return N+1;
    case 3:
        return 0;
}
```

### Bitmask

```cpp
int n;
for(int mask=0; mask<(1<<n); mask++) // Masks
{
    for(int sub=mask; sub; sub=(sub-1)&mask) // Submasks
    {
        // Code
    }
} // O(3^N)
```
