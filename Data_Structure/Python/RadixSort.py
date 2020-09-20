from queue import Queue
import random


def radix_sort(A):
    queues = []
    for i in range(BUCKETS):
        queues.append(Queue())

    n = len(A)
    factor = 1
    for d in range(DIGITS):
        for i in range(n):
            queues[(A[i] // factor) % 10].put(A[i])
        i = 0
        for b in range(BUCKETS):
            while not queues[b].empty():
                A[i] = queues[b].get()
                i += 1
        factor *= 10
        print("step", d + 1, A)


if __name__ == "__main__":
    BUCKETS = 10
    DIGITS = 4
    data = []
    for i in range(10):
        data.append(random.randint(1, 9999))
    radix_sort(data)
    print("Radix: ", data)
