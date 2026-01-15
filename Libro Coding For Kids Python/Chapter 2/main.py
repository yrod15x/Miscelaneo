"""Usar print(), f-strings y para mostrar textos sencillos o multilínea en pantalla"""

animo: str = "relajado"
haiku: str = """
Y-Rod enjoys
Coffee, lots of coding, and
Learning me Python
"""
nombre: str = "Y-Rod"
apellido: str = "Escorcia"
adjetivo: str= "madura"
merienda: str = "fruta"
numero: int = 4
arbol: str = "roble"
historia: str = f"""Hola, me llamo {nombre} {apellido}.
¡Me encanta una {merienda} {adjetivo}!
Intento comerla por lo menos {numero} al dia.
Sabe muy bien, especialmente comerlo debajo de un {arbol}."""

pastel = """  (0)
 (000)
(00000)
"""

print("Me llamo Y-Rod")
print("\"La vida es asi. No pasa nada.\" - Anonimo")
print(f"Hoy me siento {animo}.")
print(f"{haiku}")
print(historia)
print(pastel)