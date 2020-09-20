MAX_VAL = 1000


def counting_sort(A):
    output = [0] * MAX_VAL
    count = [0] * MAX_VAL

    for i in A:
        count[i] += 1

    for i in range(MAX_VAL):
        count[i] += count[i - 1]

    for i in range(len(A)):
        output[count[A[i]] - 1] = A[i]
        count[A[i]] -= 1

    for i in range(len(A)):
        A[i] = output[i]


if __name__ == "__main__":
    l = [1, 4, 1, 2, 7, 5, 2]
    counting_sort(l)
    print(l)
