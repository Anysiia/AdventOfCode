#include <string>
#include <fstream>
#include <iostream>

#define LEN 14

int main(void)
{
    std::ifstream file("./data");
    std::string line, sub;

    getline(file, line);
    for (int i = 0; i < (line.size() - LEN - 1); i++)
    {
        bool identical = false;
        sub = line.substr(i, LEN);
        for (int j = 0; j < sub.size() - 1; j++)
        {
            for (int k = 1; k < sub.size(); k++)
            {
                if (sub[j] == sub[k] && k != j)
                    identical = true;
            }
            if (identical)
                break ;
        }
        if (!identical){
            std::cout << "This is: " << i + LEN << " - " << sub << std::endl;
            return 0;
        }
    }
    file.close();
}