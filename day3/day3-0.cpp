#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int getValue(std::string line)
{
    std::string left = line.substr(0, line.size() / 2);
    std::string right = line.substr(line.size() / 2, line.size() / 2);
    for (int i = 0; i < left.size(); i++)
    {
        for (int j = 0; j < right.size(); j++)
        {
            if (left[i] == right[j])
            {
                if (left[i] >= 'a' && left[i] <= 'z')
                    return (left[i] - 96);
                else
                    return (left[i] - 38);
            }
        }
    }
    return (-1);
}

int main(void)
{
    std::ifstream file("./data");
    std::string line;

    int count;
    while (getline(file, line))
    {
        int i = 'A' - 38;
        std::cout << i << std::endl;
       count += getValue(line);
    }
    std::cout << count << std::endl;
    file.close();
}