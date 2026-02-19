import random
import time
import matplotlib.pyplot as plt

def bubble_sort(input):
    n = len(input)
    for x in range(n):
        swapped = False
        for y in range(0, n-x-1):
            if input[y] > input[y+1]:
                input[y], input[y+1] = input[y+1], input[y]
                swapped = True
        if (swapped == False):
            break

def selection_sort(input):
    n = len(input)
    for x in range(n - 1):
        min_index = x
        for y in range(x+1, n):
            if input[y] < input[min_index]:
                min_index = y
        input[x], input[min_index] = input[min_index], input[x]

def insertion_sort(input):
    for x in range(1, len(input)):
        key = input[x]
        y = x - 1

        while y >= 0 and key < input[y]:
            input[y+1] = input[y]
            y -= 1
        input[y+1] = key

def run_algorithms(lists, order_type):
    results = {"Bubble Sort": [], "Selection Sort": [], "Insertion Sort": []}

    for size in lists:
        if order_type.lower() == "sorted":
            array = list(range(size))
        elif order_type.lower() == "reverse sorted":
            array = list(range(size, 0, -1))
        else:
            array = [random.randint(0, size*10) for _ in range(size)]

        array_copy = array.copy()
        start = time.perf_counter()
        bubble_sort(array_copy)
        results["Bubble Sort"].append(time.perf_counter() - start)

        array_copy = array.copy()
        start = time.perf_counter()
        selection_sort(array_copy)
        results["Selection Sort"].append(time.perf_counter() - start)

        array_copy = array.copy()
        start = time.perf_counter()
        insertion_sort(array_copy)
        results["Insertion Sort"].append(time.perf_counter() - start)

    return results

sizes = [50, 100, 200, 400, 500, 1000]
order_types = ["sorted", "unsorted", "reverse sorted"]

for order in order_types:
    results = run_algorithms(sizes, order)
    plt.figure(figsize=(10,6))
    for algorithm in results:
        plt.plot(sizes, results[algorithm], marker='o', label=algorithm)
    plt.title(f"Order of Growth - {order} Data")
    plt.xlabel("Input Size")
    plt.ylabel("Time Taken (s)")
    plt.xlim(50, 1000)
    plt.legend()
    plt.grid(True)
    plt.show()

# def bubble_sort(input):
#     n = len(input)
#     for x in range(n):
#         swapped = False
#         for y in range(0, n-x-1):
#             if input[y] > input[y+1]:
#                 input[y], input[y+1] = input[y+1], input[y]
#                 swapped = True
#         if (swapped == False):
#             break

# def selection_sort(input):
#     n = len(input)
#     for x in range(n - 1):
#         min = x
#         for y in range(x+1, n):
#             if input[y] < input[min]:
#                 min = y
#         input[x], input[min] = input[min], input[x]

# def insert_sort(input):
#     for x in range(1, len(input)):
#         key = input[x]
#         y = x - 1

#         while y >= 0 and key < input[y]:
#             input[y+1] = input[y]
#             y -= 1
#         input[y+1] =