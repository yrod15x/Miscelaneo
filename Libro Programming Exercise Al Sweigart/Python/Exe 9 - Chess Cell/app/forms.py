"""Clase que maneja el formulario para la aplicación"""

from flask_wtf import FlaskForm
from wtforms import IntegerField, SubmitField
from wtforms.validators import DataRequired, NumberRange

class Form(FlaskForm):
    """Clase que maneja el formulario para la aplicación que tiene dos 
    cajas de texto numérico y un botón"""
    row = IntegerField('Row', validators=[DataRequired(), 
    NumberRange(min=1, max=64)])
    column = IntegerField('Column', validators=[DataRequired(), 
    NumberRange(min=1, max=64)])
    boton = SubmitField('Find Color')  