
def is_command(output):
    if (output == "$"):
        return True
    else:
        return False

def define_command_type(command):
    if(command == "cd"):
        return 1
    elif(command == "ls"):
        return 0

path_directory_dict = {}
file_size_dict = {}
directory_list = []
last_command_mode = 0 # 0 = not have last command, 1 = cd command, 2 = ls command
last_directory = ""

with open("input.txt") as f:
    for terminal_command in f:
        terminal_command = terminal_command.replace("\n", "")
        terminal_outputs = terminal_command.split(" ")
        if(is_command(terminal_outputs[0])):
            if(define_command_type(terminal_outputs[1]) == 1):
                if(last_command_mode == 2):
                    path_directory_dict[last_directory] = directory_list
                last_command_mode = 1
                if(terminal_outputs[2] == ".."):
                    last_directory = last_directory[0:last_directory.rfind("/")]
                else:
                    last_directory += "/" + terminal_outputs[2]
            else:
                last_command_mode = 2
                directory_list = []
        else:
            file_name = terminal_outputs[1]
            if(terminal_outputs[0] != "dir"):
                file_size = int(terminal_outputs[0])
                file_size_dict[last_directory + "/" + file_name] = file_size
            else:
                file_name = "/" + file_name
            directory_list.append(file_name)

    if(last_command_mode == 2):
        path_directory_dict[last_directory] = directory_list


# find all of the directories with a total size of at most 100000

def calculate_recursive_file_size(directory):
    file_list = path_directory_dict[directory]
    total_size = 0
    for file in file_list:
        if(file[0] == "/"):
            if(file in file_size_dict):
                file_name = directory + file
                total_size += file_size_dict[file_name]
            else:
                file_name = directory + file
                total_size += calculate_recursive_file_size(file_name)
        else:
            file_name = directory + "/" + file
            total_size += file_size_dict[file_name]
    
    file_size_dict[file_name] = total_size
    return total_size
    

path = "//"
file_size_dict[path] = calculate_recursive_file_size(path)

total_disk_space = 70000000
unused_disk_space = total_disk_space - file_size_dict[path]
needed_disk_space = 30000000
delete_needed_space = needed_disk_space - unused_disk_space

last_big_size = 0
suitable_size_first_flag = True

for file_name, file_size in file_size_dict.items():
    if(file_name in path_directory_dict):
        if(file_size >= delete_needed_space):
            if((file_size < last_big_size) or suitable_size_first_flag):
                suitable_size_first_flag = False
                last_big_size = file_size

print(last_big_size)
# 8474158