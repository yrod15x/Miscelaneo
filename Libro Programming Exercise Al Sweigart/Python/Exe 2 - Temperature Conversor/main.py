"""Aplicación gráfica con la biblioteca Tkinter que permite convertir 
temperaturas de grados Celcius a Farenheit y viceversa."""

from tkinter import *

#Objeto (ventana principal) de la clase tkinter. mainloop la deja abierta
app = Tk()
app.geometry("350x300")
app.title("Y-Rod")
app.resizable(width = False, height = False)

#Encabezado
titulo = Label(app, text = "Convertir Temperatura", height = 1, width = 30,
fg = 'White', font = ('Consolas', 18), bg="#336699")
titulo.place(x = 0, y = 0)

#Etiqueta
temp_label = Label(app, text = "Temperatura", font = ('Consolas', 14, 'bold'),
fg = "#336699")
temp_label.place(x = 10, y = 60)

#Operación de Conversión
temperatura = StringVar()
convertida = 0

#Caja texto temperatura a convertir
temp_caja = Entry(app, width = 18, font = ('Consolas', 14), textvariable = temperatura)
temp_caja.place(x = 150, y = 62)

#Etiqueta grados iniciales a convertir
temp_inicial_label = Label(app, text = "De grados", font = ('Consolas', 14, 'bold'), fg = "#336699")
temp_inicial_label.place(x = 10, y = 110)
grados = [f"Celsius ({chr(186)}C)", f"Farenheit ({chr(186)}F)"]
val_sel_inicial = StringVar(app)
val_sel_inicial.set(grados[0])
de_temp_menu = OptionMenu(app, val_sel_inicial, *grados)
de_temp_menu.config(font = ('Consolas', 13, 'bold'), fg = "#336699", width = 16)
de_temp_menu.place(x = 148, y = 105)

#Etiqueta grados convertidos
temp_final_label = Label(app, text = "A grados", font = ('Consolas', 14, 'bold'), fg = "#336699")
temp_final_label.place(x = 10, y = 160)
val_sel_final = StringVar(app)
val_sel_final.set(grados[1])
a_temp_menu = OptionMenu(app, val_sel_final, *grados)
a_temp_menu.config(font = ('Consolas', 13, 'bold'), fg = "#336699", width = 16)
a_temp_menu.place(x = 148, y = 155)

#Texto donde se muestra la temperatura convertida
temp_convertida = 0
tipo_temp_convertida = f" C{chr(186)}"
temp_convertida_label = Label(app, text = str(convertida) + tipo_temp_convertida, font = ('Consolas', 26, 'bold'), fg = "#336699")
temp_convertida_label.place(x = 180, y = 220)

#Operación de Conversión
def convertir_temp():
    """Convertir temperaturas dependiendo de los menus"""
    convertida = 0
    tipo_temp_convertida = ""
    temp = temperatura.get()
    temp_inicial = val_sel_inicial.get()
    temp_final = val_sel_final.get()
    if temp_inicial == f"Celsius ({chr(186)}C)" and temp_final == f"Farenheit ({chr(186)}F)":
        convertida = round(float(temp) * (9 / 5) + 32, 2)
        tipo_temp_convertida = f" F{chr(186)}"
    elif temp_inicial == f"Farenheit ({chr(186)}F)" and temp_final == f"Celsius ({chr(186)}C)":
        convertida = round((float(temp) - 32) * (5 / 9), 2)
        tipo_temp_convertida = f" C{chr(186)}"    
    temp_convertida_label = Label(app, text = str(convertida) + tipo_temp_convertida, font = ('Consolas', 26, 'bold'), fg = "#336699")
    temp_convertida_label.place(x = 180, y = 220)
    temperatura.set('')
    
#Boton para ejecutar la conversión
btn_convertir = Button(app, font = ('Consolas', 13, 'bold'), text = "Convertir",
command = convertir_temp)
btn_convertir.place(x = 15, y = 230)

app.mainloop()