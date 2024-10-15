import decimal
from math import sqrt, ceil, floor
I = lambda :map(int, input().split())
n = int(input())
l ,r = I()
# def ceil(x):
#     return int(x) if x == int(x) else int(x) + 1

# def floor(x):
#     return int(x)

# (int)(floor(sqrt(b)) - ceil(sqrt(a)) + 1)

 

def floor_sqrt(x):
    s = x**0.5
    if s == int(s) and s * s == x:
        return int(s)
    if s == int(s) and s * s < x:
        return int(s)
    if s == int(s) and s * s > x:
        return int(s) - 1
    return int(s)



def ceil_sqrt(x):
    s = x**0.5
    if s == int(s) and s * s == x:
        return int(s)
    if s == int(s) and s * s < x:
        return int(s) + 1
    if s == int(s) and s * s > x:
        return int(s)
    return int(s) + 1
k = 10**(n-1)
sk = str(k)
a = str(l)
b = str(r)

spa = int(a[n // 2:])
lfa = int(a[:n // 2])
l9 = int(10**(n//2) - 1)
spb = int(b[n // 2:])
lfb = int(b[:n // 2])
ans = 0

num1 = (int)(floor_sqrt(l9) - ceil_sqrt(spa) + 1)
num2 = (int)(floor_sqrt(spb) + 1)
num3 = (int)(floor_sqrt(l9) + 1)
if lfa == int(sqrt(lfa)) * int(sqrt(lfa)):
    ans += num1
if lfb == int(sqrt(lfb)) * int(sqrt(lfb)):
    ans += num2
ans += num3 * ((int)(floor_sqrt(lfb - 1) - ceil_sqrt(lfa + 1) + 1))
# ans1 = ((int)(floor(sqrt(int(b[:n // 2]))) - ceil(sqrt(int(sk[:n // 2]))) + 1)) * ((int)(floor(sqrt(int(b[n // 2:]))) - ceil(sqrt(int(sk[n // 2:]))) + 1))
# ans2 = ((int)(floor(sqrt(int(a[:n // 2]))) - ceil(sqrt(int(sk[:n // 2]))) + 1)) * ((int)(floor(sqrt(int(a[n // 2:]))) - ceil(sqrt(int(sk[n // 2:]))) + 1))



# for i in range(n - 1):
#     a = str(l)
#     b = str(r)
#     ans += ((int)(floor(sqrt(int(b[:i + 1]))) - ceil(sqrt(int(a[:i + 1]))) + 1)) * ((int)(floor(sqrt(int(b[i + 1:]))) - ceil(sqrt(int(a[i + 1:]))) + 1))

print(ans)