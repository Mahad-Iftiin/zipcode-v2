#include "HeaderBuffer.hpp"

bool HeaderBuffer::read(std::istream &file) {
  // read the header of an existing file into a buffer
  unsigned int lengthBytes;
  unsigned int sizeBytes;

  if (!(file >> type >> version >> headerSize >> lengthBytes >> formatType >>
        sizeBytes >> inclusionFlag >> fileName >> recordCount >> fieldCount >>
        primaryKeyIndex))
    return false;

  recordLengthBytes = lengthBytes;
  sizeOfSizes = sizeBytes;

  fields.clear();

  for (int i = 0; i < fieldCount; i++) {
    Field field;

    if (!(file >> field.name >> field.type)) {
      return false;
    }

    fields.push_back(field);
  }

  return true;
}

/**
 * Write the contents of the HeaderBuffer to a file
 */
bool HeaderBuffer::write(std::ostream &file) const {

  file << type << '\n';
  file << version << '\n';
  file << headerSize << '\n';
  file << static_cast<int>(recordLengthBytes) << '\n';
  file << formatType << '\n';
  file << static_cast<int>(sizeOfSizes) << '\n';
  file << inclusionFlag << '\n';
  file << fileName << '\n';
  file << recordCount << '\n';
  file << fieldCount << '\n';
  file << primaryKeyIndex << '\n';

  for (const Field &field : fields) {
    file << field.name << ' ' << field.type << '\n';
  }



  return static_cast<bool>(file);
}
