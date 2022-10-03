import requests

X_AUTH_TOKEN = "6a6e55628acaa519786707632f1bc709"
AUTH_KEY = ""

def init1():
    global X_AUTH_TOKEN
    global AUTH_KEY

    headers = {
        'X-Auth-Token': X_AUTH_TOKEN,
    }

    json_data = {
        'problem': 1,
    }

    response = requests.post('https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/start', headers=headers,
                             json=json_data).json()
    AUTH_KEY = response['auth_key']


def init2():
    global X_AUTH_TOKEN
    global AUTH_KEY

    headers = {
        'X-Auth-Token': X_AUTH_TOKEN,
    }

    json_data = {
        'problem': 2,
    }

    response = requests.post('https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/start', headers=headers,
                             json=json_data).json()
    AUTH_KEY = response['auth_key']

######################################################################
###########################main#######################################
######################################################################

init1()

headers = {
    'Authorization': AUTH_KEY,
    'Content-Type': 'application/json',
}
#user info 를 가져오고 ( 몇 명 인지 ? 세기위해서 . )
user_info = requests.get('http://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/user_info', headers=headers).json()

user_info = user_info['user_info']
print(user_info)
for i in range(len(user_info)):
    user_info[i]['grade'] = 40000
print(user_info)
############################################게임시작###########################################3
for now_time in range(596):
    if now_time == 595:
        change_user = requests.put('http://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/change_grade',
                                   headers=headers, json=user_info).json()
    print(now_time)
    # 대기열
    ready_list = requests.get('https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/waiting_line',
                              headers=headers).json()
    ready_list= ready_list['waiting_line']

    # print(ready_list) [{'id': 13, 'from': 1}, {'id': 17, 'from': 1}, 
    match_data = []
    for now_user in range(0,len(ready_list),2):
        if now_user + 1 >= len(ready_list):
            break
        temp = []
        temp.append(ready_list[now_user]["id"])
        temp.append(ready_list[now_user+1]["id"])
        match_data.append(temp)
        #print(temp)

    #MATCH ( 게임 시작 )
    json_data = {
        'pairs': match_data,
    }
    match = requests.put('http://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/match', headers=headers,
                            json=json_data).json()

    #이번 턴에 게임이끝난 유저들의 게임 결과 반환 .
    game_list = requests.get('http://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/game_result',
                               headers=headers).json()

    game_list = game_list['game_result']

    for now_game in range(len(game_list)):
        win_user = game_list[now_game]["win"]-1
        lose_user = game_list[now_game]["lose"]-1
        taken_time = game_list[now_game]["taken"]

        win_probability = user_info[win_user]['grade'] / (user_info[win_user]['grade'] + user_info[lose_user]['grade'])
        lose_probability = user_info[lose_user]['grade'] / (user_info[win_user]['grade'] + user_info[lose_user]['grade'])

        user_info[win_user]['grade'] += (40-taken_time) * (1-win_probability)
        user_info[lose_user]['grade'] -= (40-taken_time) * (1-lose_probability)





#####################################게임끝 ##################

score = requests.get('http://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod/score', headers=headers).json()
print(score)
