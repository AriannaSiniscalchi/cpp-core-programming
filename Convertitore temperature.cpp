#include <iostream>
#include <iomanip>

using namespace std;

// Costanti per i limiti di temperatura
const double LIMITE_INFERIORE = 0;   // Zero assoluto in Celsius
const double LIMITE_SUPERIORE = 1000.0;    // Limite superiore

// Funzione per convertire Celsius in Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Funzione per validare l'input
bool validaInput(double inizio, double fine, double passo) {
    // Controlla i limiti della temperatura iniziale
    if (inizio < LIMITE_INFERIORE || inizio > LIMITE_SUPERIORE) {
        cout << "Errore: La temperatura iniziale deve essere tra " 
             << LIMITE_INFERIORE << "C e " << LIMITE_SUPERIORE << "C" << endl;
        return false;
    }
    
    // Controlla i limiti della temperatura finale
    if (fine < LIMITE_INFERIORE || fine > LIMITE_SUPERIORE) {
        cout << "Errore: La temperatura finale deve essere tra " 
             << LIMITE_INFERIORE << "C e " << LIMITE_SUPERIORE << "C" << endl;
        return false;
    }
    
    // Controlla che la temperatura finale sia maggiore di quella iniziale
    if (fine <= inizio) {
        cout << "Errore: La temperatura finale deve essere maggiore di quella iniziale" << endl;
        return false;
    }
    
    // Controlla che lo step size sia positivo
    if (passo <= 0) {
        cout << "Errore: La dimensione del passo deve essere maggiore di zero" << endl;
        return false;
    }
    
    // Controlla che lo step size non sia maggiore della differenza di temperature
    if (passo > (fine - inizio)) {
        cout << "Errore: La dimensione del passo non può essere maggiore della differenza tra le temperature" << endl;
        return false;
    }
    
    return true;
}

int main() {
    double temperaturaIniziale, temperaturaFinale, dimensionePasso;
    
    cout << "=== CONVERSIONE TEMPERATURE CELSIUS-FAHRENHEIT ===" << endl;
    cout << "Limiti consentiti: da " << LIMITE_INFERIORE << "C a " << LIMITE_SUPERIORE << "C" << endl << endl;
    
    // Input delle temperature
    cout << "Inserisci la temperatura iniziale (C): ";
    cin >> temperaturaIniziale;
    
    cout << "Inserisci la temperatura finale (C): ";
    cin >> temperaturaFinale;
    
    cout << "Inserisci la dimensione del passo (C): ";
    cin >> dimensionePasso;
    
    // Validazione dell'input
    if (!validaInput(temperaturaIniziale, temperaturaFinale, dimensionePasso)) {
        return 1; // Termina il programma con codice di errore
    }
    
    // Stampa l'intestazione della tabella
    cout << endl << "TABELLA DI CONVERSIONE" << endl;
    cout << "======================" << endl;
    cout << fixed << setprecision(2);
    cout << setw(12) << "Celsius" << setw(12) << "Fahrenheit" << endl;
    cout << setw(12) << "-------" << setw(12) << "----------" << endl;
    
    // Genera e stampa la tabella
    double temperaturaCorrente = temperaturaIniziale;
    while (temperaturaCorrente < temperaturaFinale) {
        double fahrenheit = celsiusToFahrenheit(temperaturaCorrente);
        cout << setw(12) << temperaturaCorrente << setw(12) << fahrenheit << endl;
        temperaturaCorrente += dimensionePasso;
    }
    
    cout << endl << "Conversione completata!" << endl;
    
    return 0;
}
