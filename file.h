#ifndef FILE_H
#define FILE_H

void fuckenDemolishEndlineSymbol()
{
    auto chr = std::cin.get();
    if (chr != '\n')
    {
        std::cin.putback(chr);
    }
}

void flush(char * buf)
{
    for (;*buf != '\0'; *buf = 0, ++buf);
}


#endif // FILE_H
