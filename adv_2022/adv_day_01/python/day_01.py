
with open("input.txt") as f:
    calories = f.readlines()

biggest_calorie = 0
current_calorie = 0

for calorie in calories:
    try:
        current_calorie += int(calorie)
    except:
        if(current_calorie>biggest_calorie):
            biggest_calorie = current_calorie
        current_calorie = 0

print(biggest_calorie)
# 71023