ans = 10000
def solution(s):
    global ans

    for now_len in range(1 , int(len(s)/2)+2):
        #+2 인 이유 -> 홀수길이의 문자열일때를 생각해보자 !
        left = 0
        right = now_len
        combo = 1
        save = 0
        while left < len(s):

            if s[left: left + now_len] == s[right: right + now_len]:
                right += now_len
                combo += 1
                continue
            else:
                real_len = right - left
                compress_len = now_len + len(str(combo))
                if compress_len < real_len:
                    save += real_len - compress_len
                combo = 1
                left = right
                right = right + now_len
        if len(s) - save < ans:
            ans = len(s) - save

    return ans