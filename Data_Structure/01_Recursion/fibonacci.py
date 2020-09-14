def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


def fib_iter(n):
    if (n < 2):
        return n
    last = 0
    current = 1
    for i in range(2, n + 1):
        tmp = current
        current += last
        last = tmp
    return current
