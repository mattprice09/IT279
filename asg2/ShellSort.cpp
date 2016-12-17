
#include "stdlib.h"
#include "ShellSort.h"

ShellSort::ShellSort() {

}

/**
* Sort data in place using shell sort algorithm with Hibbard's increments
*/
void ShellSort::sort() {
  std::vector<int> gapStack;

  // Generate vector of Hibbard's increments so that we dont have to
  // recalculate every time we decrement
  int currExponent = 1;
  while ((pow(2, currExponent) - 1) < data.size()) {
    gapStack.push_back(pow(2, currExponent) - 1);
    currExponent ++;
  }

  // Perform shell sort for each increment
  while (gapStack.size() > 0) {
    int currIncrement = gapStack.back();
    gapStack.pop_back();

    // Sort each column using InsertionSort
    int col = 0;
    while (col < currIncrement) {
      int stopInd = 1;
      int index = col + (stopInd * currIncrement);

      // Iterate over all items in column
      while (index < data.size()) {
        int currInd = 0;

        // Iterate until the current stop value
        while (currInd < stopInd) {
          if (data[index] < data[col + (currInd * currIncrement)]) {
            // Swap values because current value is less than value in array
            int copy = data[col + (currInd * currIncrement)];
            data[col + (currInd * currIncrement)] = data[index];
            data[index] = copy;
          }
          currInd ++;
        }

        // push stop index back by 1 (for InsertionSort)
        stopInd ++;
        index = col + (stopInd * currIncrement);
      }
      col ++;
    }
  }
}

/**
* Read data file into memory (vector of ints)
*/
void ShellSort::readFile(const char* filename) {
  std::ifstream inputFile(filename);
  std::string line;

  if (inputFile.is_open()) {
    int curr;

    while(std::getline(inputFile, line)) {
      std::istringstream iss(line);
      if (!(iss >> curr)) {
        // end of file
        break;
      }
      data.push_back(curr);
    }
    inputFile.close();
  } else {
    std::cerr << "Unable to open file" << std::endl;
    exit (EXIT_FAILURE);
  }
}

/**
* Write data to the specified output file
*/
void ShellSort::outputFile(const char* filename) {
  std::ofstream outputFile (filename);
  if (outputFile.is_open()) {
    for (int i = 0; i < data.size(); i++) {
      outputFile << data[i] << '\n';
    }
    outputFile.close();
  } else {
    std::cerr << "Unable to open output file" << std::endl;
    exit (EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
    std::cerr << "Usage: " << argv[0] << " INPUT_FILE OUTPUT_FILE"
      << std::endl;
    return 1;
  }
  
  ShellSort sorter;

  sorter.readFile(argv[1]);
  sorter.sort();
  sorter.outputFile(argv[2]);
}
