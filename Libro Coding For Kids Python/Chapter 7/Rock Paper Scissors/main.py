"""Simulación del juego Piedra, Papel, Tijeras"""

from random import randint

def check_winner(player1, player2):
    """Check which player wins the round after shooting."""
    player1_turn: str = player1.shoot()
    player2_turn: str = player2.shoot()
    print(f"{player1_turn} vs {player2_turn}")
    if (player1_turn == "Rock" and player2_turn == "Scissors") \
        or (player1_turn == "Paper" and player2_turn == "Rock") \
        or (player1_turn == "Scissors" and player2_turn == "Paper"):
        player1.setScore(2)
    elif player1_turn == player2_turn:
        player1.setScore(1)
        player2.setScore(1)
    else:
        player2.setScore(2)

from playerRPS import playerRPS

player1: playerRPS = playerRPS()
player2: playerRPS = playerRPS()
amount_turns: int = randint(1, 10)

for i in range(amount_turns):
    check_winner(player1, player2)

print(f"After {amount_turns} turns. The score is {player1.getScore()} vs {player2.getScore()}.")
if player1.getScore() > player2.getScore():
    print("The winner is Player 1")
elif player1.getScore() < player2.getScore():
    print("The winner is Player 2")
else:
    print("It is a tie.")
