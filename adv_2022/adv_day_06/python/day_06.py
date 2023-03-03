
with open("input.txt") as f:
    datastream = f.read()

packet_start_position = 0
character_sequences = []


for data_index, data in enumerate(datastream):
    character_sequences.append(data)
    start_position_flag = True
    if(len(character_sequences) == 4):
        for index in range(3):
            if(character_sequences.count(character_sequences[index]) > 1):
                start_position_flag = False
                character_sequences.pop(0)
                break
        
        if(start_position_flag):
            packet_start_position = data_index
            break

print(packet_start_position + 1)
# 1876