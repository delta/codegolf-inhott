import re

m = int(input())
s = input()
f = set()
c = 1

for i in s:
    f.add(i)
    if ('R' in f and 'L' in f) or ('U' in f and 'D' in f):
        c += 1
        f = set(i)

print(c)