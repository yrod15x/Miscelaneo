from turtle import *
from random import randint

def show(x, y, text, fontSize):
    pen.goto(x, y)
    pen.down()
    pen.write(text, font=('Verdana', fontSize))
    pen.up()

speed(1)
pointer = Turtle()
pointer.turtlesize(3, 5, 8)

pen = Turtle()
spin_amount = randint(1, 360)

pen.up()

#right side
show(400, 0, "Yes!", 30)

#left side
show(-600, 0, "Not!", 30)

#top side
show(-150, 380, "Maybe", 30)

#bottom side
show(-180, -380, "After 50", 30)

pen.ht()
pointer.left(spin_amount)

mainloop()