def solution(id_list, report, k):
    set_report = set(report)
    set_report = list(set_report)
    record = {string: 0 for string in id_list}
    newid_list = {string:i for i, string in enumerate(id_list)}
    #print(newid_list)
    answer = [0 for i in range(len(id_list))]

    for i in range(len(set_report)):
        people =  set_report[i].split(" ")

        fired = people[1]
        record[fired] += 1

    for i in range(len(set_report)):

        people = set_report[i].split(" ")

        firing = people[0]
        fired = people[1]
        if record[fired] >= k:
            answer[newid_list[firing]]+=1;
    return answer

id_list = ["con", "ryan"]
report = ["ryan con", "ryan con", "ryan con", "ryan con"]
print(solution(id_list, report, 3))