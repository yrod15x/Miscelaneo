"""Generar nombres graciosos para superheroes combinando dos tuplas"""
import time
from random import choice
#Se usa para darle color a la fuente en la terminal
from colorama import Fore, Style

primer_nombre = (
             'Crapps', 'Dark Skies', 'Dennis Clawhammer', 'Dicman', 'Elphonso',
             'Fancypants', 'Figgs', 'Foncy', 'Gootsy', 'Greasy Jim', 'Huckleberry',
             'Huggy', 'Ignatious', 'Jimbo', "Joe 'Pottin Soil'", 'Johnny',
             'Lemongrass', 'Lil Debil', 'Longbranch', '"Lunch Money"', 'Mergatroid',
             '"Mr Peabody"', 'Oil-Can', 'Oinks', 'Old Scratch', 'Ovaltine',
             'Pennywhistle', 'Pitchfork Ben', 'Potato Bug', 'Pushmeet',
             'Rock Candy', 'Schlomo', 'Scratchensniff', 'Scut',
             "Sid 'The Squirts'", 'Skidmark', 'Slaps', 'Snakes', 'Snoobs',
             'Snorki', 'Soupcan Sam', 'Spitzitout', 'Squids', 'Stinky',
             'Storyboard', 'Sweet Tea', 'TeeTee', 'Wheezy Joe',
             "Winston 'Jazz Hands'", 'Worms')

segundo_nombre = last = ('Appleyard', 'Bigmeat', 'Bloominshine', 'Boogerbottom',
            'Breedslovetrout', 'Butterbaugh', 'Clovenhoof', 'Clutterbuck',
            'Cocktoasten', 'Endicott', 'Fewhairs', 'Gooberdapple', 'Goodensmith',
            'Goodpasture', 'Guster', 'Henderson', 'Hooperbag', 'Hoosenater',
            'Hootkins', 'Jefferson', 'Jenkins', 'Jingley-Schmidt', 'Johnson',
            'Kingfish', 'Listenbee', "M'Bembo", 'McFadden', 'Moonshine', 'Nettles',
            'Noseworthy', 'Olivetti', 'Outerbridge', 'Overpeck', 'Overturf',
            'Oxhandler', 'Pealike', 'Pennywhistle', 'Peterson', 'Pieplow',
            'Pinkerton', 'Porkins', 'Putney', 'Quakenbush', 'Rainwater',
            'Rosenthal', 'Rubbins', 'Sackrider', 'Snuggleshine', 'Splern',
            'Stevens', 'Stroganoff', 'Sugar-Gold', 'Swackhamer', 'Tippins',
            'Turnipseed', 'Vinaigrette', 'Walkingstick', 'Wallbanger', 'Weewax',
            'Weiners', 'Whipkey', 'Wigglesworth', 'Wimplesnatch', 'Winterkorn',
            'Woolysocks')

print()
print(Fore.LIGHTCYAN_EX + 'Bienvenido a su Seleccionador para su Apodo de SuperHeroe\n')
print(' ....................... Cargando ......................')
print()
time.sleep(2)

while True:
    primer_apodo = choice(primer_nombre).upper()
    segundo_apodo = choice(segundo_nombre).upper()
    print(Fore.GREEN +
          f'Su Apodo de SuperHeroe es: {primer_apodo} {segundo_apodo}')
    print()
    terminar = input(Fore.LIGHTRED_EX+
        'Si esta feliz con su nombre, presione la tecla (s) - Otra tecla para eligir otro: ')
    if terminar.lower() == 's':
        print()
        break
print(Style.RESET_ALL)
