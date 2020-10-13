def merge(S1, S2, S):
    """
    Merge two wroted Python lists S1 and S2 into properly sized list S.
    """
    i = j = 0
    while i + j < len(S):
        if j == len(S2) or (i < len(S1) and S1[i] < S2[j]):
            S[i + j] = S1[i]
            i += 1
        else:
            S[i + j] = S2[j]
            j += 1


def merge_sort(S):
    """
    Sort the elements of Python list S using the merge-sort algorithm
    """
    n = len(S)
    if n < 2:
        return  # list is already sorted
    # divide
    mid = n // 2
    S1 = S[0:mid]
    S2 = S[mid:n]

    # conquer
    merge_sort(S1)
    merge_sort(S2)

    # merge results
    merge(S1, S2, S)


if __name__ == "__main__":
    l = [5, 3, 8, 4, 9, 1, 6, 2, 7]
    print("Original : ", l)
    merge_sort(l)
    print(l)
