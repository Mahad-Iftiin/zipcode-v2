#include "CsvBuffer.hpp"
#include "HeaderBuffer.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main() {

  //  Original CSV files
  ifstream file1("./../data/us_postal_codes.csv");
  ifstream file2("./../data/us_postal_codes_ROWS_RANDOMIZED.csv");

  // Length-indicated output files
  ofstream output1("./../data/us_postal_codes_length.txt", ios::binary);
  ofstream output2("./../data/us_postal_codes_ROWS_RANDOMIZED_length.txt",
                   ios::binary);

  // index files
  ofstream index1("./../data/us_postal_codes_index.txt");
  ofstream index2("./../data/us_postal_codes_ROWS_RANDOMIZED_index.txt");

  // check that each file opened successfully
  if (!file1 || !file2 || !output1 || !output2 || !index1 || !index2) {
    cerr << "One or more files failed to open\n";
    return 1;
  }

  // Buffers for csv
  CsvBuffer csvBuffer1;
  CsvBuffer csvBuffer2;

  // headerbuffer 1
  HeaderBuffer headerBuffer1;

  headerBuffer1.type = "LengthIndicated";
  headerBuffer1.version = 1;
  headerBuffer1.headerSize = 0;
  headerBuffer1.recordLengthBytes = 2;
  headerBuffer1.formatType = "binary";
  headerBuffer1.sizeOfSizes = 2;
  headerBuffer1.inclusionFlag = false;
  headerBuffer1.fileName = "us_postal_codes.idx";
  headerBuffer1.recordCount = 0;
  headerBuffer1.fieldCount = 0;
  headerBuffer1.primaryKeyIndex = 0;

  HeaderBuffer headerBuffer2;

  headerBuffer2.type = "LengthIndicated";
  headerBuffer2.version = 1;
  headerBuffer2.headerSize = 0;
  headerBuffer2.recordLengthBytes = 2;
  headerBuffer2.formatType = "binary";
  headerBuffer2.sizeOfSizes = 2;
  headerBuffer2.inclusionFlag = false;
  headerBuffer2.fileName = "us_postal_codes.idx";
  headerBuffer2.recordCount = 0;
  headerBuffer2.fieldCount = 0;
  headerBuffer2.primaryKeyIndex = 0;

  ZipCodeRecord zipCodeRecord1;
  ZipCodeRecord zipCodeRecord2;

  // skip the csv header for both files
  csvBuffer1.read(file1);
  csvBuffer2.read(file2);

  while (csvBuffer1.read(file1)) {

    if (!csvBuffer1.unpack(zipCodeRecord1))
      return 1;

    headerBuffer1.recordCount++;
  }

  while (csvBuffer2.read(file2)) {

    // unpack each record into a zipcoderecord
    if (!csvBuffer2.unpack(zipCodeRecord2))
      return 1;

    headerBuffer2.recordCount++;
  }



  return 0;
}
