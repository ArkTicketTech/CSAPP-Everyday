import os
import datetime

# 读取参与打卡的人员名单
with open('readers.txt') as f:
    users = [line.strip() for line in f.readlines()]

# 获取当前日期和前两天日期
today = datetime.date.today()
yesterday = today - datetime.timedelta(days=1)
day_before_yesterday = today - datetime.timedelta(days=2)

missed = 0

# 检查每个人的打卡情况
for user in users:
    # 检查最近两天的所有文件名
    found = False
    for folder in [yesterday, day_before_yesterday]:
        folder_path = folder.strftime('./homeworks/%Y/%-m/%-d')
        for root, dirs, files in os.walk(folder_path):
            for file in files:
                if user.lower() in file.lower():
                    found = True
                    break
            for dir in dirs:
                if user.lower() in dir.lower():
                    found = True
                    break
            if found:
                break
        if found:
            break

    # 检查打卡情况
    if not found:
        missed = missed + 1
        print(f'{user} 今天没有打卡！')

print(f'当前{len(users)}位同学参与打卡，{missed}位老板缺卡，缺卡率：{missed/len(users)*100:.2f}%。请发2元红包{len(users)-2}份，再发一个3元红包给我。谢谢老板！')