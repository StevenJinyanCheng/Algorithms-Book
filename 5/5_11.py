def str2dict(s: str) -> dict[str, int]:
    if s.startswith('{') and s.endswith('}'):
        s = s[1:-1]
    if len(s) == 0:
        return dict({})
    l = s.split(',')
    dl = []
    for i in l:
        i.replace(' ', '')
        dl.append((i.split(':')[0], int(i.split(':')[1])))
    return dict(dl)
def solve_problem(d1: dict[str, int], d2: dict[str, int]) -> str:
    d1keys = list(d1.keys())
    d2keys = list(d2.keys())
    adds = []
    dels = []
    mods = []
    for i in d2keys:
        if i not in d1keys:
            adds.append(i)
    for i in d1keys:
        if i not in d2keys:
            dels.append(i)
    for i in d1keys:
        if i in d2keys:
            if d1[i] != d2[i]:
                mods.append(i)
    s = ""
    adds.sort()
    dels.sort()
    mods.sort()
    if len(adds) != 0:
        s += "+"
        s += ",".join(adds)
        s += ";"
    if len(dels) != 0:
        s += "-"
        s += ",".join(dels)
        s += ";"
    if len(mods) != 0:
        s += "*"
        s += ",".join(mods)
        s += ";"
    if len(s) == 0:
        s = "No changes"
    return s
def Solve():
    s1 = input()
    s2 = input()
    print(solve_problem(str2dict(s1), str2dict(s2)))
Solve()