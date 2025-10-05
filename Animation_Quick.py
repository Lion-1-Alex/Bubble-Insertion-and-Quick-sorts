import numpy as np
import matplotlib.pyplot as plt

def read_all_steps(filename):
    with open(filename, 'r') as file:
        steps = []
        for line in file:
            step_data = list(map(int, line.strip().split()))
            steps.append(step_data)
    return steps

filename = "/Users/aleksandrrubcov/Desktop/HomeWork/laba3/QuickSort/Quick.txt"
all_steps = read_all_steps(filename)

array_length = len(all_steps[0])
max_value = max(all_steps[0])

plt.xlim(0, array_length)
plt.ylim(0, max_value + 10)

for step in all_steps:
    plt.clf()
    plt.xlim(0, array_length)
    plt.ylim(0, max_value + 10)
    plt.bar(list(range(len(step))), step, color='red')
    plt.pause(0.1)

plt.show()