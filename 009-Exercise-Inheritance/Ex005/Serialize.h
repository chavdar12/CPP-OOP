#ifndef SERIALIZE_H
#define SERIALIZE_H

byte* serializeToMemory(std::string s, size_t& bytesWritten)
{
    std::vector<byte> vB;

    byte companies = 0;
    vB.push_back(companies); //reserve position to calibrate later

    std::istringstream iss(s);
    Company company;

    while (iss >> company)
    {
        vB.push_back((byte)company.getId());

        for (auto chN : company.getName())
            vB.push_back((byte)chN);

        vB.push_back(0);

        vB.push_back((byte)company.getEmployees().size());

        for (auto empl : company.getEmployees())
        {
            vB.push_back((byte)empl.first);
            vB.push_back((byte)empl.second);
        }

        ++companies;
    }

    vB[0] = companies; //calibrate number of companies

    bytesWritten = vB.size();
    auto arrB = new byte[bytesWritten];

    for (size_t i = 0; i < bytesWritten; i++)
        arrB[i] = vB[i];

    return arrB;
}

#endif
