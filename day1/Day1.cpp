#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int main(void)
{
    std::ifstream file("./data");
    std::string line;
    std::vector<int> calByElves;

    int countElf = 0;
    while (getline(file, line))
    {
        if (line.size() == 0)
        {
            calByElves.push_back(countElf);
            countElf = 0;
        }
        else
            countElf += stoi(line);
    }
    if (countElf != 0)
        calByElves.push_back(countElf);
    sort(calByElves.begin(), calByElves.end(), std::greater<int>());

    int total = calByElves[0] + calByElves[1] + calByElves[2];
    std::cout << total << std::endl;
    file.close();
}