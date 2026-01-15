#Muestra mi versión de la casa de los Simpsons usando Turtle

from turtle import *

def rectangulo(ancho: int, alto: int, posX: int, posY: int, col_fondo: tuple):
    penup()
    goto(posX, posY)
    pendown()
    color(col_fondo)
    begin_fill()
    for i in range(4):
        if i % 2 == 0:
            forward(ancho)
        else:
            forward(alto)
        right(90)
    end_fill()

#Ver la pantalla completa
setup(width = 1.0, height = 1.0)
speed(10)
ht()

colormode(255)
pensize(5)
col_paredes = (254, 171, 145)
col_techo = (101, 67, 33)
col_techo_obscure = (51, 26, 0)
col_ventana = (194, 255, 247)
col_bordillo = (211, 211, 211)
col_puerta = (255,193,204)
#Pared principal

rectangulo(2800, 1000, -1400, 300, col_paredes)

#Base del techo
rectangulo(2800, 80, -1400, 380, col_techo)
rectangulo(2880, 40, -1440, 420, col_techo_obscure)

#Techo
penup()
goto(-1440, 420)
pendown()
color(col_techo)
begin_fill()
left(55)
forward(400)
right(55)
forward(2420)
right(55)
forward(400)
end_fill()

#ventanas atico
left(55)
rectangulo(600, 200, -1200, 300, col_techo)
rectangulo(225, 175, -1150, 295, col_ventana)
rectangulo(225, 175, -875, 295, col_ventana)

rectangulo(600, 200, 600, 300, col_techo)
rectangulo(225, 175, 650, 295, col_ventana)
rectangulo(225, 175, 925, 295, col_ventana)

#Ventnas primer Priso
penup()
goto(-670, -250)
pendown()
color(col_techo)
begin_fill()
left(110)
circle(250, extent=140)
left(110)
forward(470)
end_fill()
rectangulo(470, 300, -1140, -250, col_techo)
rectangulo(430, 240, -1120, -285, col_ventana)
rectangulo(10, 280, -910, -250, col_techo)
rectangulo(10, 280, -1100, -250, col_techo)
rectangulo(10, 280, -720, -250, col_techo)
rectangulo(440, 10, -1130, -445, col_techo)
rectangulo(440, 10, -1130, -365, col_techo)

penup()
goto(1150, -250)
pendown()
color(col_techo)
begin_fill()
left(110)
circle(250, extent=140)
left(110)
forward(470)
end_fill()
rectangulo(470, 300, 680, -250, col_techo)
rectangulo(430, 240, 700, -285, col_ventana)
rectangulo(10, 280, 910, -250, col_techo)
rectangulo(10, 280, 720, -250, col_techo)
rectangulo(10, 280, 1100, -250, col_techo)
rectangulo(440, 10, 690, -445, col_techo)
rectangulo(440, 10, 690, -365, col_techo)

#Puerta
penup()
goto(250, -250)
pendown()
color(col_techo)
begin_fill()
left(110)
circle(250, extent=140)
left(110)
forward(470)
end_fill()

rectangulo(470, 400, -220, -250, col_techo)
rectangulo(470, 50, -220, -650, col_bordillo)
rectangulo(420, 400, -195, -250, col_puerta)

penup()
goto(-170, -450)
pendown()
color(col_techo_obscure)
begin_fill()
circle(15)
end_fill()

penup()
goto(10, -320)
pendown()
color(140,146,172)
begin_fill()
circle(15)
end_fill()

mainloop()