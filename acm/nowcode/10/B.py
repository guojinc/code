import re
I = lambda: map(int, input().split())
n, m = I()
al = {}
for _ in range(n):
    s = input()
    sslist = re.split(r'<|>| |,|;', s)
    slist = []
    for i in range(len(sslist)):
        if sslist[i] != '':
            slist.append(sslist[i])
    print(sslist)
    print(slist)
    al[slist[-1]] = slist[:-1]


def pri(lis, op):
    if op[0] == 'first':
        print(lis[0], end='')
        pri(lis[1:], op[1:])
        return
    if op[0] == 'second':
        print(lis[1], end='')
        return
    if lis[0] != 'pair':
        print(lis[0], end='')
        return
    if (lis[0] == 'pair'):
        print('pair<', end='')
        pri(lis[1:])
        print(',', end='')
        pri(lis[2:])
        print('>', end='')
        return

    

for _ in range(m):
    s = input()
    ss = re.split(r'.')
    lis = al[ss[0]]
    pri(lis, ss[1:])
    print()
