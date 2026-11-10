/**
 * This is for reading a length delimited record into a buffer
 */

#pragma once

#include "ZipCodeRecord.hpp"

#include <string>

class LengthBuffer {
  std::string record;

public:
  bool read(std::istream &file);
  bool write(std::ostream &file) const;
  bool pack(const ZipCodeRecord &record);
  bool unpack(ZipCodeRecord &record) const;
};
