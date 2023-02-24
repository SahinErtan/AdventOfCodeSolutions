#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::ifstream File("input.txt");

    std::string items;
    std::vector<std::string> item_list;

    char matched_char;
    
    int index1 = 0;
    int index2 = 0;
    int priority_sum = 0;
    int item_priority = 0;

    while (std::getline(File, items)) {
        item_list.push_back(items);

        if (item_list.size() == 3) {

            for (int i = 0; i < item_list[0].length(); i++) {
                index1 = item_list[1].find(item_list[0][i]);
                index2 = item_list[2].find(item_list[0][i]);

                if (index1 != std::string::npos && index2 != std::string::npos) {
                    matched_char = item_list[1][index1];

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
            item_list.clear();
        }
    }

    std::cout << priority_sum << std::endl;
    // 2681

    File.close();
}
