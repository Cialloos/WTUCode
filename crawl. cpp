import requests
import pandas as pd

def get_bilibili_hot(pn=1):
    url = f"https://api.bilibili.com/x/web-interface/popular?pn={pn}&ps=20"
    headers = {
        "User-Agent": "Mozilla/5.0"
    }

    res = requests.get(url, headers=headers)
    data = res.json()

    video_list = []

    for video in data['data']['list']:
        title = video['title']
        author = video['owner']['name']
        play = video['stat']['view']
        like = video['stat']['like']
        bvid = video['bvid']
        link = f"https://www.bilibili.com/video/{bvid}"

        video_list.append({
            "标题": title,
            "UP主": author,
            "播放量": play,
            "点赞数": like,
            "链接": link
        })

    return video_list

# 爬取前2页热门视频（最多40条）
all_videos = []
for i in range(1, 3):
    print(f"正在抓取第{i}页...")
    all_videos.extend(get_bilibili_hot(pn=i))

# 保存为 Excel 表格
df = pd.DataFrame(all_videos)
df.to_excel("bilibili热门视频.xlsx", index=False)
print("✅ 爬取完成！文件已保存为：bilibili热门视频.xlsx")
