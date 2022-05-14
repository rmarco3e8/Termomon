#ifndef TYPEHELPER_H
#define TYPEHELPER_H

enum Type {heat, plant, drip};


class TypeHelper {

    int TypeHelper::type_vs(Type type1, Type type2);

    bool TypeHelper::checkNotEffective(Type &type1, Type &type2);

    bool TypeHelper::checkVeryEffective(Type &type1, Type &type2);
};

#endif