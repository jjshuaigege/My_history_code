from PIL import Image
def makesketch(image,threhold):
    temp_img=image.convert("L")     #转为灰度图
    img_martix=temp_img.load()      #获取像素矩阵
    w,h=image.size[0],image.size[1]
    for i in range(w-1):
        for j in range(h-1):
            if abs(img_martix[i,j]-img_martix[i+1,j+1])>threhold:
                img_martix[i,j]=255
            else:
                img_martix[i,j]=0
    return temp_img
img=Image.open("../../sgz.jpg")
img=makesketch(img,15)
img.show()
img.save("../../图像素描/sgz（素描）.jpg")
