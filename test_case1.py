import random
import numpy as np

random.seed(1011)
with open("test_case1.txt","w") as output:
    list1 = [random.randint(-100_000_000, 100_000_000)/100 for i in range(1_000_000)]
    list1 = np.sort(list1)
    for number in list1:
        output.write(str(number) + ' ')
    output.write('\n')

    
    list1 = [random.randint(-100_000_000, 100_000_000)/100 for i in range(1_000_000)]
    list1 = np.sort(list1)
    list1 = list1 [::-1]
    for number in list1:
        output.write(str(number) + ' ')
    output.write('\n')

    

    for i in range(8):
        for j in range (1_000_000):
             output.write(str(random.randint(-100_000_000, 100_000_000)/100) + ' ')
        output.write('\n')

















        
 #   print([random.randint(0, 100_000_000)/100] for i in range(1_000_000)])