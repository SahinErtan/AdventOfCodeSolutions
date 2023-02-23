#include <iostream>
#include <fstream>

int main(){
    std::ifstream File("input.txt");
    std::string text;
    
    int top_count = 3;  // calculate top how many elf
    int biggest_calories[top_count];;
    int current_calorie = 0;
    int temp = 0;
    int total_calorie = 0;

    std::fill_n(biggest_calories, top_count, 0);
    int biggest_calories_len = sizeof(biggest_calories) / sizeof(biggest_calories[0]); // or use top_count (biggest_count_len = top_count)
    
    while (std::getline(File, text)) {
        try {
            current_calorie += std::stoi(text);
        }
        catch (std::exception e) {
            for (int i = 0; i < top_count; i++) {
                if (current_calorie > biggest_calories[i]) {
                    if (i+1 <= biggest_calories_len) {
                        temp = biggest_calories[i];
                        biggest_calories[i] = current_calorie;
                        current_calorie = temp;
                    }
                }
            }
            current_calorie = 0;
        }
    }
    for (int i = 0; i < biggest_calories_len; i++) {
        std::cout << biggest_calories[i] << std::endl;
        // 71023
        // 68034
        // 67232
        total_calorie += biggest_calories[i];
    }

    std::cout << "Total Calorie = " << total_calorie << std::endl;
    // Total Calorie = 206289


    File.close();
}