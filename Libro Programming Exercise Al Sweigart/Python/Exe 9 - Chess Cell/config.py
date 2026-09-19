"""Clase que tiene todas las configuraciones de la aplicación"""

import os

class Config():
    """Configuraciones de seguridad"""
    SECRET_KEY = os.environ.get('SECRET_KEY') or 'hg6tgshg!!@@'


