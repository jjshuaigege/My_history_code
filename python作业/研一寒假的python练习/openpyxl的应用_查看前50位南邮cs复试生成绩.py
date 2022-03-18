#coding=utf-8
import openpyxl
book=openpyxl.load_workbook("D:\\复试相关\\21南邮计软网安复试名单.xlsx")
sheet=book.worksheets[0]
xue_stu_grade_dic=dict()
zhuan_stu_grade_dic=dict()
def collect_stu_name_grade_dict(major,obj_dict):
    for row in sheet.rows:
        # 更正名字列号错误
        if row[ord("B") - ord("A")].value == None:
            name_col_index = "C"
        else:
            name_col_index = "B"
        # 更正数学成绩列号错误
        if row[ord("G") - ord("A")].value == None:
            wrong_math_col_index = "G"
        else:
            wrong_math_col_index = "H"
        this_major = str(row[0].value).replace("\n", "")
        if this_major == major:
            # obj_dict[row[ord(name_col_index) - ord("A")].value] = \
            # tuple(row[i - ord("A")].value for i in range(ord("E"), ord("K")) if i != ord(wrong_math_col_index))
            list_temp=list()
            try:
                for i in range(ord("E"), ord("K")):
                    if i==ord(wrong_math_col_index):
                        continue
                    if type(row[i-ord("A")].value) == str:
                        if row[i-ord("A")].value.isdigit():   #字符串全部由数字组成，则返回True
                            row[i - ord("A")].value=int(row[i - ord("A")].value)
                        else:
                            raise Exception("不是整数！")
                    list_temp.append(row[i-ord("A")].value)
                obj_dict[row[ord(name_col_index) - ord("A")].value]=list_temp
            except Exception as e:
                print(e)
                continue


def sort_and_print(subject_ord,num,stu_dict):
    list_temp=list(stu_dict.items())
    list_temp.sort(key=lambda x:x[1][subject_ord],reverse=True)
    if num<len(list_temp):
        list_to_print=list_temp[0:num+1]
    else:
        print("目标人数大于实际人数!")
        list_to_print=list_temp
    for i in range(len(list_to_print)):
        print(" 姓名：{:""^10}\t政治：{:""^6}\t英语：{:""^6}\t数学：{:""^6}\t数据结构：{:""^6}\t总分：{:""^6}".format(list_to_print[i][0],list_to_print[i][1][0],list_to_print[i][1][1],list_to_print[i][1][2],list_to_print[i][1][3],list_to_print[i][1][4]))
# for row in sheet.rows:
#     #更正名字列号错误
#     if row[ord("B")-ord("A")].value==None:
#         name_col_index="C"
#     else:
#         name_col_index="B"
#     #更正数学成绩列号错误
#     if row[ord("G")-ord("A")].value==None:
#         wrong_math_col_index="G"
#     else:
#         wrong_math_col_index="H"
#     major=str(row[0].value).replace("\n","")
#     if major=="计算机科学与技术":
#         xue_stu_grade_dic[row[ord(name_col_index)-ord("A")].value]=tuple(row[i-ord("A")].value for i in range(ord("E"),ord("K")) if i!=ord(wrong_math_col_index))
#         for cell in row:
#             cvtp=str(cell.value).replace("\n","")     #去掉表格中值的换行符号
#             print(cvtp,end=" ")
#         print("")
#     elif major=="电子信息":
collect_stu_name_grade_dict("计算机科学与技术",xue_stu_grade_dic)
collect_stu_name_grade_dict("电子信息",zhuan_stu_grade_dic)
print("电子信息")
sort_and_print(4,50,zhuan_stu_grade_dic)
print("计算机科学与技术")
sort_and_print(4,50,xue_stu_grade_dic)

# for i in zhuan_stu_grade_dic.items():
#     print(i)

#输出某学科前50名学生成绩


