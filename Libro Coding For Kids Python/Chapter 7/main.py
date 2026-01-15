from random import choice

people: list[str] = ['Baby Oil', 'Bad News', 'Big Burps', "Bill 'Beenie-Weenie'",
"Bob 'Stinkbug'", 'Bowel Noises', 'Boxelder', "Bud 'Lite'",
'Butterbean', 'Buttermilk', 'Buttocks', 'Chad', 'Chesterfield',
'Chewy', 'Chigger', 'Cinnabuns', 'Cleet', 'Cornbread', 'Crab Meat']

jokes: list[str] = ["I'm afraid for the calendar. Its days are numbered.", 
"My wife said I should do lunges to stay in shape. That would be a big step forward.", 
"Why do fathers take an extra pair of socks when they go golfing? In case they get a hole in one!", 
"Singing in the shower is fun until you get soap in your mouth. Then it's a soap opera.", 
"What do a tick and the Eiffel Tower have in common? They're both Paris sites.", 
"What do you call a fish wearing a bowtie? Sofishticated.", 
"How do you follow Will Smith in the snow? You follow the fresh prints.", 
"If April showers bring May flowers, what do May flowers bring? Pilgrims."]

heroes: dict[str:str] = {"Spiderman": "balancearse", 
    "Batman": "atrapar criminales",
    "Superman": "volar", 
    "Guepardo": "sanarse",}

def super_heroes(heroe:str, poder:str)-> str:
    return f"{heroe} tiene el poder de {poder}."

def chiste_aleatorio(personas: list[str], chistes: list[str])->str:
    return f"{choice(personas)} dice {choice(chistes)}"

for key, value in heroes.items():
    print(super_heroes(key, value))

print("*"*80)

print(chiste_aleatorio(people, jokes))

print("*"*80)

#Factorial
def factorial(numero: int)-> int:
    if numero == 1:
        return 1
    else:
        return factorial(numero - 1) * numero

print(factorial(4))

print("*"*80)

#FizzBuzz Cakes
def fizz_buzz(pudines: int):
    for i in range(1, pudines + 1):
        if i % 15 == 0:
            print("Cupcake-Galleta")
        elif i % 3 == 0:
            print("Cupcake")
        elif i % 5 == 0:
            print("Galleta")

fizz_buzz(20)