from flask import Flask
from config import Config

app = Flask(__name__)
#Toma las configuraciones de la clase creada Config
app.config.from_object(Config)

#Evitar la importación circular. Cuando dos modulos dependen entre si.
from app import routes
#from app import funciones