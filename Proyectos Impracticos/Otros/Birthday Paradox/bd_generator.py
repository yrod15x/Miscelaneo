from random import randint, choice
import datetime

def bisiesto(anno):
    if anno % 4 == 0:
        if anno % 100 == 0 and anno % 400 == 0:
            return True
        return True
    else:
        return False

def input_data():
    while True:
        #Pedir cantidad de cumpleanos de 1  a 100
        num_birthdays = int(input('Birthdays to generate (Max 100)> '))
        if 0 < num_birthdays <= 100:
            break
    return num_birthdays

def generate_birthdays(num_birthdays):  
    birthdays = []
    month_31s = [1, 3, 5, 7, 8, 10, 12]
    months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
    days = [str(x) for x in range(32)]
    
    for i in range(num_birthdays):
        ran_month = randint(0, 11)
        if ran_month + 1 in month_31s:
            ran_days = randint(1, 31)
        else:
            if ran_month == 1:
                if bisiesto(int(datetime.datetime.today().year)):
                    ran_days = randint(1, 29)
                else:
                    ran_days = randint(1, 28)
            else:
                ran_days = randint(1, 30)
        bd = months[ran_month] + ' ' + days[ran_days]
        birthdays.append(bd)
    return birthdays

def birthday_to_compare(birthdays):
    num_birthdays = generate_birthdays(birthdays)
    return choice(num_birthdays)


def matchBirthdays(birthdays, bd_to_compare):
    num_birthdays = generate_birthdays(birthdays)
    duplicates = 1
    #print(*birthdays, sep=', ')
    #Mirar si o hay cumpleanos duplicados. Los SET eliminan duplicados. Se compara el tamano
    #de la lista inicial con la misma convertida a set. Si son iguales no hay duplicados
    if len(num_birthdays) == len(set(num_birthdays)):
        return 0
    for bd in num_birthdays:
        duplicates = num_birthdays.count(bd_to_compare)
        
    return duplicates

def print_info(bd_to_compare, duplicates, num_people, num_sims):
    average = round((duplicates * 100 / num_sims), 2)
    text = f"Out of {num_sims} simualtions of {num_people} people, {bd_to_compare} repeats {str(duplicates)} times. There is an {average}% of peple having the same birthday." 
    print(text)
    return None