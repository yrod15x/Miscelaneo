"""Write a program for creating a
substitution cipher problem. In a substitution cipher problem, all messages
are made of uppercase letters and punctuation. The original message is called
the plaintext, and you create the ciphertext by substituting each letter with
another letter (for example, each C could become an X). For this problem,
hard-code a const array of 26 char elements for the cipher, and have your
program read a plaintext message and output the equivalent ciphertext.
Convert the ciphertext back to the plaintext to verify the encoding and 
decoding."""

from random import randint

def text_input()-> str:
	"""Ask the user for a text"""
	return input("Type the text to encrypt >> ").upper()
	
def generate_key()->list[str]:
	"""Geneates and return a list with am scrambled alphabet"""
	key = []
	used = []
	cont = 0
	random_num: int = 0
	while cont <= 25:
		random_num: int = randint(65, 90)
		#Asegurarse que las letras del alfabeto no esten en el mismo orde
		while(random_num == cont + 65):
			random_num: int = randint(65, 90)
		character = (chr(random_num))
		if character not in used:
			key.append(character)
			used.append(character)
			cont += 1	
	return key
	
def generate_encrypted(text, key)->str:
	"""Return an encrypted text using an scrambled alphabet(key)"""
	encrypted = ""
	for char in text:
		if ord(char) >= 65 and ord(char) <= 90:
			encrypted += key[ord(char) - 65]
		else:
			encrypted += char
	return encrypted

def generate_reg_alphabet()-> str:
	"""Returns the English alphabet"""
	return [chr(i) for i in range(65, 91)]

def generate_decrypted(text: str, key: list[str])-> str:
	"""Returns an original text decrypted from a cyphered message"""
	decrypted: str = ''
	reg_alphabet: list[str] = generate_reg_alphabet()
	for index, char in enumerate(text):
		if char not in reg_alphabet:
			decrypted += char
		else:
			decrypted += reg_alphabet[''.join(key).find(char)]
	return decrypted

text = text_input()
key = generate_key()
encrypted = generate_encrypted(text, key)

print(encrypted)
print(generate_decrypted(encrypted, key))
