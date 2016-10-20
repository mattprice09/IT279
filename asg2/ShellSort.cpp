
#include <vector>

using namespace std;

ShellSort::ShellSort() {

}

ShellSort::sort() {

}

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


}
