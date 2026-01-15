
"""Maneja todas las variables de configuración de la aplicación"""

import os

class Config(object):
    #llave criptográfica para proteger los formularios. Si el sistem no 
    #la brinda le paso una cadena de texto
    SECRET_KEY = os.environ.get('SECRET_KEY') or "hghjHJHk344hhhbbvd"