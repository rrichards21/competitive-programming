#Problem: https://www.hackerrank.com/challenges/candies/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the candies function below.
def candies(n, arr):
    fwd = [1]*n
    back = [1]*n
    total = 0
    for i in range(1,len(arr)):
        if(arr[i] > arr[i-1]):
            fwd[i] = fwd[i-1] + 1
    for i in range(len(arr)-2,-1,-1):
        if(arr[i] > arr[i+1]):
            back[i] = back[i+1] + 1
    for i in range(n):
        total += max(fwd[i],back[i])
    return total


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = []

    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)

    result = candies(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
