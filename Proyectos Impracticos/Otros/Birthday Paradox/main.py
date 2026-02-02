import bd_generator

num_bds = bd_generator.input_data()
date = bd_generator.birthday_to_compare(num_bds)
duplicates = 0
num_simulations = 100000

for i in range(num_simulations):
    duplicates += bd_generator.matchBirthdays(num_bds, date)

bd_generator.print_info(date, duplicates, num_bds, num_simulations)