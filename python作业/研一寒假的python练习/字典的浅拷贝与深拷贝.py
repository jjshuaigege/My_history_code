import copy
if __name__=="__main__":
    #此处是浅拷贝
    d_1={"user":"sgz",68:[1,2]}
    d_2=d_1.copy()
    d_2["new"]="person"
    print(d_1,d_2)
    d_2[68].append(33)
    print(d_1,d_2)
    #此处是深拷贝
    d_1 = {"user": "sgz", 68: [1, 2]}
    d_2 = copy.deepcopy(d_1)
    d_2["new"] = "person"
    print(d_1, d_2)
    d_2[68].append(33)
    print(d_1, d_2)