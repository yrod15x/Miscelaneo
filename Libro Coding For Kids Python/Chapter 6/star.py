from turtle import *

def move(x, y):
    penup()
    goto(x, y)
    pendown()

colormode(255)
ht()
speed(5)

color("orange")
fillcolor("orange")
pensize(5)

angle = 144
steps = 1800

move(-900, 200)
begin_fill()
for i in range(3):
    forward(steps)
    right(angle)
forward(steps)
end_fill()

mainloop()