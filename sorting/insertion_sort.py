def insertion_sort(lst):
    for i in range(1, len(lst)):
        curr = lst[i]
        prev = i - 1
        while prev >= 0 and lst[prev] > curr:
            lst[prev + 1] = lst[prev]
            prev -= 1
            lst [prev + 1] = curr
    return lst


data_list = list(map(int, input("Enter numbers separated by space: ").split()))

result = insertion_sort(data_list)
print("Sorted list:", result)
