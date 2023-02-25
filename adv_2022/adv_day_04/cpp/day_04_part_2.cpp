#include <iostream>
#include <fstream>
#include <vector>   
#include <bits/stdc++.h>

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
    std::string section_pairs;

    std::vector<std::string> section_list;
    std::vector<std::string> section1_part_list;
    std::vector<std::string> section2_part_list;

    int comma_index = -1;
    int section11 = 0;
    int section12 = 0;
    int section21 = 0;
    int section22 = 0;
    int overlaped_section_count = 0;

    while (std::getline(File, section_pairs)) {
        section_list = adv_tokenizer(section_pairs, ',');
        section1_part_list = adv_tokenizer(section_list[0], '-'); 
        section2_part_list = adv_tokenizer(section_list[1], '-');

        section11 = std::stoi(section1_part_list[0]);
        section12 = std::stoi(section1_part_list[1]);
        section21 = std::stoi(section2_part_list[0]);
        section22 = std::stoi(section2_part_list[1]);


        if ((section11 >= section21) && (section11 <= section22)) {
            overlaped_section_count += 1;
        }
        else if ((section12 >= section21) && (section12 <= section22)) {
            overlaped_section_count += 1;
        }
        else if ((section21 >= section11) && (section21 <= section12)) {
            overlaped_section_count += 1;
        }
        else if ((section22 >= section11) && (section22 <= section12)) {
            overlaped_section_count += 1;
        }
    }

    std::cout << overlaped_section_count << std::endl;
    // 861

    File.close();
}
