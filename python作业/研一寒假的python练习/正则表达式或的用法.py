import re
# sample_1="(\w{4}ces)|(\w{4}ce)|(p\w)"
sample_1="(\w{4}ces)|(\d{3}fj)|(p\w)"
oc=re.finditer(sample_1,"你好dbsces213fjflpsdk")      #对于“|”实际为短路匹配
for i in oc:
    print(i.group(1,2,3))
    print(i.start(2)) #返回该匹配结果的第二组在原字符串中的起始位置
    print(i.end(2))
    print(i.span(2))
    print(i.lastindex)
# for i in oc:
#     print(i)