#pragma once

#include <cstdint>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

class HeaderBuffer {
public:
  std::string type;
  std::uint16_t version;
  std::uint32_t headerSize;
  std::uint8_t recordLengthBytes;
  std::string formatType;
  std::uint8_t sizeOfSizes;
  bool inclusionFlag;
  std::string fileName;
  std::uint32_t recordCount;
  std::uint32_t fieldCount;
  std::uint32_t primaryKeyIndex;

struct Field {
  std::string name;
  std::string type;
};

std::vector<Field> fields;

bool read(std::istream &file);
bool write(std::ostream &file) const;
};
