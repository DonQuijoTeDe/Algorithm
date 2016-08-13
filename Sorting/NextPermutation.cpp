/*
* Computes the next lexicographical permutation of the specified
* vector in place, returning whether a next permutation existed.
* (Returns false when the argument is already the last possible
* permutation.)
*/
template <typename T>
bool nextPermutation(vector<T>& a) {
    int i, j;

    // Empty
    if (!a.size())
        return false;

    // 1. Find largest index i, s.t a[i - 1] < a[i]
    for (i = a.size() - 1; i > 0; i--)
        if (a[i - 1] < a[i])
            break;

    // Only one element
    if (i == 0)
        return false;

    // 2. Find largest index j s.t j >= i and a[j] > a[i - 1]
    for (j = a.size() - 1; j >= i; j--)
        if (a[j] > a[i - 1])
            break;

    // 3. Swap a[i - 1] and a[j]
    swap(a[i - 1], a[j]);

    // 4. Reverse the suffix starting at a[i]
    reverse(a.begin() + i, a.end());

    return true;
}
