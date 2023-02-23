#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main(int argc, char **argv){
    std::ifstream File("input.txt");
    std::string moves;

    // Move Points: Rock = 1 Point, Paper = 2 Point, Scissors = 3 Point
    std::map<std::string, int> guideline{{"Rock", 1}, {"Paper", 2}, {"Scissors", 3}};
    // Result Points: Win = 6 Point, Draw = 3 Point, Lose = 0 Point
    std::map<std::string, int> result_points{{"Win", 6}, {"Draw", 3}, {"Lose", 0}};
    // A Rock, B Paper, C Scissors
    // X Rock, Y Paper, Z Scissors
    std::map<std::string, std::string> encryption{{"A", "Rock"}, {"X", "Rock"},
                                                  {"B", "Paper"}, {"Y", "Paper"},
                                                  {"C", "Scissors"}, {"Z", "Scissors"}};
    int elf_point = 0;
    int our_point = 0;
    int total_result_point = 0;

    while (std::getline(File, moves)) {
        std::string move[2];
        int i = 0;
        std::stringstream ssin(moves);
        while (ssin.good() && i < 2){
            ssin >> move[i];
            ++i;
        }

        elf_point = guideline[encryption[move[0]]];
        our_point = guideline[encryption[move[1]]];

        if (elf_point == our_point) {
            total_result_point += our_point + result_points["Draw"];
        }
        else if (( elf_point + our_point ) % 2 == 0) {
            if (elf_point < our_point) {
                total_result_point += our_point + result_points["Lose"];
            }
            else {
                total_result_point += our_point + result_points["Win"];
            }
        }
        else {
            if(our_point > elf_point) {
                total_result_point += our_point + result_points["Win"];
            }
            else {
                total_result_point += our_point + result_points["Lose"];
            }
        }

    }

    std::cout << total_result_point << std::endl;
    // 11386
    File.close();
}
