def binary_search(data, target, low, high):
    """
    Return index if target is found in indicated portion of a Python list.
    The search only considers the portion from data[low] to data[high] inclusive.
    """
    if low > high:
        return None  # interval is empty; no match
    else:
        mid = (low + high) // 2
        if target == data[mid]:  # found a match
            return mid
        elif target < data[mid]:
            # recur on the portion left of the middle
            return binary_search(data, target, low, mid - 1)
        else:
            # recur on the portion right of the middle
            return binary_search(data, target, mid + 1, high)


if __name__ == "__main__":
    li = [i * 3 for i in range(11)]
    target = 6
    idx = binary_search(li, target, 0, 10)
    print(li)
    print(idx)
