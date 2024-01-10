#include "algos.cpp"
#include <string>
#include <time.h>
#include <chrono>
#include <string.h>
#include <iomanip>


void chosseMode (int a[], int n, char *str)
{
    if (strcmp (str, "-rand") == 0)
    {
        cout << "Input order: Random data\n";
        cout << "----------\n";
        GenerateRandomData (a, n);
    }
    else if (strcmp (str, "-nsort") == 0)
    {
        cout << "Input order: Nearly sorted data\n";
        cout << "----------\n";
        GenerateNearlySortedData (a, n);
    }
    else if (strcmp (str, "-sorted") == 0)
    {
        cout << "Input order: Sorted data\n";
        cout << "----------\n";
        GenerateSortedData (a, n);
    }
    else if (strcmp (str, "-rev") == 0)
    {
        cout << "Input order: Reverse sorted data\n";
        cout << "----------\n";
        GenerateReverseData (a, n);
    }
}


int main (int argc, char * argv[]){
    if (strcmp (argv[1], "-a") == 0){
        cout<<"ALGORITHM MODE\n";
//commmand 2----------------------------------------------------------------------------------//
        if(argc == 6){
            string algo = argv[2];
            int n = atoi (argv[3]);
            int* a = new int[n];
            cout << "Algorithm:" << algo << endl;
            cout << "Input size: " << n << endl;
            chosseMode (a, n, argv[4]);
            writeTXT("input.txt",a, n);
            if (strcmp (argv[5], "-time") == 0){
                auto start = chrono::high_resolution_clock::now ();
                chooseAlgo_time(algo, a, n);
                auto end = chrono::high_resolution_clock::now ();
                cout << "Running time: " << fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
            }
            else if (strcmp (argv[5], "-comp") == 0){
                unsigned long long com = 0;
                chooseAlgo_com(algo, a, n, com);
                cout << "Comparisions: " << com << endl;
            }
            else if (strcmp (argv[5], "-both") == 0){
                unsigned long long com = 0;
                auto start = chrono::high_resolution_clock::now ();
                chooseAlgo_time(algo, a, n);
                auto end = chrono::high_resolution_clock::now ();
                chooseAlgo_com(algo, a, n, com);
                cout << "Running time: "<< fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                cout << "Comparisions: " << com << endl;
            }
            writeTXT("output.txt",a, n);
            return 0;
        }
        if(argc == 5){
            string temp = argv[3];
//commmand 3------------------------------------------------------------------------------------//
            if(isNumber(temp)){
                string algo = argv[2];
                int n = stoi(temp);
                int* a = new int[n];
                int* b = new int[n];
                cout << "Algorithm:" << algo << endl;
                cout << "Input size: " << n << endl;
                unsigned long long com = 0;

                //time
                if(strcmp (argv[4], "-time") == 0){
                    chosseMode(a, n, "-rand");
                    writeTXT("input1.txt",a, n);
                    cout << "Input order : randomized\n";
                    auto start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    auto end = chrono::high_resolution_clock::now ();
                    cout << "Running time: " << fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-nsort");
                    writeTXT("input2.txt",a, n);
                    cout << "Input order : nearly sorted\n";
                    start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    end = chrono::high_resolution_clock::now ();
                    cout << "Running time: " <<fixed << std::setprecision(8) << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-sorted");
                    writeTXT("input3.txt",a, n);
                    cout << "Input order : sorted\n";
                    start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    end = chrono::high_resolution_clock::now ();
                    cout << "Running time: " << fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-rev");
                    cout << "Input order : reversed\n";
                    writeTXT("input4.txt",a, n);
                    start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    end = chrono::high_resolution_clock::now ();
                    cout << "Running time: " << fixed << std::setprecision(8) << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "-----------------------------------------------------\n";
                }

                //comparions
                else if (strcmp(argv[4], "-comp") == 0){
                    chosseMode(a, n, "-rand");
                    writeTXT("input1.txt",a, n);
                    cout << "Input order : randomized\n";
                    chooseAlgo_com(algo, a, n, com);
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-nsort");
                    writeTXT("input2.txt",a, n);
                    cout << "Input order : nearly sorted\n";
                    chooseAlgo_com(algo, a, n, com);
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-sorted");
                    writeTXT("input3.txt",a, n);
                    cout << "Input order : sorted\n";
                    chooseAlgo_com(algo, a, n, com);
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-rev");
                    writeTXT("input4.txt",a, n);
                    cout << "Input order : reversed\n";
                    chooseAlgo_com(algo, a, n, com);
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                }

                //both
                else if (strcmp (argv[4], "-both") == 0){
                    chosseMode(a, n, "-rand");
                    for(int i= 0; i<n; i++){
                        b[i] = a[i]; 
                    }
                    writeTXT("input1.txt",a, n);
                    cout << "Input order : randomized\n";
                    auto start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    auto end = chrono::high_resolution_clock::now ();
                    chooseAlgo_com(algo, b, n, com);
                    cout << "Running time: " << fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-nsort");
                    for(int i= 0; i<n; i++){
                        b[i] = a[i]; 
                    }
                    writeTXT("input2.txt",a, n);
                    cout << "Input order : nearly sorted\n";
                    start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    end = chrono::high_resolution_clock::now ();
                    chooseAlgo_com(algo, b, n, com);
                    cout << "Running time: " <<fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-sorted");
                    for(int i= 0; i<n; i++){
                        b[i] = a[i]; 
                    }
                    writeTXT("input3.txt",a, n);
                    cout << "Input order : sorted\n";
                    start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    end = chrono::high_resolution_clock::now ();
                    chooseAlgo_com(algo, b, n, com);
                    cout << "Running time: " << fixed << std::setprecision(8) << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                    chosseMode(a, n, "-rev");
                    for(int i= 0; i<n; i++){
                        b[i] = a[i]; 
                    }
                    writeTXT("input4.txt",a, n);
                    cout << "Input order : reversed\n";
                    start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    end = chrono::high_resolution_clock::now ();
                    chooseAlgo_com(algo, b, n, com);
                    cout << "Running time: " << fixed << std::setprecision(8) << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "Comparisions: " << com << endl;
                    cout << "-----------------------------------------------------\n";
                }
            }
//commmand 1------------------------------------------------------------------------------------------//
            else{
                string giveninput = argv[3];
                string algo = argv[2];
                int n;
                int* a;
                readFile(giveninput, n, a);
                cout << "Algorithm: " << algo << endl;
                cout << "Input size: " << n << "\n";
                cout << "Input file: " << giveninput << "\n";
                if (strcmp (argv[4], "-time") == 0){
                    auto start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    auto end = chrono::high_resolution_clock::now ();
                    cout << "Running time: "<<fixed << std::setprecision(8) << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                }
                else if (strcmp (argv[4], "-comp") == 0){
                    unsigned long long com = 0;
                    chooseAlgo_com(algo, a, n, com);
                    cout << "Comparisions: " << com << endl;
                }
                else if (strcmp (argv[4], "-both") == 0){
                    unsigned long long com = 0;
                    auto start = chrono::high_resolution_clock::now ();
                    chooseAlgo_time(algo, a, n);
                    auto end = chrono::high_resolution_clock::now ();
                    chooseAlgo_com(algo, a, n, com);
                    cout << "Running time: "<< fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << endl;
                    cout << "Comparisions: " << com << endl;
                }
                writeTXT("output.txt",a, n);
                return 0;
            }
        }
    }
    if(strcmp (argv[1], "-c") == 0){
        cout << "COMPARISON MODE" << "\n"; 
        string algo1 = argv[2];
        string algo2 = argv[3];
//commmand 4------------------------------------------------------------------------------------------//
        if(argc == 5){
			string giveninput = argv[4];\
            int n;
			int* a;
            readFile(giveninput, n, a);
            int* b;
            unsigned long long com1 = 0;
            for(int i= 0; i<n; i++){
                b[i] = a[i]; 
            }
            unsigned long long com2 = 0;
            //algo1
            auto start1 = chrono::high_resolution_clock::now ();
            chooseAlgo_time(algo1, a, n);
            auto end1 = chrono::high_resolution_clock::now ();
            chooseAlgo_com(algo1, a, n, com1);
            //algo2
            auto start2 = chrono::high_resolution_clock::now ();
            chooseAlgo_time(algo2, b, n);
            auto end2 = chrono::high_resolution_clock::now ();
            chooseAlgo_com(algo2, b, n, com2);

            cout << "Algorithm: " << algo1 <<" | " << algo2 << endl;
            cout << "Input size: " << n << "\n";
            cout << "Input file: " << giveninput << "\n";
            cout << "-----------------------------------------------------\n";
            cout << "Running time: " << "Sort Time 1 :" <<fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end1-start1).count() << " | " << "Sort time 2 :"<< fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2).count() << endl;
            cout << "Comparisions:" << "Sort comp 1 :" << com1 << " | " << "Sort comp 2 :"<< com2 << endl;
        }
//commmand 5-----------------------------------------------------------------------------------------------//
        else if(argc == 6){
			int n = atoi(argv[4]);
			string order = argv[5];
			int typedat;
			if( order == "-rand"){
				typedat = 0;
			}
			else if( order == "-nsorted"){
				typedat = 3;
			}
			else if( order == "-sorted"){
				typedat = 1;
			}
			else if( order == "-rev"){
				typedat = 2;
			}
			int* a = new int[n];
            int* b = new int[n];
			GenerateData(a, n, typedat);
            writeTXT("input.txt",a, n);
            unsigned long long com1 = 0;
            for(int i= 0; i<n; i++){
                b[i] = a[i]; 
            }
            unsigned long long com2 = 0;
            //algo1
            auto start1 = chrono::high_resolution_clock::now ();
            chooseAlgo_time(algo1, a, n);
            auto end1 = chrono::high_resolution_clock::now ();
            chooseAlgo_com(algo1, a, n, com1);
            //algo2
            auto start2 = chrono::high_resolution_clock::now ();
            chooseAlgo_time(algo2, b, n);
            auto end2 = chrono::high_resolution_clock::now ();
            chooseAlgo_com(algo2, b, n, com2);
            cout << "Algorithm: " << algo1 <<" | " << algo2 << endl;
            cout << "Input size: " << n << "\n";
            cout << "Input order: " << order << "\n";
            cout << "-----------------------------------------------------\n";
            cout << "Running time: " << "Sort Time 1 :"<< fixed << std::setprecision(8) << std::chrono::duration_cast<std::chrono::milliseconds>(end1-start1).count() << " | " << "Sort time 2 :"<<fixed << std::setprecision(8)<< std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2).count() << endl;
            cout << "Comparisions:" << "Sort comp 1 :" << com1 << " | " << "Sort comp 2 :"<< com2 << endl;
        }
    }
    return 0;
}