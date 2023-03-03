#include <iostream>
#include <fstream>
#include <vector>   

int main(){
    std::ifstream File("input.txt");
    
    char data;
    int packet_start_position = 0;
    std::vector<char> character_sequences;
    
    while (File.good()) {
        File.get(data);
        character_sequences.push_back(data);
        packet_start_position++;
        bool start_position_flag = true;
        if (character_sequences.size() == 4) {
            for (int i = 0; i < 3; i++) {
                for (int j = i+1; j < 4; j++) {
                    if(character_sequences[i] == character_sequences[j]) {
                        start_position_flag = false;
                        character_sequences.erase(character_sequences.begin());
                        i = 4;
                        break;
                    }
                }
            }
            if (start_position_flag) {
                break;
            }
        }
    }

    File.close();
    std::cout << std::to_string(packet_start_position) << std::endl;
    // 1876
}
