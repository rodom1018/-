import json, requests

data = requests.get("http://apis.data.go.kr/6410000/GOA/GOA001?type=json").json()

# r = requests.get('https://api.github.com/events')
# r = requests.get('https://api.github.com/events').json()

# post -> 등록 ,  put -> 수정
# r = requests.post('https://httpbin.org/post', data = {'key':'value'})
# r = requests.put('https://httpbin.org/put', data = {'key':'value})

# r  = requests.delete('https://httpbin.org/delete')
# r  = requests.head('https://httpbin.org/get')
# r  = requests.options('https://httpbin.org/get')


data2 = data["items"]
print(data2)
print(len(data2))

for item in data["items"]:
    try:
        print(item["busno"], end=" / ")
        print(item["area"], end = " / ")
        print(item["name"])
    except:
        pass

# 응답 데이터의 상태코드 확인
status = requests.get("http://apis.data.go.kr/6410000/GOA/GOA001").raise_for_status()
print(status)


# url = 'https://api.github.com/some/endpoint'
# payload = {'some' : 'data'}
# r = requests.post(url, json = payload)




