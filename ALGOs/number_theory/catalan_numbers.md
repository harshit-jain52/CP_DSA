## Catalan Numbers

**C(n) = (2n choose n) / (n + 1)**

Recurrence Relation: `C(n+1) = Σ (C(i) \* C(n-i)) for i = 0 to n; C(0) = 1`

Examples:

1.  No. of ways to reach from (0,0) to (n,n) in 2D grid without crossing diagonal
2.  No. of ways to form valid parenthesis with n pairs (2n length)
3.  No. of ways to form BST with n nodes
4.  No. of ways to form full binary tree with _n+1_ leaves
5.  No. of triangulation ways for a convex polygon with _n+2_ sides
6.  No. of ways to connect 2n points on a circle, so that no two lines intersect
