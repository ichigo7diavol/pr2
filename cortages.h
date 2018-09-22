#ifndef CORTAGES_H
#define CORTAGES_H

struct cartage
{
    cartage() {}
    cartage(std::string name, std::string village,
         int vill_count, float square)
        : m_name(name)
        , m_village(village)
        , m_vill_count(vill_count)
        , m_square(square) {}

    std::string m_name;
    std::string m_village;
    int m_vill_count;
    float m_square;

    friend std::fstream &  operator << (std::fstream & stream,
                                         const cartage & crtg)
    {
        stream << crtg.m_name << std::endl
               << crtg.m_village << std::endl
               << crtg.m_vill_count << std::endl
               << crtg.m_square << std::endl;

        return stream;
    }

    friend std::ostream &  operator << (std::ostream & stream,
                                         const cartage & crtg)
    {
        stream << crtg.m_name << ' '
               << crtg.m_village << ' '
               << crtg.m_vill_count << ' '
               << crtg.m_square << std::endl;
        return stream;
    }

    friend std::fstream&  operator >> (std::fstream & stream,
                                         cartage & crtg)
    {
        char buf[255] = {'\0'};
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_name = buf;
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_village = buf;
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_vill_count = atof(buf);
        if ((buf[0] != '0' || std::string(buf).size() > 0)
                && crtg.m_vill_count == 0)
        {
            throw std::invalid_argument("");
        }
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_square = atof(buf);
        if ((buf[0] != '0' || std::string(buf).size() > 0)
                && crtg.m_square == 0)
            throw std::invalid_argument("");

        return stream;
    }

    friend std::istream&  operator >> (std::istream & stream,
                                         cartage & crtg)
    {
        char buf[255] = {'\0'};
        std::cout << "Type dev name.\n";
        fuckenDemolishEndlineSymbol();
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_name = buf;
        std::cout << "Type village name.\n";
        fuckenDemolishEndlineSymbol();
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_village = buf;
        std::cout << "Type people count.\n";
        fuckenDemolishEndlineSymbol();
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_vill_count = atof(buf);
        if ((buf[0] != '0' || std::string(buf).size() > 0)
                && crtg.m_vill_count == 0)
        {
            throw std::invalid_argument("");
        }
        std::cout << "Type square of village.\n";
        fuckenDemolishEndlineSymbol();
        flush(buf);
        stream.getline(buf, 255);
        crtg.m_square = atof(buf);
        if ((buf[0] != '0' || std::string(buf).size() > 0)
                && crtg.m_square == 0)
            throw std::invalid_argument("");

        return stream;
    }
};

#endif // CORTAGES_H
