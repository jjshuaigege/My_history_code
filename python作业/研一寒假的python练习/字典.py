dc1=dict()
print(dc1)
#字典的键必须是不可变的数据类型，如字符串，整数，小数，元组
t_1=(1,8,10)
dc1={t_1:"fsd",(8,):980,9.8:"tiger",45:"shiwo","shenguozhi":["handsome","brilliant"]}
for i in dc1:
    print(i,end=" ")
    print(dc1[i])
#查找不存在的键会引起异常
try:
    print(dc1["hh"])
except Exception as e:
    print(type(e),":",e)
#字典添加新元素
dc1["new"]=['g','u','y']
print(dc1)

#get(key,v), 若字典存在键key，则返回对应的值，否则返回v
print(dc1.get(9.8,10))
print(dc1.get("n_exist",58))

"""
items()，返回所有键值对的序列
keys()，返回所有键的序列
values()，返回所有值的序列
"""
for i in dc1.items():
    print(i,end=" ")
print("")
if "new" in dc1.keys():
    print("在")
else:
    print("不在")
for i in dc1.values():
    print(i,end=" ")
print("")
