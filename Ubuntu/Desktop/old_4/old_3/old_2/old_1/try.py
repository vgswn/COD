
import queue as qq
import copy
def cost(cs,goal):
    c=0
    for i in range(3):
        for j in range(3):
            if cs[i][j]!=goal[i][j] :
                c=c+1
    return c
def ucs(arr,par,goal):
    vis=set()
    pq = qq.PriorityQueue()
    pq.put([0,arr])
    d={}
    
    while not pq.empty():
        ds,ls=pq.get()
        vis.add(tuple(tuple(x) for x in arr))
        x=0
        y=0
        if ls.__eq__(goal):
            break

        for i in range(3):
            for j in range(3):
                if ls[i][j]==0:
                    x=i
                    y=j

        cs = copy.deepcopy(ls)
        if x-1>=0:
            cs[x-1][y],cs[x][y]=cs[x][y],cs[x-1][y]
            if vis.__contains__(tuple(tuple(x) for x in cs))==False:
                    c=cost(cs,goal)
                    print(c)
                    par[tuple(tuple(x) for x in cs)]=ls
                    pq.put([c,cs])
        cs=copy.deepcopy(ls)
        if x+1<3:
            cs[x+1][y],cs[x][y]=cs[x][y],cs[x+1][y]
            if vis.__contains__(tuple(tuple(x) for x in cs))==False:
                    c=cost(cs,goal)
                    print(c)
                    par[tuple(tuple(x) for x in cs)]=ls
                    pq.put([c,cs])
        cs = copy.deepcopy(ls)
        if y+1<3:
            cs[x][y+1],cs[x][y]=cs[x][y],cs[x][y+1]
            if vis.__contains__(tuple(tuple(x) for x in cs))==False:
                    c=cost(cs,goal)
                    print(c)
                    par[tuple(tuple(x) for x in cs)]=ls
                    pq.put([c,cs])
        cs = copy.deepcopy(ls)
        if y-1>=0:
            cs[x][y-1],cs[x][y]=cs[x][y],cs[x][y-1]
            if vis.__contains__(tuple(tuple(x) for x in cs))==False:
                if d.__contains__(tuple(tuple(x) for x in cs))==False :
                    c=cost(cs,goal)
                    print(c)
                    par[tuple(tuple(x) for x in cs)]=ls
                    pq.put([c,cs])
    
def pp(arr,par,start):
    if start.__eq__(arr):
        print(arr)
    elif tuple(tuple(x) for x in arr) not in par:
        print('Not exist')
    else:
        pp(par[tuple(tuple(x) for x in arr)],par,start)
        print(arr)
arr=[[] for i in range(3)]
ca=[]
for i in range(3):
    x=input().split(' ')
    arr[i].append(int(x[0]))
    arr[i].append(int(x[1]))
    arr[i].append(int(x[2]))
    ca.append(int(x[0]))
    ca.append(int(x[1]))
    ca.append(int(x[2]))
goal=[[1,2,3],[5,8,6],[0,7,4]]
par={}
inv=0
print(ca)
for i in range(9):
    for j in range(i+1,9):
        if ca[i]!=0 and ca[j]!=0 and ca[i]>ca[j]:
            inv=inv+1


if inv%2==1:
    print('No path')
else:
    ucs(arr,par,goal)
    pp(goal,par,arr)