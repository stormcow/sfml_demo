#pragma once

#include <fstream>
#include <string>
#include <vector>

class Loader {
private:
  std::vector<std::string> floorTable{9, ""};
  std::string fileName{};
  std::ifstream inputFile;

  void initFile();
  void closeFile();
  void operateOnFile();

public:
  Loader(std::string fileName);
  Loader(){};
  std::vector<std::string> const getTable() { return floorTable; };
};
