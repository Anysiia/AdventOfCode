#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include <tuple>

std::deque<char> * getStacks(std::string filename) {
    std::ifstream inputFile;
    inputFile.open(filename);
    std::deque<char>* stacks = new std::deque<char> [9];
    if (inputFile.is_open()) {
        std::string line;
        for (int x = 0; x < 8; x++) {
            std::getline(inputFile, line);
            int stacknum = 0;
            for (int y = 2; y < line.size(); y += 4) {
                char ch = line[y-1];
                if (ch != 32)
                    stacks[stacknum].push_back(ch);
                stacknum++;
            }
        }
        std::getline(inputFile, line);
    }
    return stacks;
}

std::vector<std::tuple<int, int, int>> getMoves(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    std::vector<std::tuple<int, int, int>> moves;
    if (file.is_open()) {
        std::string line;
        for (int x = 0; x < 10; x++)
            std::getline(file, line);
        int num, to, from = 0;
        while (file >> line >> num >> line >> from >> line >> to) {
            std::tuple<int, int, int> move(num, to, from);
            moves.push_back(move);
        }
    }
    return (moves);
}

void doMoves(std::deque<char> *stacks, std::vector<std::tuple<int, int, int>> moves) {
    for (int i = 0; i < moves.size(); i++) {
        int num = std::get<0>(moves[i]);
        int to = std::get<1>(moves[i]);
        int from = std::get<2>(moves[i]);
        for (int j = 0; j < num; j++) {
            char ch = stacks[from - 1].front();
            stacks[from - 1].pop_front();
            stacks[to - 1].push_front(ch);
        }
    }
}

int main(void)
{
    std::deque<char> *stacks = getStacks("./data");
    std::vector <std::tuple<int, int, int>> moves = getMoves("./data");

    doMoves(stacks, moves);
    for (int i = 0; i < 9; i++) {
        std::cout << stacks[i].front();
    }
    std::cout << std::endl;
}