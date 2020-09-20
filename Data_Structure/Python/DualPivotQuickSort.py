def partitionDP(A, low, high):
    if A[low] > A[high]:
        A[low], A[high] = A[high], A[low]

    j = low + 1
    g = high - 1
    k = low + 1
    lp_val = A[low]
    rp_val = A[high]

    while (k <= g):
        if (A[k] < lp_val):
            A[k], A[j] = A[j], A[k]
            j += 1

        elif (A[k] >= rp_val):
            while (A[g] > rp_val and k < g):
                g -= 1
            A[k], A[g] = A[g], A[k]
            g -= 1

            if (A[k] < lp_val):
                A[k], A[j] = A[j], A[k]
                j += 1
            k += 1
    j -= 1
    g += 1
    A[low], A[j] = A[j], A[low]
    A[high], A[g] = A[g], A[high]
    return j, g


def dp_quick_sort(A, low, high):
    if low < high:
        lp, rp = partitionDP(A, low, high)
        dp_quick_sort(A, low, lp - 1)
        dp_quick_sort(A, lp + 1, rp - 1)
        dp_quick_sort(A, rp + 1, high)


if __name__ == "__main__":
    l = [5, 3, 8, 4, 9, 1, 6, 2, 7]
    print("Original : ", l)
    dp_quick_sort(l, 0, 8)
    print(l)
