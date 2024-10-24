#include <iostream>
#include <fstream>
using namespace std;

// Function declarations
void read3arrays(ifstream& inFile, int exam1[], int exam2[], int exam3[], int k);
void print1array(ofstream& outFile, const int nums[], int k, const char* heading);
void makeweightedavg(const int exam1[], const int exam2[], const int exam3[], int weightedavg[], int k);
void findsmallestandpos(const int nums[], int k, int& smallest, int& pos);

int main() {
    const int k = 20; // Array size

    // Open files
    ifstream inFile("text.txt");
    ofstream outFile("outputdata.txt");

    // Check if files are open
    if (!inFile) {
        cerr << "Unable to open input file!" << endl;
        return 1;
    }
    if (!outFile) {
        cerr << "Unable to open output file!" << endl;
        return 1;
    }

    // Arrays for storing exam scores and weighted averages
    int exam1[k], exam2[k], exam3[k], weightedavg[k];

    // Read data into arrays
    read3arrays(inFile, exam1, exam2, exam3, k);

    // Print original exam data
    print1array(outFile, exam1, k, "Exam 1 Scores");
    outFile << endl;
    print1array(outFile, exam2, k, "Exam 2 Scores");
    outFile << endl;
    print1array(outFile, exam3, k, "Exam 3 Scores");
    outFile << endl << endl;

    //Prints out weighted averages
    makeweightedavg(exam1, exam2, exam3, weightedavg, k);
    print1array(outFile, weightedavg, k, "Weighted Averages");
    outFile << endl;

    // Find and prints out the smallest score and its position for each array
    int smallest, pos;
    findsmallestandpos(exam1, k, smallest, pos);
    outFile << "Smallest score in Exam 1: " << smallest << " at position " << pos << " of the array." << endl;
    findsmallestandpos(exam2, k, smallest, pos);
    outFile << "Smallest score in Exam 2: " << smallest << " at position " << pos << " of the array." << endl;
    findsmallestandpos(exam3, k, smallest, pos);
    outFile << "Smallest score in Exam 3: " << smallest << " at position " << pos << " of the array." << endl;
    findsmallestandpos(weightedavg, k, smallest, pos);
    outFile << "Smallest score in Weighted Averages: " << smallest << " at position " << pos << " of the array." << endl;

    // Close files
    inFile.close();
    outFile.close();

    return 0;
}

// Function definitions
void read3arrays(ifstream& inFile, int exam1[], int exam2[], int exam3[], int k) {
    int i = 0;
    while (i < k && inFile >> exam1[i] >> exam2[i] >> exam3[i]) {
        i++;
    }
}

void print1array(ofstream& outFile, const int nums[], int k, const char* heading) {
    outFile << heading << ":\n";
    for (int i = 0; i < k; i++) {
        outFile.width(6);
        outFile << nums[i];
        if ((i + 1) % 6 == 0) outFile << "\n";
    }
    outFile << "\n";
}

void makeweightedavg(const int exam1[], const int exam2[], const int exam3[], int weightedavg[], int k) {
    for (int i = 0; i < k; i++) {
        weightedavg[i] = (exam1[i] + 2 * exam2[i] + 3 * exam3[i]) / 6;
    }
}

void findsmallestandpos(const int nums[], int k, int& smallest, int& pos) {
    smallest = nums[0];
    pos = 0;
    for (int i = 1; i < k; i++) {
        if (nums[i] < smallest) {
            smallest = nums[i];
            pos = i;
        }
    }
}
