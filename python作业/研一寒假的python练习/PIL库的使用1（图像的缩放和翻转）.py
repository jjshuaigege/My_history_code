from PIL import Image
img=Image.open("../../sgz.jpg")
w,h=img.size
print("原图片大小为{}乘{}".format(w,h))
print(img.format,img.mode)             #打出图像的类型（jpg，png等）和色彩类型（RGB，黑白等）
newSize = (w//2,h//2)
newImg=img.resize(newSize)
newImg.save("../../sgz(修改1).jpg")
print("1图片大小为{}乘{}".format(newImg.size[0],newImg.size[1]))
newImg.thumbnail((128,128))
newImg.save("../../sgz(修改2).jpg")
print("2图片大小为{}乘{}".format(newImg.size[0],newImg.size[1]))
newImg.show()
newImg1=img.rotate(90,expand=True)      #expand为True表示可以修改图片大小,即从1920*1080到1080*1920
newImg1.save("../../sgz(修改3).jpg")
print("3图片大小为{}乘{}".format(newImg1.size[0],newImg1.size[1]))
newImg2=img.transpose(Image.FLIP_LEFT_RIGHT)     #将图像左右镜像翻转
newImg2=newImg2.filter(ImageFilter.BLUR)
newImg2.save("../../sgz(修改4).jpg")
