class OrgLineas:
    """Clase que organiza un texto de menor a mayor linea. Luego ordena las palabras de la
    lista alfabeticamente."""
    
    def __init__(self, texto):
        self.__texto = texto.split('\n')
    
    def info(self):
        print(f"{'*' * 55}")
        print("""Programa que organiza un texto de menor a mayor linea.\nLuego ordena las palabras de la lista alfabeticamente.""")
        print(f"{'*' * 55}")
        print()
    
    def pedir_texto(self):
        self.__texto = input("Ingrese el texto a trabajar >>")
        
    def ordenar_lineas(self):
        #Se hizo el bubbleSort porque sort() no lograba organizarlos
        for i in range(len(self.__texto)):
            for j in range(i, len(self.__texto) - 1):
                if len(self.__texto[j]) > len(self.__texto[j + 1]):
                    temp = self.__texto[j]
                    self.__texto[j] = self.__texto[j+1]
                    self.__texto[j+1] = temp
    
    def ordenar_alfabetica(self):
        #como string no tiene sort() toca convertilo en lista para poder ordenarlo con sorted()
        #tambien se podria ordenar el string con bubble sort()
        self.__texto_alfabetico = []
        for text in self.__texto:
            text = text.split(' ')
            self.__texto_alfabetico.append(' '.join(sorted(text)).lower())
        
    def impimir_texto(self):
       for text in self.__texto_alfabetico:
           print(text.strip()) 
       print()