#include "drone_test_bench.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int>& vec){
    for(int value : vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}


int main(){

    /* Section 1 Tests
    int value1 = 10;
    int value2 = 20;
    std::cout << "Before swap: value1 = " << value1 << ", value2 = " << value2 << std::endl;
    swapValue(value1, value2);
    std::cout << "After swap: value1 = " <<value1 <<" Value2: " << value2 << std::endl;
    char sensorFrames[5] = {'?', '?', '?', '?', '?'};
    printSensorFrames(sensorFrames);
    printSensorMetadata("Battery Level", 85, "Status", "OK");
    */


    /* Task 6 
    std::vector<int> recordSamples = {42, 17, 42, 5, 99, 17, 63, 12};
    std::cout << "Original Value: ";
    for(int sample : recordSamples){
        std::cout << sample << " ";
    }
    std::cout << std::endl;

    std::sort(recordSamples.begin(), recordSamples.end());
    std::cout << "Sorted Value: ";
    for(int samples : recordSamples){
        std::cout << samples<< " ";
    }
    std::cout << std::endl;

    auto iter = std::find(recordSamples.begin(), recordSamples.end(), 63);
    if(iter != recordSamples.end()){
        std::cout << "Found value: " << *iter << std::endl;
    } else {
        std::cout << "Value not found." << std::endl;
    }
    */

    /* Task 7 
    std::vector<int> recordSamples = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    printVector(recordSamples);
    for(int sample : recordSamples){
       auto iterChangeToZero = std::find(recordSamples.begin(), recordSamples.end(), -1);
       if(iterChangeToZero != recordSamples.end()){
            *iterChangeToZero =0;
       }
       
    }
    printVector(recordSamples);
    auto count = std::count(recordSamples.begin(), recordSamples.end(), 8);
    std::cout << "Count of 8: " << count << std::endl;

    std::reverse(recordSamples.begin(), recordSamples.end());
    printVector(recordSamples);
    */


    /*Task 8

    *it -> gibt Wert des Iterators zurück
    ++it -> bewegt den Iterator zum nächsten Element

    std::vector<int> recordSamples = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    std::cout << "Original Value: ";
    for(auto iter = recordSamples.begin(); iter != recordSamples.end(); ++iter){
        std::cout << *iter << " ";
        }
    std::cout << std::endl;
    */

    /* Task 9 */
    std::vector<int> recordSamples = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    reportDataSet(recordSamples);
    std::vector<double> recordSamplesDouble = {7.5, -1.2, 13.3, -1.0, 21.8, 21.1, 8.6, -1.5, 8.9};
    reportDataSet(recordSamplesDouble);
    return 0;
}
