import turtle
from random import randint

stamp = turtle.Turtle()
stamp.shape('turtle')
stamp.turtlesize(3)

stamp.penup()
turtle.colormode(255)
paces: int = 10

for i in range(50):
    stamp.color(randint(0, 255), randint(0, 255), randint(0, 255))
    stamp.stamp()
    paces += 10
    stamp.forward(paces)
    stamp.right(45)

turtle.mainloop()