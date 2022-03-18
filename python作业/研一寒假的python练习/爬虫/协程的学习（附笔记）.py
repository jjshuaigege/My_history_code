import asyncio
import time
import pyppeteer
"""
协程就是前面加了"async"的函数(自python3.6开始有)
async def f():
    return 0
调用协程时，必须在函数名前面加"await"
    await f()
协程只能在协程里面调用，即await语句只能出现在协程里面
协程是一种特殊的函数，多个协程可以并行
"""


async def f1():
    broswer = await pyppeteer.launch(executablePath="D:\\ungoogled-chromium_84.0.4147.135-1.1_windows\\chrome.exe", headless=False)
    page = await broswer.newPage()
    await page.goto("https://search.bilibili.com/all?keyword=chromium&from_source=webtop_search&spm_id_from=333.1007")
if __name__=="__main__":
    m=asyncio.ensure_future(f1())
    asyncio.get_event_loop().run_until_complete(m)
    time.sleep(10)

