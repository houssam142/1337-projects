#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
  private:
    Serializer();
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& eq);
    ~Serializer();
  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
