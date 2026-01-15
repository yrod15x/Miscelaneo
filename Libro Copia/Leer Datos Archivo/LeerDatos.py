class LeerDatos:
    def __init__(self):
        self.__lineas = []
        self.__valores = []
    
    def leer_archivo(self, nom_archivo):
        with open(nom_archivo) as file_object:
           lineas = file_object.readlines()
        for line in lineas:
            self.__lineas.append(line.rstrip('\n'))
        return None
    
    def devolver_lineas(self):
        return self.__lineas
    
    def mostrar_lineas(self):
        for line in self.__lineas:
            print(line)
            
    def suma_valores(self):
        temp_valores = self.__lineas[1:]
        valores = [val.split(' ') for val in temp_valores]

        try:
            for val in valores:
                self.__valores.append(int(val[-1]))
        except Exception as err:
            print(err)
        else:
            print(f"El total de kilos de todos los productos es {sum(self.__valores)}")
        
            
        