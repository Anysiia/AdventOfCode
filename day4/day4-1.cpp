#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
/*
#define A_min = out[0]
#define A_max = out[1]
#define B_min = out[2]
#define B_max = out[3]
*/

void tokenize(std::string const &str, const char* delim, std::vector<int> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(stoi(std::string(token)));
        token = strtok(nullptr, delim);
    }
}

int isOverlap(std::string line)
{
    const char *delimi = ",-";
    std::vector<int> out;
    tokenize(line, delimi, out);
    for (int i = 0; i < out.size(); i++)
        std::cout << out[i] << " - ";
    if ((out[0] <= out[2] && out[2] <= out[1])
        || (out[2] <= out[0] && out[0] <= out[3]))
        return (1);
    return (0);
}

int main(void)
{
    std::ifstream file("./data");
    std::string line;
    int count = 0;

    while (getline(file, line))
    {
        count += isOverlap(line);
        std::cout << count << std::endl;
    }
    std::cout << count << std::endl;
    file.close();
}