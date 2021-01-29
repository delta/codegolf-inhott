n, p, q, r = map(int, input().split())
q += 1
l = [q if ch == "d" else 1 for ch in input()]
r -= sum(l) - p * (n + 2)
hi, n2 = n, n * 2
n21 = n2 + 1
lo = res = 0
l *= 2
while lo <= n and hi < n2:
    r -= l[hi]
    hi += 1
    q = hi - n
    while lo < q or (hi - lo + min(hi, n21 - lo)) * p > r:
        r += l[lo]
        lo += 1
    if res < hi - lo:
        res = hi - lo
        if res == n:
            break
print(res)