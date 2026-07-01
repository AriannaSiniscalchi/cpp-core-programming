#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int DIM = 50;

// Function to populate the array with random numbers
void generaArray(int array[]) {
    for(int i = 0; i < DIM; i++) {
        array[i] = rand() % 100 + 1;
    }
}

// Function to calculate the arithmetic mean
double calcolaMedia(int array[]) {
    double somma = 0;
    for(int i = 0; i < DIM; i++) {
        somma += array[i];
    }
    return somma / DIM;
}

// Function to find the maximum value
int trovaMassimo(int array[]) {
    int max = array[0];
    for(int i = 1; i < DIM; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to find the minimum value
int trovaMinimo(int array[]) {
    int min = array[0];
    for(int i = 1; i < DIM; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to display values close to the mean
void valoriViciniMedia(int array[]) {
    double media = calcolaMedia(array);
    cout << "Mean: " << media << endl;
    cout << "Values close to the mean:" << endl;
    
    bool trovati = false;
    for(int i = 0; i < DIM; i++) {
        if(fabs(array[i] - media) < 4) {
            cout << array[i] << " ";
            trovati = true;
        }
    }
    if(!trovati) {
        cout << "No matching values found";
    }
    cout << endl;
}

// Function to calculate the mode (most frequent value)
int calcolaModa(int array[]) {
    int frequenze[101] = {0}; // Frequency array to count occurrences
    
    // Count occurrences of each number
    for(int i = 0; i < DIM; i++) {
        frequenze[array[i]]++;
    }
    
    // Identify the most frequent value
    int moda = 1;
    int maxFreq = frequenze[1];
    
    for(int i = 2; i <= 100; i++) {
        if(frequenze[i] > maxFreq) {
            maxFreq = frequenze[i];
            moda = i;
        }
    }
    
    return moda;
}

// Function to display the user menu
void stampaMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Calculate mean" << endl;
    cout << "2. View maximum value" << endl;
    cout << "3. View minimum value" << endl;
    cout << "4. Regenerate array" << endl;
    cout << "5. View values close to the mean" << endl;
    cout << "6. Calculate mode" << endl;
    cout << "7. Exit" << endl;
    cout << "Choice: ";
}

int main() {
    int array[DIM];
    int scelta;
    
    srand(time(0));
    generaArray(array);
    
    cout << "Array of " << DIM << " random numbers generated (1-100)" << endl;
    
    do {
        stampaMenu();
        cin >> scelta;
        
        switch(scelta) {
            case 1:
                cout << "Mean: " << calcolaMedia(array) << endl;
                break;
                
            case 2:
                cout << "Maximum: " << trovaMassimo(array) << endl;
                break;
                
            case 3:
                cout << "Minimum: " << trovaMinimo(array) << endl;
                break;
                
            case 4:
                generaArray(array);
                cout << "Array regenerated!" << endl;
                break;
                
            case 5:
                valoriViciniMedia(array);
                break;
                
            case 6:
                cout << "Mode: " << calcolaModa(array) << endl;
                break;
                
            case 7:
                cout << "Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }
        
    } while(scelta != 7);
    
    return 0;
}
