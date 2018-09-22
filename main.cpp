#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "file.h"
#include "bd.h"
#include "cortages.h"

extern std::fstream file;
extern std::vector<cartage> crtgs;

bool key_routing(char key)
{
    int idx = 0;
    std::string inp;
    cartage buf;
    int i = 0;
    switch (key)
    {
    case 'A':
    case 'a':
        try {
            open_db();
            close_db();
            std::cin >> buf;
            crtgs.push_back(buf);
            rewrite_db();
        } catch (...) {
            std::cout << "Wrong fields format! (When adding cortages!)\n";
        }
        break;
    case 'M':
    case 'm':
        std::cout << "Type index to modify:\n";
        std::cin >> inp;
        open_db();
        close_db();
        i = atoi(inp.c_str());
        if (i <= crtgs.size() && i > 0) {
            try {
                std::cin >> buf;
            } catch (...) {
                std::cout << "Wrong fields format!\n";
            }
            crtgs[i - 1] = buf;
            rewrite_db();
        } else
            std::cout << "Wrong index!\n";
        break;
    case 'd':
    case 'D':
        std::cout << "Type index to delete:\n";
        std::cin >> inp;
        open_db();
        read_db();
        close_db();
        i = atoi(inp.c_str());
        if (i <= crtgs.size() && i > 0) {
            crtgs.erase(crtgs.begin() + i - 1);
            open_db();
            close_db();
            rewrite_db();

        } else
            std::cout << "Wrong index! (At del else)\n";
        break;
    case 'e':
    case 'E':
        return false;
    case 'p':
    case 'P':
        open_db();
        read_db();
        for (auto & x : crtgs )
            std::cout << ++idx << ':' << x;
        close_db();
        break;
    default:
        std::cout << "Wrong command!\n";
        break;
    }

    return true;
}

void routine()
{
    std::string key;
    do {
        std::cout << "Type any key to do smth (a - add, d - del, m - modify, p - print, e - exit): \n";
        std::cin >> key;
        if (key.size() > 1)
            key[0] = ' ';

    } while (key_routing(key[0]));
}

int main()
{
    routine();

    return 0;
}
