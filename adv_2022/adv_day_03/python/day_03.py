import string

alphabet_lowercase = list(string.ascii_lowercase)
alphabet_uppercase = list(string.ascii_uppercase)

priority_sum = 0
item_priority = 0

with open("input.txt") as f:
    for items in f:
        items.replace("\n","")
        
        item_counts = len(items)
        half_items_index = int(item_counts / 2) # assuming all of item counts are even numbers

        first_part_of_items = items[0:half_items_index]
        second_part_of_items = items[half_items_index:item_counts]

        for char in first_part_of_items:
            index = second_part_of_items.find(char)
            
            if ( index != -1 ):
                matched_char = second_part_of_items[index]
                
                if ( matched_char.islower() ):
                    item_priority = alphabet_lowercase.index(matched_char) + 1
                elif ( matched_char.isupper() ):
                    item_priority = 26 + alphabet_uppercase.index(matched_char) + 1
                
                priority_sum += item_priority
                break


print(priority_sum)
# 8349