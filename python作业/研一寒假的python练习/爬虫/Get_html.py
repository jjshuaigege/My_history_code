def get_html_selenium(url):
    from selenium import webdriver
    from selenium.webdriver.chrome.options import Options
    options=Options()            #获得浏览器选项

    options.add_argument("--headless")      #启动chrome浏览器的隐身模式
    options.add_argument("--disable-gpu")   #禁止chrome使用gpu加速（能快点）
    driver=webdriver.Chrome(options=options)
    driver.get(url)                         #浏览器装入网页
    html=driver.page_source                 #获取网页源代码(html)
    driver.close()
    driver.quit()
    return html
def get_html_request(url):
    import sys,requests
    import chardet
    fakeHeaders={"User-Agent":
                 "Mozilla/5.0 (Windows NT 10.0;Win64;x64)\
                  AppleWebKit/537.36 (KHTML, like Gecko)\
                  Chrome/81.0.4044.138 Safari/537.36 Edg/81.0.416.77",
                 'Accept':'text/html,application/xhtml+xml,*/*'}
    #伪装浏览器发送请求,防止反爬虫手段
    try:
        r=requests.get(url,headers=fakeHeaders)
        ecd=chardet.detect(r.content)['encoding']
        if ecd.lower()!=sys.getdefaultencoding().lower():
            print("jin1")
            r.encoding=ecd
        else:
            print("jin2")
            r.encoding=r.apparent_encoding
        return r.text
    except Exception as e:
        print(e)
        return ""
