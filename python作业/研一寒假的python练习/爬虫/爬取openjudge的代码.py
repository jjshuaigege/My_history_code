import asyncio
import pyppeteer as pyp
#增加反反爬手段
async def antiAntiCrawler(page):
    await page.setUserAgent("Mozilla/5.0 (Windows NT 6.1;\
                            Win64;x64) AppleWebKit/537.36 (KHTML, like Gecko)\
                            Chrome/78.0.3904.70 Safari/537.36")
    await page.evaluateOnNewDocument(
        "() =>{ Object.defineProperties(navigator,\
        { webdriver:{get: () => false} }) }")
#获得根据登陆页面的网址，最终得出n段源代码
async def get_oj_source_code(n,login_url,account,password):
    width,height=1400,800
    browser=await pyp.launch(headless=False,
    executablePath="D:/ungoogled-chromium_84.0.4147.135-1.1_windows/chrome.exe",
                       args=[f'--window-size={width},{height}'],
                       userdataDir="c:/tmp")

    #浏览器打开一个新的空白页面
    page=await browser.newPage()
    await antiAntiCrawler(page)
    #设置页面大小
    await page.setViewport({"width":width,"height":height})
    #页面转到登录页面
    await page.goto(login_url)
    #模拟人输入账户密码
    element=await page.querySelector("#email")
    await element.type(account)
    element=await page.querySelector("#password")
    await element.type(password)
    element=await page.querySelector("#main > form > div.user-login > p:nth-child(2) > button")
    await element.click()
    await page.waitForSelector("#main > h2 > span:nth-child(2) > a")    #等待正在进行的比赛（查看全部） 这一行出现后，再进行操作
    element=await page.querySelector("#userMenu > li:nth-child(2) > a")
    await element.click()
    #等待页面加载完成
    await page.waitForNavigation()
    elements=await page.querySelectorAll(".result-right")
    page2=await browser.newPage()
    await antiAntiCrawler(page)
    await page.setViewport({"width": width, "height": height})
    for element in elements[:n]:
        obj=await element.getProperty("href")
        url=await obj.jsonValue()
        await page2.goto(url)
        element=await page2.querySelector("pre")
        obj=await element.getProperty("innerText")
        text=await obj.jsonValue()
        print("-"*30)
        print(text)
    await browser.close()
if __name__=="__main__":
    m=asyncio.ensure_future(get_oj_source_code(20,"http://openjudge.cn/auth/login/","1020486065@qq.com","2010XXy"))
    asyncio.get_event_loop().run_until_complete(m)






