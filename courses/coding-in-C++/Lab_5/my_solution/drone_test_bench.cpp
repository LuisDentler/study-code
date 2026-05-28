#include "drone_test_bench.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>




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
    printVector(recordSamples);

    std::sort(recordSamples.begin(), recordSamples.end());
    std::cout << "Sorted Value: ";
    printVector(recordSamples);
    

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
            *iterChangeToZero = 0;
       }
       
    }
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

    /* Task 9 
    std::vector<int> recordSamples = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    reportDataSet(recordSamples);
    std::vector<double> recordSamplesDouble = {7.5, -1.2, 13.3, -1.0, 21.8, 21.1, 8.6, -1.5, 8.9};
    reportDataSet(recordSamplesDouble);


    //Example drone_dataset as Array
    std::array<int, 5> drone_dataset = {10, 20, 30, 40, 50};
    std::vector<int> drone_vector = swapArrayToVector(drone_dataset);
    std::cout << "Drone Dataset as Vector: ";
    printVector(drone_vector);
    reportDataSet(drone_vector);

    //Example boolean dataset 
    std::vector<bool> bool_dataset = {true, false, true, true, false};
    reportDataSet(bool_dataset);

    */
    return 0;
}
