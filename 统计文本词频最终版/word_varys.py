def get_word_vary_dic(file_name):
    fp1=open(file_name,"r",encoding="gbk")
    obj_dic=dict()
    lines_list=fp1.readlines()
    for i in range(0,len(lines_list),2):
        vary_words_list=lines_list[i+1].strip().split("|")
        for j in vary_words_list:
            obj_dic[j.lower()]=lines_list[i].rstrip("\n").lower()
    return obj_dic
if __name__=="__main__":
    print(get_word_vary_dic("word_varys.txt"))
