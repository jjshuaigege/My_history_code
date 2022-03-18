#python C:\Users\10204\Desktop\python练习\寒假python练习\统计文章中的单词词频.py Hamlet.txt outcome.txt
import os
import sys
import re
cmd_list=sys.argv
src_file=cmd_list[1]
dst_file=cmd_list[2]
os.chdir("C:\\Users\\10204\\Desktop\\python练习\\寒假python练习")
fp1=open(src_file,"r",encoding="utf-8")
fp2=open(dst_file,"w",encoding="utf-8")
s_l=re.split(",| |:|\n|'|!|\.|\?",fp1.read())
fp1.close()
s_dict=dict()
for i in s_l:
    if i=="":
        continue
    i=i.lower()
    if i in s_dict:
        s_dict[i]+=1
    else:
        s_dict[i]=1
s_l2=list()
for i in s_dict.items():
    s_l2.append(i)
s_l2.sort(key=lambda x:(-x[1],x[0]))
for i in s_l2:
    fp2.write(i[0])
    fp2.write(":")
    fp2.write(str(i[1]))
    fp2.write("\n")
fp2.close()