#include "SortingAlgorithm.hpp"
#include <chrono>
#include <vector>
#include <numeric> //used for generating random numbers

using namespace std;

int main(int argc, char * argv[])
{
    //argc tells how long is argv
    int s = 50; //number of times I evaluate the time for a fixed vector size (using big number law; increase k for better precision)
    vector<int> ns = {};
    ns.resize(argc-1);
    if (argc == 1){ //if no argument are given :(
        cerr << "no argument";
        return 1;
    }
    for (unsigned int i = 1; i < argc; i++){ //skipping 0 which contains the name of the file
        ns[i-1] = stoi(argv[i]);
    }

    vector<int> vect = {};
    for (unsigned int j = 0; j < size(ns); j++){
        vect.resize(ns[j]);
        double time_Merge = 0;
        double time_Bubble = 0;
        cout << "the size of the vector is :" << ns[j] << endl;
        for (unsigned int k = 0; k < s; k++){
            for (unsigned int i = 0; i < ns[j]; i++){
                vect[i] = rand();
            }

            vector<int> vectBubble = vect; //I have to make a copy to avoid silly mistakes

            //misurazione MergeSort
            chrono::steady_clock::time_point t_begin_Merge = chrono::steady_clock::now();
            SortLibrary::MergeSort(vect);
            chrono::steady_clock::time_point t_end_Merge = chrono::steady_clock::now();
            double timeElapsed_Mergesort = chrono::duration_cast<chrono::microseconds>(t_end_Merge-t_begin_Merge).count();

            //misurazioni bubblesort
            chrono::steady_clock::time_point t_begin_Bubble = chrono::steady_clock::now();
            SortLibrary::BubbleSort(vectBubble);
            chrono::steady_clock::time_point t_end_Bubble = chrono::steady_clock::now();
            double timeElapsed_BubbleSort = chrono::duration_cast<chrono::microseconds>(t_end_Bubble-t_begin_Bubble).count();

            time_Merge += timeElapsed_Mergesort;
            time_Bubble += timeElapsed_BubbleSort;

        }
        cout << "MergeSort average time: " << time_Merge/s << endl;
        cout << "BubbleSort average time: " << time_Bubble/s << endl;
        cout << endl;
    }

    return 0;
}

