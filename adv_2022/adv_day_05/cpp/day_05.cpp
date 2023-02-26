#include <iostream>
#include <fstream>
#include <vector>   
#include <bits/stdc++.h>
#include <map>

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

int main(){
    std::ifstream File("input.txt");
    std::string rearrangement_procedure;

    bool continue_permission = false;
    
    std::vector<std::string> crate_stacks;
    std::vector<std::string> move;
    std::map<int, int> crate_index_map;
    std::map<int, std::vector<char>> crate_stack_arrangement_map;

    while (std::getline(File, rearrangement_procedure)) {

        if (continue_permission) {
            move = adv_tokenizer(rearrangement_procedure, ' ');
            int move_count = std::stoi(move[1]);
            int move_from = std::stoi(move[3]);
            int move_to = std::stoi(move[5]);

            int count = 0;
            while (count < move_count) {
                crate_stack_arrangement_map[move_to].push_back(crate_stack_arrangement_map[move_from].back());
                crate_stack_arrangement_map[move_from].pop_back();
                count++;
            }
        }

        if (rearrangement_procedure == "") {
            for (int i = 0; i < crate_stacks.back().length(); i++) {
                if (std::isdigit(crate_stacks.back()[i])) {
                    crate_index_map[(int)crate_stacks.back()[i] - '0'] = i;
                }
            }
            
            crate_stacks.pop_back();

            int i = 0;
            for (std::map<int, int>::iterator it = crate_index_map.begin(); it != crate_index_map.end(); it++) {
                std::vector<char> stack;
                while (i < crate_stacks.size()) {
                    if (crate_stacks[i][it->second] != ' ') {
                        stack.insert(stack.begin(), (crate_stacks[i][it->second]));
                    }
                    i++;
                }
                crate_stack_arrangement_map[it->first] = stack;
                i = 0;
            }
            continue_permission = true;
        }
        
        crate_stacks.push_back(rearrangement_procedure);
    }

    File.close();

    std::string last_top_chars = "";
    for (std::map<int, std::vector<char>>::iterator it = crate_stack_arrangement_map.begin(); it != crate_stack_arrangement_map.end(); it++) {
        last_top_chars += it->second.back();
    }

    std::cout << last_top_chars << std::endl;
    // FZCMJCRHZ
    
}
