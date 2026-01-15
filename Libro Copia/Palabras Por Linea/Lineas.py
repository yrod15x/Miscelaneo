class Linea():
    def __init__(self, nom_archivo):
        self.__nom_archivo = nom_archivo
        
    def extraer_lineas(self):
        #Se usa el enconding por que texto no puede estar formateado.
        lin, self.lineas= [], []
        with open(self.__nom_archivo, encoding='utf-8') as file_object:
            self.lin = file_object.readlines()
        for l in self.lin:
            if len(l) > 1:
                self.lineas.append(l)
                
        return self.lineas
    
    def entrada_datos(self):
        #Restringe al usuario a poner un numero entero de 1 al tamanano del texto
        len_lineas = len(self.extraer_lineas())
        while True:
            self.num_linea = input(f"Type a number from 1 to {len_lineas} >> ")
            if self.num_linea.isdecimal():
                self.num_linea = int(self.num_linea)
                if self.num_linea > 0 and self.num_linea < len_lineas:
                    return self.num_linea
                else:
                    print('El numero excede el numero de lineas o es negativo')
            else:
                print('La entrada no es un numero - Intente de nuevo')
    
    def mostar_linea_requerida(self):
        print(f"la linea {self.num_linea} es: \n {self.lineas[self.num_linea - 1]}")
        return None
    
    def obtener_linea_requerida(self):
        return self.lineas[self.num_linea - 1]
         
    def  frecuencia_palabra(self, palabra):
        self.__frecuencia = 0
        for p in self.lineas:
            if palabra.lower() in p or palabra.upper() in p or palabra.capitalize() in p :
                self.__frecuencia += 1
        print(f"La palabra {palabra} aparece {self.__frecuencia} veces en el texto")
        return None
    
    def mostrar_lineas_ascedente(self, texto):
        #Escibe en un archivo las lineas de menor a mayor cantidad que estan en un texto
        lista_lineas = texto.split('\n')
        lista_lineas = sorted(lista_lineas, key=len)
        file_object = open(r"texto.txt",'w', encoding='utf-8')
        for l in lista_lineas:
            file_object.write(l + '\n')
        

                    
        