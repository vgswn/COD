import copy
class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)
def bfs(arr,par,goal):
    vis=[]
    q=Stack()
    q.push(arr)
    vis.append(arr)
    d=0
    while not q.isEmpty():
        d=d+1
        if d>=362880:
            break
        ls=q.pop()
        x=0
        y=0
        d=d+1
        if ls.__eq__(goal):
            break
        #print(ls)
        for i in range(3):
            for j in range(3):
                if ls[i][j]==0:
                    x=i
                    y=j
        #print(x,y)
        cs = copy.deepcopy(ls)
        if x-1>=0:
            cs[x-1][y],cs[x][y]=cs[x][y],cs[x-1][y]
            if vis.__contains__(cs)==False:
                vis.append(cs)
                par[tuple(tuple(x) for x in cs)]=ls
                q.push(cs)
        cs=copy.deepcopy(ls)
        if x+1<3:
            cs[x+1][y],cs[x][y]=cs[x][y],cs[x+1][y]
            if vis.__contains__(cs)==False:
                vis.append(cs)
                q.push(cs)
                par[tuple(tuple(x) for x in cs)]=ls
        cs = copy.deepcopy(ls)
        if y+1<3:
            cs[x][y+1],cs[x][y]=cs[x][y],cs[x][y+1]
            if vis.__contains__(cs)==False:
                vis.append(cs)
                q.push(cs)
                par[tuple(tuple(x) for x in cs)]=ls
        cs = copy.deepcopy(ls)
        if y-1>=0:
            cs[x][y-1],cs[x][y]=cs[x][y],cs[x][y-1]
            if vis.__contains__(cs)==False:
                vis.append(cs)
                q.push(cs)
                par[tuple(tuple(x) for x in cs)]=ls
    print(vis)
def pp(arr,par,start):
    while arr.__eq__(start)==False:
        print(arr)
        arr=par[tuple(tuple(x) for x in arr)]
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
            #print(ca[i],ca[j])
#print(inv)
if inv%2==1:
    print('No path')
else:
    bfs(arr,par,goal)
    pp(goal,par,arr)
