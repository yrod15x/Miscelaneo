from turtle import *
from random import randint

turtlesize(5)
shape("turtle")
colormode(255)

penup()
goto(-450, 0)
speed(1)
angle = 10
left(90)

for i in range(13):
    color(randint(0, 255), randint(0, 255), randint(0, 255))
    stamp()
    right(angle)
    forward(120)
    angle = 15

goto(-300, 0)
angle = 10
left(185)
for i in range(8):
    color(randint(0, 255), randint(0, 255), randint(0, 255))
    stamp()
    right(angle)
    forward(120)
    angle = 22


mainloop()