#include <iostream>
#include <fstream>

int main(){
    std::ifstream File("input.txt");
    std::string items;
    std::string first_part_of_items;
    std::string second_part_of_items;

    char matched_char;
    
    int items_count = 0;
    int half_items_index = 0;
    int index = 0;
    int priority_sum = 0;
    int item_priority = 0;

    while (std::getline(File, items)) {
        items_count = items.length();
        half_items_index = items_count / 2;  // assuming all of item counts are even numbers
        first_part_of_items = items.substr(0, half_items_index);
        second_part_of_items = items.substr(half_items_index, items_count - half_items_index);

        for (int i = 0; i< first_part_of_items.length(); i++) {
            int index = second_part_of_items.find(first_part_of_items[i]);

            if (index != std::string::npos) {
                matched_char = second_part_of_items[index];
                
                // ASCII TABLE a = 97 ... z = 122
                if ((int) matched_char >= 97) {
                    item_priority = (int) matched_char - 96;
                }
                // ASCII TABLE A = 65 ... Z = 90
                else if ((int) matched_char >= 65) {
                    item_priority = (int) matched_char - 38;
                }

                priority_sum += item_priority;
                break;
            }
        }
    }

    std::cout << priority_sum << std::endl;
    // 8349

    File.close();
}
