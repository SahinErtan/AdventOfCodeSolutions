
continue_permission = False
crate_stacks = []
crate_index_dict = {}
crate_stack_arrangement_dict = {}

with open("input.txt") as f:
    for rearrangement_procedure in f:
        rearrangement_procedure = rearrangement_procedure.replace("\n", "")
        if(continue_permission):
            move = rearrangement_procedure.split(" ")
            move_count = int(move[1])
            move_from = int(move[3])
            move_to = int(move[5])
            count = 0
            while(count < move_count):
                crate_stack_arrangement_dict[move_to].append(crate_stack_arrangement_dict[move_from][-1])
                crate_stack_arrangement_dict[move_from].pop()
                count += 1

        if(rearrangement_procedure == ""):
            for index, stack in enumerate(crate_stacks[-1]):
                if(stack.isdecimal()):
                    crate_index_dict[int(stack)] = index
            
            i = 0    
            for key in crate_index_dict.keys():
                value = crate_index_dict[key]
                stack = []
                while(i < len(crate_stacks)):
                    if(crate_stacks[i][value] != " "):
                        stack.insert(0, crate_stacks[i][value])
                    i += 1
                crate_stack_arrangement_dict[key] = stack
                i = 0

            continue_permission = True

        crate_stacks.append(rearrangement_procedure)


last_top_chars = ""
for value in crate_stack_arrangement_dict.values():
    last_top_chars += value[-1]

print(last_top_chars)
# FZCMJCRHZ
