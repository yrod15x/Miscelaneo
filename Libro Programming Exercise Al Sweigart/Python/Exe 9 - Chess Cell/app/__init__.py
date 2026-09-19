from flask import Flask
from config import Config

app = Flask(__name__)
#Decirle a Flask que lea y aplique las configuraciones y lo enlace a la 
#variable encargada app.config
app.config.from_object(Config)  

from app import routes