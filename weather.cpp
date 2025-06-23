import requests
from bs4 import BeautifulSoup

# 中国各省会城市与其天气网对应的城市代码（部分）
cities = {
    '北京': '101010100',
    '上海': '101020100',
    '广州': '101280101',
    '南京': '101190101',
    '成都': '101270101',
    '西安': '101110101',
    '杭州': '101210101',
    '武汉': '101200101',
    '郑州': '101180101',
    '长沙': '101250101',
}

def get_weather(city_code):
    url = f"http://www.weather.com.cn/weather1d/{city_code}.shtml"
    headers = {
        'User-Agent': 'Mozilla/5.0'
    }
    resp = requests.get(url, headers=headers)
    resp.encoding = 'utf-8'
    soup = BeautifulSoup(resp.text, 'html.parser')

    # 抓取天气概况
    try:
        info = soup.find('div', class_='t').find('p', class_='wea').text
        temp = soup.find('div', class_='t').find('p', class_='tem').text.strip()
        return info, temp
    except Exception as e:
        return "获取失败", str(e)

# 显示所有城市天气
for city, code in cities.items():
    weather, temp = get_weather(code)
    print(f"{city}：{weather}，{temp}")
