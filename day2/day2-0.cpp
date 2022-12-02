#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

int main(void)
{
    std::ifstream file("./data");
    std::string line;
    std::vector<int> rounds;

    int roundMark;
    int myPick, opponentPick = -1;
    while (getline(file, line))
    {
        if (line.size() == 3)
        {
            if (line[2] == 'X')
            {
                roundMark = 1;
                if (line[0] == 'A')
                    roundMark += 3;
                else if (line[0] == 'C')
                    roundMark += 6;
            }
            if (line[2] == 'Y')
            {
                roundMark = 2;
                if (line[0] == 'A')
                    roundMark += 6;
                else if (line[0] == 'B')
                    roundMark += 3;
            }
            if (line[2] == 'Z')
            {
                roundMark = 3;
                if (line[0] == 'B')
                    roundMark += 6;
                else if (line[0] == 'C')
                    roundMark += 3;
            }
        }
        std::cout << roundMark << std::endl;
        rounds.push_back(roundMark);
    }
    int totalMark = std::accumulate(rounds.begin(), rounds.end(), 0);
    std::cout << totalMark << std::endl;
    file.close();
}