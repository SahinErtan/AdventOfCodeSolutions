
with open("input.txt") as f:
    moves = f.readlines()
# Move Points: Rock = 1 Point, Paper = 2 Point, Scissors = 3 Point
guideline = {"Rock": 1, "Paper": 2, "Scissors": 3}
# A Rock, B Paper, C Scissors
# X Rock, Y Paper, Z Scissors
encryption = {"A": "Rock", "X": "Rock",
              "B": "Paper", "Y": "Paper",
              "C": "Scissors", "Z": "Scissors"}
# Result Points: Win = 6 Point, Draw = 3 Point, Lose = 0 Point
result_points = {"Win": 6, "Draw": 3, "Lose": 0} 

total_result_point = 0

for move in moves:
    strategy_guide = move.split(" ")
    strategy_guide[1] = strategy_guide[1][0]

    elf_point = guideline[encryption[strategy_guide[0]]]
    our_point = guideline[encryption[strategy_guide[1]]]

    if(elf_point == our_point):
        total_result_point += our_point + result_points["Draw"]
    elif(( elf_point + our_point ) % 2 == 0):
        if(elf_point < our_point):
            total_result_point += our_point + result_points["Lose"]
        else:
            total_result_point += our_point + result_points["Win"]
    else:
        if(our_point > elf_point):
            total_result_point += our_point + result_points["Win"]
        else:
            total_result_point += our_point + result_points["Lose"]

print(total_result_point)
# 11386