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
    std::map<std::string, std::string> encryption{{"A", "Rock"}, {"X", "Lose"},
                                                  {"B", "Paper"}, {"Y", "Draw"},
                                                  {"C", "Scissors"}, {"Z", "Win"}};
    int elf_point = 0;
    int our_point = 0;
    int total_result_point = 0;

    std::string waiting_result;
    std::string our_move;

    while (std::getline(File, moves)) {
        std::string move[2];
        int i = 0;
        std::stringstream ssin(moves);
        while (ssin.good() && i < 2){
            ssin >> move[i];
            ++i;
        }

        elf_point = guideline[encryption[move[0]]];
        waiting_result = encryption[move[1]];

        if (waiting_result == "Draw"){
            our_point = elf_point;
        }
        else if (waiting_result == "Win") {
            if (elf_point + 1 <= 3) {
                our_point = elf_point + 1;
            }
            else {
                our_point = 1;
            }
        }
        else if (waiting_result == "Lose") {
            if (elf_point - 1 >= 1) {
                our_point = elf_point - 1;
            }
            else {
                our_point = 3;
            }
        }

        for (auto it: guideline) {
            if(our_point == it.second) {
                our_move = it.first;
                break;
            }
        }
        total_result_point += our_point + result_points[waiting_result];

    }

    std::cout << total_result_point << std::endl;
    // 11386
    File.close();
}
