
with open("input.txt") as f:
    calories = f.readlines()

top_count = 3 # calculate top how many elf
biggest_calories = [0] * top_count
current_calorie = 0
total_calorie = 0

for calorie in calories:
    try:
        current_calorie += int(calorie)
    except:
        for i in range(top_count):
            if(current_calorie>biggest_calories[i]):
                if(i + 1 <= len(biggest_calories)):
                    temp = biggest_calories[i]
                    biggest_calories[i] = current_calorie
                    current_calorie = temp
                    
        current_calorie = 0

print(biggest_calories)
# [71023, 68034, 67232]
for calorie in biggest_calories:
    total_calorie += calorie   
print(total_calorie)
# 206289