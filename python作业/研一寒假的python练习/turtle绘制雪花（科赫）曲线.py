import turtle
def draw_kehe(size,n):
    if n==0:
        turtle.forward(size)
    else:
        angle=[0,60,-120,60]
        for i in angle:
            turtle.left(i)
            draw_kehe(size/3,n-1)
if __name__=="__main__":
    s1,s2=input("请输入科赫曲线的阶数n(建议小于6)和边长大小a（建议在100到500）").split()
    n,size=int(s1),int(s2)
    turtle.setup(800,600)
    turtle.penup()
    turtle.color("RED")
    s_x,s_y=-(size/2),3**0.5/6*size
    turtle.goto(s_x,s_y)
    turtle.pensize(3)
    turtle.speed(10)
    turtle.seth(0)
    turtle.pendown()
    angle=[0,120,120]
    for i in angle:
        turtle.right(i)
        draw_kehe(size,n)
    turtle.hideturtle()
    turtle.done()
