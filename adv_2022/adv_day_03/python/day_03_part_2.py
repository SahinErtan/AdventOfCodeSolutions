import string

alphabet_lowercase = list(string.ascii_lowercase)
alphabet_uppercase = list(string.ascii_uppercase)

priority_sum = 0
item_priority = 0

item_list = []

with open("input.txt") as f:
    for items in f:
        items.replace("\n","")
        
        item_list.append(items)
        
        if(len(item_list) == 3):
            for char in item_list[0]:
                index1 = item_list[1].find(char)
                index2 = item_list[2].find(char)

                if(index1 != -1 and index2 != -1):
                    matched_char = item_list[1][index1]

                    if ( matched_char.islower() ):
                        item_priority = alphabet_lowercase.index(matched_char) + 1
                    elif ( matched_char.isupper() ):
                        item_priority = 26 + alphabet_uppercase.index(matched_char) + 1
                
                    priority_sum += item_priority
                    break

            item_list.clear()

print(priority_sum)
# 2681