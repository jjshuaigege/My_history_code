#此文件的名字在python中实际上就是"my_library_1"
__all__=["intro","my_py_1"]   #用于from ... import*
import my_library_1.intro
import my_library_1.my_py_1 #用于import library时，让library下的所有py文件也都变为可用
print("打开了my_pc_1！")      #说明import my_library_1时，自动执行此py文件