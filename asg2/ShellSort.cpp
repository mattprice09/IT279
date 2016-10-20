
#include <cmath>
#include <vector>

using namespace std;

ShellSort::ShellSort() {

}

/**
* Sort data in place using shell sort algorithm
*/
ShellSort::sort(std::vector<int> data) {
  std::vector<int> gapStack;

  // Generate vector of increments so that we dont have to recalculate every time
  int currExponent = 1;
  while ((pow(2, currExponent) - 1) < data.size()) {
    gapStack.push_back(pow(2, currExponent) - 1);
    currExponent ++;
  }

  // Perform shell sort for each increment
  while (gapStack.size() > 0) {
    int currIncrement = gapStack.back();
    gapStack.pop_back();
    // TODO: @mattprice09
  }

}

/**
* Read data file into memory
*/
void ShellSort::readFile(const char* filename) {
  std::ifstream inputFile(filename);
  std::string line;

  int next;
  std::vector<int> data;

  if (inputFile.is_open()) {
    // Assume there is at least one valid int in the input file
    inputFile >> next;
    data.push_back(next);

    while(inputFile >> data) {
     data.push_back(next);
    }
    inputFile.close();
  } else {
    std::cerr << "Unable to open file" << std::endl;
    exit (EXIT_FAILURE);
  }

  return data;
}

int main(int argc, char* argv[]) {
  
  ShellSort sorter;

  std::vector<int> data = sorter.readFile('data.txt');

  sorter.sort(data);

}
