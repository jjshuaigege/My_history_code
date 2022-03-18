def get_cet4words_set(file_name):
    obj_set=set()
    fp1=open(file_name,"r",encoding="gbk")
    lines_list=fp1.readlines()
    for i in lines_list:
        if i.startswith("$"):
            i=i.rstrip("\n").lstrip("$").lower()
            if(len(i)>1):
                obj_set.add(i)
    return(obj_set)
if __name__=="__main__":
    print(get_cet4words_set("cet4words.txt"))
