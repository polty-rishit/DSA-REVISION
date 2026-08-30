def canWin(n, a):
    a.sort(reverse=True)

    prefix = [0] * n

    mx = -1
    for i in range(n):
        mx = max(mx, a[i] + i + 1)
        prefix[i] = mx

    suffix = [0] * n

    mx = -1
    for i in range(n - 1, -1, -1):
        mx = max(mx, a[i] + i)
        suffix[i] = mx

    count = 0

    for i in range(n):
        candidate_score = a[i] + n

        worst = -1

        if i > 0:
            worst = max(worst, prefix[i - 1])

        if i < n - 1:
            worst = max(worst, suffix[i + 1])

        if worst <= candidate_score:
            count += 1

    return count


def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(canWin(n, a))


main()