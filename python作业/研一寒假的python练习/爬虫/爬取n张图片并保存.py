import Get_html
import requests
import re
"""
算法
1.先手工得出百度根据某关键字搜索图片网页的那个url
2.根据这个url得出此网页的html（网页源代码）
3.根据html，结合正则表达式得出搜索结果各种图片的多个url
4.使用request库，根据这多个url爬到相关数据，将这些数据分别写入各文件，得到多张图片
"""
def get_pictures(word,n):
    baidu_photo_source_page = "https://image.baidu.com/search/index?tn=baiduimage&ipn=r&ct=201326592&cl=2&lm=-1&st=\
                            -1&fm=result&fr=&sf=1&fmq=1645791851608_R&pv=&ic=0&nc=1&z=&hd=&latest=&copyright=&se=1&showtab=0&fb=\
                            0&width=&height=&face=0&istype=2&dyTabStr=&ie=utf-8&sid=&word="
    url=baidu_photo_source_page+word
    print("前")
    html=Get_html.get_html_request(url)
    print("后")
    pt="\"thumbURL\":.*?\"(.*?)\""
    x_l=re.findall(pt,html)
    print(x_l)
    i=0
    for x in x_l:
        try:
            print(x)
            r=requests.get(x)      #根据已知url爬到相关数据
            f=open("搜到的图片/{}{}.jpeg".format(word,i),"wb")
            f.write(r.content)                 #将爬到的数据写入文件
            f.close()
        except:
            pass
        finally:
            print("搜到一张!")
            i+=1
        if i>=n:
            break
if __name__=="__main__":
    get_pictures("飞机",5)          #爬5张猫的图片