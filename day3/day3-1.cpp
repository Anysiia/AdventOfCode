#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int getValue(std::string first, std::string second, std::string third)
{
    std::string identical;
    for (int i = 0; i < first.size(); i++)
    {
        for (int j = 0; j < second.size(); j++)
            if (first[i] == second[j])
                identical += first[i];
    }
    for (int i = 0; i < identical.size(); i++)
    {
        for (int k = 0; k < third.size(); k++)
        {
            std::cout << identical[i] << std::endl;
            if (identical[i] == third[k])
            {
                if (identical[i] >= 'a' && identical[i] <= 'z')
                    return (identical[i] - 96);
                else
                    return (identical[i] - 38);
            }
        }
    }
    return (-1);
}

int main(void)
{
    std::ifstream file("./data");
    std::string first, second, third;
    int count = 0;

    while (getline(file, first))
    {
        getline(file, second);
        getline(file, third);
        count += getValue(first, second, third);
    }
    std::cout << count << std::endl;
    file.close();
}