#############################2차원 배열############################
col = 4
row = 5
a =[[0 for col in range(col)] for row in range(row)]

for now_r in range(row):
    for now_c in range(col):
        print(a[now_r][now_c], end=" ")
    print()

############################1~2차원 배열 정렬######################################
a = [5,4,3,2,1]
a.sort()
print(a)
a.sort(reverse=True)
print(a)

a = [[1,2], [100,1],[3,4]]
a = sorted(a, key=lambda x:x[0])
print(a)
###########################dict 정렬###############################
my_dict = {}
my_dict['apple'] = 1
my_dict['banana'] = 2
my_dict['azaz'] = 0
my_dict = dict(sorted(my_dict.items(), key=lambda x:x[1]))
print(my_dict)
my_dict = dict(sorted(my_dict.items(), key=lambda x:x[0]))
print(my_dict)

##########################set 정렬#################################
s = set()
s.add(1)
s.add(1)
s.add(3)
s.add(2)
s = set(sorted(s))
print(s)

#############################deque(양방향 큐) #############################
from collections import deque
d = deque()
d.append(1)
d.append(4)
d.append(2)
d.appendleft(7)
print(d)
d.remove(2)
print(d)
d.popleft()
print(d)
d.pop()
print(d)

########################문자열###################################
sample = "AAA,BBB,CCC,DDD,EEE,FFF,GGG"
my_list = sample.split(",")
print(my_list)


