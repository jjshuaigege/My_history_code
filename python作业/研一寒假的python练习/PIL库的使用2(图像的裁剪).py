from PIL import Image
image=Image.open("../../sgz.jpg")
w,h=image.size[0]//3,image.size[1]//3
gap=90
newImage=Image.new("RGB",(w*3+gap*2,h*3+gap*2),"white")    #RGB彩色图，底色为白色
for i in range(3):
    for j in range(3):
        clipImage=image.crop((i*w,j*h,(i+1)*w,(j+1)*h))
        clipImage.save("../../裁剪图片用/sgz%d%d.jpg"%(i,j))
        newImage.paste(clipImage,(i*(w+gap),j*(h+gap)))
newImage.save("../../裁剪图片用/sgz裁剪拼装后.jpg")