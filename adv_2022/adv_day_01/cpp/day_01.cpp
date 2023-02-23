#include <iostream>
#include <fstream>

int main(){
    std::ifstream File("input.txt");
    std::string text;
    
    int biggest_calorie = 0;
    int current_calorie = 0;

    while (std::getline(File, text)) {
        try {
            current_calorie += std::stoi(text);
        }
        catch (std::exception e) {
            if (current_calorie > biggest_calorie) {
                biggest_calorie = current_calorie;
            }
            current_calorie = 0;
        }
    }
    std::cout << biggest_calorie;

    File.close();
}
// 71023