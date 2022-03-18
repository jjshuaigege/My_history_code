# import re
# fp=open("三国演义.txt","r",encoding="utf-8")
# txt=fp.read()
# pt="曹操"
# oc1=re.findall(pt,txt)
# print(len(oc1))
import jieba
fp=open("三国演义.txt","r",encoding="utf-8")
txt=fp.read()
fp.close()
lst1=jieba.lcut(txt)
excludes={"将军","却说","二人","不可","荆州","不能","如此","商议","如何","主公","军士","左右","军马","引兵","次日","大喜","天下","东吴",\
          "于是","今日","不敢","魏兵","陛下","一人","都督"}
fp1=open("三国人名同义词.txt","r",encoding="utf-8")
synonyms=dict()
txt1=fp1.readlines()
for i in range(len(txt1)):
    if txt1[i].endswith("：\n"):
        org_word=txt1[i].rstrip("：\n")
        der_words=txt1[i+1].rstrip("\n").split(" ")
    for j in der_words:
        synonyms[j]=org_word
# print(synonyms)
oc_dic=dict()
for i in lst1:
    if i in synonyms:
        i = synonyms[i]
    elif len(i)<=1 or i in excludes:
        continue
    oc_dic[i]=oc_dic.get(i,0)+1

oc_lst=list(oc_dic.items())
oc_lst.sort(key=lambda x:x[1],reverse=True)
for i in range(10):
    print(oc_lst[i])