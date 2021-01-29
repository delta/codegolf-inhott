fact = list()
fact.append(1)
for i in range(1, 20):
    fact.append(i * fact[i - 1])

visited = set()
c0 = [0 for _ in range(10)]
c = [0 for _ in range(10)]


def set_count(s, lst):
    for i in range(10):
        lst[i] = 0
    for ch in s:
        lst[int(ch)] += 1


def get_perms():
    ans = fact[sum(c)]
    for i in c:
        ans //= fact[i]
    return ans


def get_ans(s):
    set_count(s, c)

    for i in range(10):
        if (c0[i] and not c[i]):
            return 0

    s = ''.join(sorted(s))

    if s in visited:
        return 0
    visited.add(s)

    ans = get_perms()
    if c[0] > 0:
        c[0] -= 1
        ans -= get_perms()

    return ans


def solve():

    n = input()
    k = len(n)

    set_count(n, c0)

    ans = 0
    for i in range(1, 2**k+1):
        s = ''
        for j in range(k):
            if (i & 2**j):
                s += n[j]
        ans += get_ans(s)
    
    print(ans)


solve()