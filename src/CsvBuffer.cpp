#include "CsvBuffer.hpp"
#include <sstream>

#include <istream>

bool CsvBuffer::read(std::istream &file) {
  return static_cast<bool>(std::getline(file, record));
}

bool CsvBuffer::unpack(ZipCodeRecord &record) {

  std::stringstream ss(this->record);

  if (!std::getline(ss, record.zipCode, ','))
    return false;
  if (!std::getline(ss, record.place, ','))
    return false;
  if (!std::getline(ss, record.state, ','))
    return false;
  if (!std::getline(ss, record.county, ','))
    return false;
  if (!std::getline(ss, record.latitude, ','))
    return false;
  if (!std::getline(ss, record.longitude))
    return false;
  return true;
}

const std::string &CsvBuffer::getRecord() const { return record; }
