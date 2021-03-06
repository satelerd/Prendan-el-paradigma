"""
Lo siguiente es un juego de Cachipun programado en python 
creado por el grupo "Prendan el Paradigma":
- Daniel Sateler
- Seba Diaz
- Maximiliano Mardones
"""

import random


def get_winner(user_choice, computer_choice):
    # Determines the winner
    if user_choice == computer_choice:
        return "It's a tie!"

    elif user_choice == "rock":
        if computer_choice == "paper":
            return "The computer won!"
        else: # Este else no es necesario pq si no entra al if etra al esle
            return "You won!"

    elif user_choice == "paper":
        if computer_choice == "scissors":
            return "The computer won!"
        else:
            return "You won!"

    elif user_choice == "scissors":
        if computer_choice == "rock":
            return "The computer won!"
        else:
            return "You won!"


def play_again():
    # Asks the user if he wants to play again
    play_again_input = input("Do you want to play again? (y/n): ")
    return play_again_input


def main():
    # The main function that runs the game

    # Starts the game
    print("Welcome to the paper rock scissors game")
    print("The rules are simple:")
    print("1. You will be asked to choose between rock, paper or scissors")
    print("2. The computer will randomly choose between rock, paper or scissors")
    print("3. The winner is the first one to reach 5 points")
    print("4. Good luck!")
    print()
    print("Let's start the game!")
    print()

    user_score = 0
    computer_score = 0
    while True:
        # Asks the user to choose between rock, paper or scissors
        user_choice = input("Please choose rock, paper or scissors: ")

        # if the user enters anything other than rock, paper or scissors, the game will ask again
        if (
            user_choice != "rock"
            and user_choice != "paper"
            and user_choice != "scissors"
        ):
            print(f"{user_choice} is not a valid choice. Please try again.")
            print()
            continue

        # Asks the computer to randomly choose between rock, paper or scissors
        computer_choice = random.choice(["rock", "paper", "scissors"])
        print(f"The computer chose {computer_choice}")

        # Determines the winner
        winner = get_winner(user_choice, computer_choice)
        print(f"The result is: {winner}")
        if winner == "You won!":
            user_score += 1
        elif winner == "The computer won!":
            computer_score += 1

        print()
        print(f"Your score is: {user_score}")
        print(f"The computer's score is: {computer_score}")
        print()

        # Checks if the game is over
        if user_score == 5:
            print("You won the game!")
            print()
            break
        elif computer_score == 5:
            print("The computer won the game!")
            print()
            break


if __name__ == "__main__":
    main()

    # Ask the user if he wants to play again
    new_game = play_again()
    if new_game == "n":
        print("Thank you for playing!")
    elif new_game == "y":
        main()
