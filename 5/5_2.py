# Just a simple abs function
def _abs(n):
    return n if n > 0 else -n
# A weird transformation
def ducci(l: list):
    newlist = []
    for i in range(len(l)-1):
        newlist.append(_abs(l[i+1]-l[i]))
    newlist.append(_abs(l[-1]-l[0]))
    return newlist
# solve
def solve_problem():
    n = int(input())
    l = []
    s: set = {()}
    k = ""
    try:
        for i in range(n):
            k = input()
            l.append(int(k))
    except Exception:
        L = k.split()
        for i in L:
            l.append(int(i))
        
    while True:
        if tuple(l) in s:
            if len(list(filter(lambda x: x != 0, l))) == 0:
                print('ZERO')
                break
            else:
                print('LOOP')
                break
        l = ducci(l)
        s.add(tuple(l))
solve_problem()