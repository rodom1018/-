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

# 단일 조건으로 정렬.
a = sorted(a, key=lambda x:x[0])

# 이중 조건으로 정렬. 
a = sorted(a, key=lambda x:(x[0],x[1]))
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

#apple 이 있으면 값을 가져오고
#apple 없으면 -1 반환.
dict.get('apple', -1)

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

inputStr = "   아기 판다와 어른 판다는 둘 다 판다입니다.    "
replaceStr = inputStr.replace("판다", "사자")
print(replaceStr)

replaceStr = inputStr.strip()
print(replaceStr)

########################deepcopy###################################
>>> import copy
>>> a = [[1,2],[3,4]]
>>> b = copy.deepcopy(a)
>>> a[1].append(5)
>>> a
[[1, 2], [3, 4, 5]]
>>> b
[[1, 2], [3, 4]]

#########################조합 순열 ####################################
items = ['1', '2', '3', '4', '5']
from itertools import permutations
print(list(permutations(items, 2)))
# [('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('2', '1'), ('2', '3'), ('2', '4'), ('2', '5'), ('3', '1'), ('3', '2'), ('3', '4'), ('3', '5'), ('4', '1'), ('4', '2'), ('4', '3'), ('4', '5'), ('5', '1'), ('5', '2'), ('5', '3'), ('5', '4')]

from itertools import combinations
print(list(combinations(items, 2)))
# [('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('2', '3'), ('2', '4'), ('2', '5'), ('3', '4'), ('3', '5'), ('4', '5')]

