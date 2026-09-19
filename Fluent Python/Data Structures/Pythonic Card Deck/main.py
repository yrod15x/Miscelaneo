"""Programa que crea un mazo de cartas usando OOP y métodos especiales como
__getitem__ y __len__. La clase FrenchDeck construida ofrece todas las
posibilidades (slicing, sort , ...) de una lista debido a la sobrecarga de 
[] por parte de __get__item."""

from card import Card, FrenchDeck

my_card: Card = Card('7', 'Spade')
mazo: FrenchDeck = FrenchDeck()
#Uso del método __getitem__, sobrecarga de []  
print(mazo[0])
#uso de __len__
print(len(mazo))
