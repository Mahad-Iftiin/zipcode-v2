#pragma once

#include "ZipCodeRecord.hpp"
#include <istream>
#include <string>

class CsvBuffer {
  std::string record;

public:
  bool read(std::istream &file);
  bool unpack(ZipCodeRecord &record);
  const std::string &getRecord() const;
};
