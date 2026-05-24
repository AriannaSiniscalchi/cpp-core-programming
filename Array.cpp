#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int DIM = 50;

// Funzione per generare l'array
void generaArray(int array[]) {
    for(int i = 0; i < DIM; i++) {
        array[i] = rand() % 100 + 1;
    }
}

// Funzione per calcolare la media
double calcolaMedia(int array[]) {
    double somma = 0;
    for(int i = 0; i < DIM; i++) {
        somma += array[i];
    }
    return somma / DIM;
}

// Funzione per trovare il massimo
int trovaMassimo(int array[]) {
    int max = array[0];
    for(int i = 1; i < DIM; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Funzione per trovare il minimo
int trovaMinimo(int array[]) {
    int min = array[0];
    for(int i = 1; i < DIM; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Funzione per valori vicini alla media
void valoriViciniMedia(int array[]) {
    double media = calcolaMedia(array);
    cout << "Media: " << media << endl;
    cout << "Valori vicini alla media:" << endl;
    
    bool trovati = false;
    for(int i = 0; i < DIM; i++) {
        if(fabs(array[i] - media) < 4) {
            cout << array[i] << " ";
            trovati = true;
        }
    }
    if(!trovati) {
        cout << "Nessun valore trovato";
    }
    cout << endl;
}

// Funzione per calcolare la moda
int calcolaModa(int array[]) {
    int frequenze[101] = {0}; // Array per contare le frequenze
    
    // Conta le occorrenze
    for(int i = 0; i < DIM; i++) {
        frequenze[array[i]]++;
    }
    
    // Trova il valore più frequente
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

// Funzione per stampare il menu
void stampaMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Calcola la media" << endl;
    cout << "2. Visualizza il massimo" << endl;
    cout << "3. Visualizza il minimo" << endl;
    cout << "4. Rigenera l'array" << endl;
    cout << "5. Valori vicini alla media" << endl;
    cout << "6. Calcola la moda" << endl;
    cout << "7. Esci" << endl;
    cout << "Scelta: ";
}

int main() {
    int array[DIM];
    int scelta;
    
    srand(time(0));
    generaArray(array);
    
    cout << "Array di " << DIM << " numeri generato (1-100)" << endl;
    
    do {
        stampaMenu();
        cin >> scelta;
        
        switch(scelta) {
            case 1:
                cout << "Media: " << calcolaMedia(array) << endl;
                break;
                
            case 2:
                cout << "Massimo: " << trovaMassimo(array) << endl;
                break;
                
            case 3:
                cout << "Minimo: " << trovaMinimo(array) << endl;
                break;
                
            case 4:
                generaArray(array);
                cout << "Array rigenerato!" << endl;
                break;
                
            case 5:
                valoriViciniMedia(array);
                break;
                
            case 6:
                cout << "Moda: " << calcolaModa(array) << endl;
                break;
                
            case 7:
                cout << "Arrivederci!" << endl;
                break;
                
            default:
                cout << "Scelta non valida!" << endl;
        }
        
    } while(scelta != 7);
    
    return 0;
}
