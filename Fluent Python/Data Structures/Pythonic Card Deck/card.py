"""Programa que crea un mazo de cartas usando OOP y métodos especiales como
__getitem__ y __len__. Además de modulo collections con su contenedor
 namedtuple (Es un contendor para crear un objeto sólo con propiedades y 
 no métodos)."""

import collections

Card = collections.namedtuple('Card', ['rank', 'suit'])  

class FrenchDeck:
    """Recrea un mazo de cartas francés"""
    ranks: list[str] = [str(i) for i in range(2, 11)] + list('JQKA')
    suits: list[str] = "spades diamonds clubs hearts".split()
    def __init__(self):
        self.__cards = [Card(rank, suit) for suit in self.suits
                                        for rank in self.ranks]
    def __len__(self):
        return len(self.__cards)
    def __getitem__(self, position: int):
        """Sobrecarga el operador []"""
        return self.__cards[position]    
