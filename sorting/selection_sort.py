class selection:
    def __init__(self, data):
        self.data = data

    def selection_sort(self):
        for i in range (len(self.data)):
            min_index = i
            for j in range(i + 1, len(self.data)):
                if self.data[j] < self.data[min_index]:
                    min_index = j
            # Swap the found minimum element with the first element
            self.data[i], self.data[min_index] = self.data[min_index], self.data[i]
        return self.data

data_list= list(map(int, input("Enter numbers separated by space: ").split()))
# Create object
sorter = selection(data_list)
# Call method
result = sorter.selection_sort()
print("Sorted list:", result)