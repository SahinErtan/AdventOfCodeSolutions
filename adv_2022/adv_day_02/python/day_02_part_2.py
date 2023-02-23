
with open("input.txt") as f:
    moves = f.readlines()
# Move Points: Rock = 1 Point, Paper = 2 Point, Scissors = 3 Point
guideline = {"Rock": 1, "Paper": 2, "Scissors": 3}
# A Rock, B Paper, C Scissors
# X Lose, Y Draw, Z Win
encryption = {"A": "Rock", "X": "Lose",
              "B": "Paper", "Y": "Draw",
              "C": "Scissors", "Z": "Win"}
# Result Points: Win = 6 Point, Draw = 3 Point, Lose = 0 Point
result_points = {"Win": 6, "Draw": 3, "Lose": 0} 

total_result_point = 0

for move in moves:
    strategy_guide = move.split(" ")
    strategy_guide[1] = strategy_guide[1][0]

    waiting_result = encryption[strategy_guide[1]]
    
    elf_point = guideline[encryption[strategy_guide[0]]]
    if(waiting_result == "Draw"):
        our_point = elf_point
    elif(waiting_result == "Win"):
        if(elf_point + 1 <= 3):
            our_point = elf_point + 1
        else:
            our_point = 1
    elif(waiting_result == "Lose"):
        if(elf_point - 1 >= 1):
            our_point = elf_point - 1
        else:
            our_point = 3

    our_move = list(guideline.keys())[list(guideline.values()).index(our_point)]
    total_result_point += our_point + result_points[waiting_result]

print(total_result_point)
# 13600