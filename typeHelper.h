#ifndef TYPEHELPER_H
#define TYPEHELPER_H

#include <string>
#include <unordered_map>

enum class Type 
{
    heat, 
    plant, 
    drip,
};


class TypeHelper {
public:

    int TypeHelper::typeBattle(Type &type1, Type &type2);

    bool TypeHelper::checkNotEffective(Type &type1, Type &type2);

    bool TypeHelper::checkVeryEffective(Type &type1, Type &type2);

    std::string TypeHelper::printTypeBattle(Type &type1, Type &type2);

    std::string TypeHelper::printType(Type type);

    std::string TypeHelper::printResult(int res);

private:

    std::unordered_map <Type, std::string> typeLookup = {
        {Type::heat, "Heat"},
        {Type::plant, "Plant"},
        {Type::drip, "Drip"},
    };

    std::unordered_map <int, std::string> battleLookup = {
        {-1, "not very effective"},
        {0, "reasonably effective"},
        {1, "very effective"},
    };

};

#endif