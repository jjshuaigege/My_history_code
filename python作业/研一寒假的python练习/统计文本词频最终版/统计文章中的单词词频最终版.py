import re
import sys
import os
import cet4words
import word_varys
#得出分隔字符串，用于re
def get_spl_str(text):
    spl_chr_set = set()
    for i in text:
        if not ("a"<=i<="z" or "A"<=i<="Z"):
            spl_chr_set.add(i)
    spl_str=""
    for i in spl_chr_set:
        if i in {".","?","!",'"',"'","(",")","|","*","$","\\","[","]","^","{","}"}:
            spl_str+="\\"+ i+"|"
        else:
            spl_str+=i+"|"
    spl_str+=" "
    return spl_str
#读取文件,返回一个字典，代表词频统计结果
def readfile(file_name):
    try:
        fp1=open(file_name,"r",encoding="utf-8")
        file_text=fp1.read()
        fp1.close()
        # 得出分割字符串
        spl_str=get_spl_str(file_text)
        ret_dic=dict()
        re_s_list=re.split(spl_str,file_text)

        cet4_set=cet4words.get_cet4words_set("cet4words.txt")
        word_varys_dic=word_varys.get_word_vary_dic("word_varys.txt")
        for i in re_s_list:
            i=i.lower()   #一律改为小写
            if len(i)<=1 or i in cet4_set:   #去掉长度小于等于1和在cet-4中的单词
                continue
            else:
                if i in word_varys_dic:
                    i=word_varys_dic[i]       #去掉变形形式的单词
                ret_dic[i]=ret_dic.get(i,0)+1
        return ret_dic
    except:
        return None
#将统计结果写入目标文件
def writefile(file_name,oc_dic):
    temp_list1 = list(oc_dic.items())
    temp_list1.sort(key=lambda x: x[0])
    fp2=open(file_name,"w",encoding="utf-8")
    for i in temp_list1:
        fp2.write(i[0] + ":" + str(i[1]) + "\n")
    fp2.close()

#打开
if __name__=="__main__":
    try:
        files_list=os.listdir()
        count_list=list()
        for f in files_list:
            if os.path.isfile(f) and f.startswith("a") and f.endswith(".txt"):
                count_list.append(f)
        cnt_dic=dict()
        for c_f in count_list:
            temp_dic=readfile(c_f)
            if temp_dic==None:
                raise Exception("打不开文件:"+c_f)
            cnt_dic.update(temp_dic)
        writefile("calculation.txt",cnt_dic)
    except Exception as e:
        print(type(e),e)
    finally:
        print("calculate successfully")

