import os
import sys
cmd_list=sys.argv
for i in cmd_list:
    print(i)
print("当前工作目录为{:s}".format(os.getcwd()))