// Rainfall-Assignment
//Coursework In Intro To C++
//Name: Tarun Kumar
//Purpose: To sort an array of different Rainfall amounts by month
//Input: Months, Rainfall amounts
//Output: Average Rainfall, Highest Rainfall, Lowest Rainfall, Total Rainfall, Sorted rainfall by months




#include <iostream>
#include <fstream>

using namespace std;

const int Months = 12;
const string monthNames[Months] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void readRainfallData(double rainfall[], const string& filename) {
    ifstream infile(filename);
    for (int i = 0; i < Months; i++) {
        infile >> rainfall[i];
    }
    infile.close();
}

double calculateTotalRainfall(const double rainfall[]) {
    double total = 0;
    for (int i = 0; i < Months; i++) {
        total += rainfall[i];
    }
    return total;
}

double calculateAverageRainfall(const double rainfall[]) {
    double total = calculateTotalRainfall(rainfall);
    return total / Months;
}
int findMaxRainfallMonth(const double rainfall[]) {
    int maxIndex = 0;
    for (int i = 1; i < Months; i++) {
        if (rainfall[i] > rainfall[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}
int findMinRainfallMonth(const double rainfall[]) {
    int minIndex = 0;
    for (int i = 1; i < Months; i++) {
        if (rainfall[i] < rainfall[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
void sortRainfall(double rainfall[], string months[]) {
    for (int i = 0; i < Months - 1; i++) {
        for (int t = i + 1; t < Months; t++) {
            if (rainfall[i] < rainfall[t]) {
                swap(rainfall[i], rainfall[t]);
                swap(months[i], months[t]);
            }
        }
    }
}

int main() {
    double rainfall[Months];
    string filename = "rainfall.txt";

    readRainfallData(rainfall, filename);

    double totalRainfall = calculateTotalRainfall(rainfall);
    double averageRainfall = calculateAverageRainfall(rainfall);

    int maxMonth = findMaxRainfallMonth(rainfall);
    int minMonth = findMinRainfallMonth(rainfall);

    cout << "Total rainfall for the year: " << totalRainfall << " units";
    cout << "\nAverage monthly rainfall: " << averageRainfall << " units";
    cout << "\nMonth with highest rainfall: " << monthNames[maxMonth] << " (" << rainfall[maxMonth] << " units)" ;
    cout << "\nMonth with lowest rainfall: " << monthNames[minMonth] << " (" << rainfall[minMonth] << " units)" ;

    string sortedMonths[Months];
    for (int i = 0; i < Months; i++) {
        sortedMonths[i] = monthNames[i];
    }
    sortRainfall(rainfall, sortedMonths);

    cout << "\n\n\nMonths sorted by rainfall (highest to lowest):\n";
    for (int i = 0; i < Months; i++) {
        cout << sortedMonths[i] << ": " << rainfall[i] << " units\n ";
    }

    return 0;
}
