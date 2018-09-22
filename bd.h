#ifndef BD_H
#define BD_H

#include "file.h"
#include "cortages.h"
#include <fstream>
#include <vector>

std::string dbPath("dbFile.txt");

std::fstream file;
std::vector<cartage> crtgs;

void close_db()
{
    file.close();
}

void rewrite_db()
{
    file.open(dbPath,std::ios_base::in
              | std::ios_base::out
              | std::ios_base::trunc);

    for(auto x : crtgs)
    {
        file << x;
    }

    close_db();
}

void write_db()
{
    for(auto x : crtgs)
    {
        file << x;
    }
}

void open_db()
{
    file.open(dbPath,std::ios_base::in
              | std::ios_base::out
              | std::ios_base::app);
}

void read_db()
{
    cartage buf;
    try {
        crtgs.clear();
        while (!file.eof() && file >> buf) {
            crtgs.push_back(buf);
        }
    }
    catch (...) {
    }
}


#endif // BD_H
