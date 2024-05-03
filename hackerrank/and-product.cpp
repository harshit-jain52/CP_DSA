long andProduct(long a, long b)
{
    long long res = 0;
    long long diff = b - a + 1;
    for (int i = 0; i <= 31; i++)
    {
        long long pow = (1LL << i);
        if (pow < diff)
            continue;
        if ((pow & a) && (pow & b))
            res |= pow;
    }
    return res;
}