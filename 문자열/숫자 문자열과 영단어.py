
number_list = ["zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine"]

def solution(s):
    answer = ""
    left = 0
    right = 1
    while(True):
        if left >= len(s):
            break

        if s[left:right].isdigit():
            answer = answer + s[left:right]
            left = right
            right= left+1
            continue

        for i in range(10):
            if s[left:right] == number_list[i]:
                answer = answer + str(i)
                left = right
                right = left+1
                break
            if i==9 :
                right += 1
    answer = int(answer)
    return answer