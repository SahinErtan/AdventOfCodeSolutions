#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <map>

std::map<std::string, std::vector<std::string>> path_directory_map;
std::map<std::string, int> file_size_map;

std::vector<std::string> adv_tokenizer(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> output_list;
    while (!ss.eof()) {
        std::getline(ss, word, del);
        output_list.push_back(word);
    }
    return output_list;
}

bool is_command(std::string output) {
    if (output == "$") {
        return true;
    }
    else {
        return false;
    }
}

int define_command_type(std::string command) {
    if (command == "cd") {
        return 1;
    }
    else {
        return 0;
    }
}

bool is_exist_on_path_directory(std::string check_str) {
    for (std::map<std::string, std::vector<std::string>>::iterator it = path_directory_map.begin(); it != path_directory_map.end(); it++) {
        if (check_str == it->first) {
            return true;
        }
    }
    return false;
}

bool is_exist_on_file_size(std::string check_str) {
    for (std::map<std::string, int>::iterator it = file_size_map.begin(); it != file_size_map.end(); it++) {
        if (check_str == it->first) {
            return true;
        }
    }
    return false;
}

int calculate_recursive_file_size(std::string directory) {
    std::vector<std::string> file_list = path_directory_map[directory];
    int total_size = 0;
    std::string file_name;
    for (std::string file : file_list) {
        if (file[0] == '/') {
            if(is_exist_on_file_size(file)) {
                file_name = directory + file;
                total_size = total_size + file_size_map[file_name];
            }
            else {
                file_name = directory + file;
                total_size = total_size + calculate_recursive_file_size(file_name);
            }
        }
        else {
            file_name = directory + "/" + file;
            total_size = total_size + file_size_map[file_name];
        }
    }
    file_size_map[file_name] = total_size;
    return total_size;
}

int main(){
    std::ifstream File("input.txt");

    int last_command_mode = 0;
    int file_size;
    std::string terminal_command;
    std::string last_directory;   
    std::string file_name; 
    std::vector<std::string> terminal_outputs;
    std::vector<std::string> directory_list;

    while (std::getline(File, terminal_command)) {
        terminal_outputs = adv_tokenizer(terminal_command, ' ');
        if (is_command(terminal_outputs[0])) {
            if (define_command_type(terminal_outputs[1]) == 1) {
                if (last_command_mode == 2) {
                    path_directory_map[last_directory] = directory_list;
                }
                last_command_mode = 1;
                if (terminal_outputs[2] == "..") {
                    last_directory = last_directory.substr(0,last_directory.rfind("/"));                
                }
                else {
                    last_directory += "/" + terminal_outputs[2];
                }
            }
            else {
                last_command_mode = 2;
                directory_list.clear();
            }
        }
        else {
            file_name = terminal_outputs[1];
            if (terminal_outputs[0] != "dir") {
                file_size = std::stoi(terminal_outputs[0]);
                file_size_map[last_directory + "/" + file_name] = file_size;
            }
            else {
                file_name = "/" + file_name;
            }
            directory_list.push_back(file_name);
        }
    }

    if(last_command_mode == 2) {
        path_directory_map[last_directory] = directory_list;
    }

    File.close();

    std::string path = "//";
    file_size_map[path] = calculate_recursive_file_size(path);

    int total_disk_space = 70000000;
    int unused_disk_space = total_disk_space - file_size_map[path];
    int needed_disk_space = 30000000;
    int delete_needed_space = needed_disk_space - unused_disk_space;

    int last_big_size = 0;
    bool suitable_size_first_flag = true;
    for (std::map<std::string, int>::iterator it = file_size_map.begin(); it != file_size_map.end(); it++) {
        if (is_exist_on_path_directory(it->first)) {
            int size = it->second;
            if ((size >= delete_needed_space)) {    
                if (size < last_big_size || suitable_size_first_flag) {
                    suitable_size_first_flag = false;
                    last_big_size = size;
                }
            }
        }
    }

    std::cout << last_big_size << std::endl;
    // 8474158
}
