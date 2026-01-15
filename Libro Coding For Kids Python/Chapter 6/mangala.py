from turtle import *
from random import randint

speed(5)
colormode(255)
pensize(7)

suiche: int = randint(0, 1)

for i in range(40):
    if suiche == 0:
        color(randint(0, 255), randint(0, 255), randint(0, 255))
    circle(260)
    left(10)

mainloop()