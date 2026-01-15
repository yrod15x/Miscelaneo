"""Clase que maneja los formularios de la aplicación mediante el uso de los 
objetos de la clase flask_wtf"""

from flask_wtf import FlaskForm
from wtforms import IntegerField, SubmitField
from wtforms.validators import DataRequired, NumberRange

class NumeroForm(FlaskForm):
    numeroX = IntegerField("NumeroX", validators=[DataRequired(), 
    NumberRange(0, 50)])
    enviar = SubmitField('Revisar', render_kw={"class" : "boton"})