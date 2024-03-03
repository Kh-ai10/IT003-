import numpy as np
import time

with open("test_case1.txt", "r") as input:
    test_case1 = input.readlines()

    i = 1
    for line in test_case1:
       
        list1 = [float (x) for x in line.split()]

        start = time.time()

        list1 = np.sort(list1)

        end = time.time()
        
        print(f"nympy_sort time_data {i}:", round((end - start)*1000), "\tms\n")
        i+=1
