def maxProduct(v):
    max = v[0]
    for i in range(len(v)):
        curr_max = v[i]
        if curr_max > max:
            max = curr_max
        acc = v[i]
        for elem_2 in v[i+1:]:
            acc *= elem_2
            if acc >= curr_max:
                curr_max = acc
                if curr_max >= max:
                    max = curr_max
    return max

while True:
    try:
        array = list(map(int,input().split()))
        array = array[:-1]
        print(maxProduct(array))

    except EOFError:
        break

