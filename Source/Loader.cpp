#include "../Header/Loader.h"
#include <iostream>
Loader::Loader(std::string fileName) : fileName(fileName) { this->initFile(); }

void Loader::initFile() {
  this->inputFile.open("../../../Maps/" + this->fileName);
  this->operateOnFile();
  this->inputFile.close();
}

void Loader::operateOnFile() {
  std::string tempLine{};

  /* while (std::getline(this->inputFile, tempLine)) {
     this->floorTable.push_back(tempLine);
   }*/
  for (size_t i = 0; i < this->floorTable.size(); i++) {
    std::getline(this->inputFile, tempLine);
    this->floorTable.at(i) = tempLine;
  }
}
