ord_a = ord('a')

def solve():
    cnt = [[0, i] for i in range(10)]
    starts = [False for _ in range(10)]
    n = int(input())
    for _ in range(n):
        s = input()
        place_val = 1
        length = len(s)
        for i in range(length-1, -1, -1):
            cnt[ord(s[i]) - ord_a][0] += place_val
            place_val *= 10
        starts[ord(s[0]) - ord_a] = True

    cnt.sort()
    digit = 1
    ans = 0
    flag = True

    for i in range(9, -1, -1):
        if not starts[cnt[i][1]] and flag:
            flag = False
        else:
            ans += cnt[i][0] * digit
            digit += 1

    print(ans)


solve()