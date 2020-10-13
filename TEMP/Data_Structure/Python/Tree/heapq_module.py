import heapq
arr = [5, 3, 8, 4, 9, 1, 6, 2, 7]
print(arr)

heapq.heapify(arr)
print(arr)
print(heapq.heappop(arr))
print(heapq.heappop(arr))
print(heapq.heappop(arr))
print(arr)
