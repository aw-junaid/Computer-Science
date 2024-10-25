import math

def find_pythagorean_triplets(limit):
    c = 0
    m = 2
    while c < limit:
        for n in range(1, m):
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n * n
            if c > limit:
                break
            if a == 0 or b == 0 or c == 0:
                continue
            print(a, b, c)
        m += 1

find_pythagorean_triplets(100)
