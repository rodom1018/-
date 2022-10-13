tc = int(input())
#print(parent)
def my_find(x):
    if parent[x] != x:
        return my_find(parent[x])
    else:
        return x

def my_union(a, b):
    global size
    global parent

    a = my_find(a)
    b = my_find(b)

    if a == b:
        return

    if size[a] >= size[b] :
        parent[b] = a
        size[a] += size[b]
    else:
        parent[a] = b
        size[b] += size[a]

################################
################################
for now_tc in range(tc):
    f = int(input())
    dict = {}
    id = 1
    parent = [i for i in range(200020)]
    size = [1 for i in range(200020)]

    for i in range(f):
        two_friends =input().split()
        now_ids = []
        for j in range(2):
            now_id = dict.get(two_friends[j], -1)
            if now_id == -1:
                dict[two_friends[j]] = id
                now_ids.append(id)
                id += 1
            else:
                now_ids.append(now_id)
        my_union(now_ids[0], now_ids[1])

        parent_1 = my_find(now_ids[0])
        parent_2 = my_find(now_ids[1])
        print( max(size[parent_1], size[parent_2]) )



