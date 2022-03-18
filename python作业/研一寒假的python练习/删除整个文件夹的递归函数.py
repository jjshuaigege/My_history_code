import os
def delete_folder(c_path):
    file_list=os.listdir(c_path)
    for file in file_list:
        file_absolute_loc=c_path+"/"+file
        if os.path.isfile(file_absolute_loc):
            os.remove(file_absolute_loc)
        else:
            delete_folder(file_absolute_loc)
    os.rmdir(c_path)
delete_folder("C:\\Users\\10204\\Desktop\\python练习\\寒假python练习\\验证删除 - 副本")