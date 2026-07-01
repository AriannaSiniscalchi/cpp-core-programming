#include <iostream>
#include <iomanip>

using namespace std;

// Constants defining allowed temperature boundaries
const double LIMITE_INFERIORE = 0;      // Absolute zero in Celsius (simplified lower bound)
const double LIMITE_SUPERIORE = 1000.0; // Upper temperature threshold

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to validate user parameters
bool validaInput(double inizio, double fine, double passo) {
    // Validate initial temperature boundaries
    if (inizio < LIMITE_INFERIORE || inizio > LIMITE_SUPERIORE) {
        cout << "Error: Initial temperature must be between " 
             << LIMITE_INFERIORE << "C and " << LIMITE_SUPERIORE << "C" << endl;
        return false;
    }
    
    // Validate final temperature boundaries
    if (fine < LIMITE_INFERIORE || fine > LIMITE_SUPERIORE) {
        cout << "Error: Final temperature must be between " 
             << LIMITE_INFERIORE << "C and " << LIMITE_SUPERIORE << "C" << endl;
        return false;
    }
    
    // Ensure logical order (final temperature must be greater than initial)
    if (fine <= inizio) {
        cout << "Error: Final temperature must be strictly greater than initial temperature" << endl;
        return false;
    }
    
    // Ensure the step size is a positive non-zero value
    if (passo <= 0) {
        cout << "Error: Step size must be strictly greater than zero" << endl;
        return false;
    }
    
    // Ensure step size does not exceed the total temperature delta
    if (passo > (fine - inizio)) {
        cout << "Error: Step size cannot be greater than the difference between temperatures" << endl;
        return false;
    }
    
    return true;
}

int main() {
    double temperaturaIniziale, temperaturaFinale, dimensionePasso;
    
    cout << "=== CELSIUS-FAHRENHEIT TEMPERATURE CONVERTER ===" << endl;
    cout << "Allowed ranges: from " << LIMITE_INFERIORE << "C to " << LIMITE_SUPERIORE << "C" << endl << endl;
    
    // Temperature inputs
    cout << "Enter initial temperature (C): ";
    cin >> temperaturaIniziale;
    
    cout << "Enter final temperature (C): ";
    cin >> temperaturaFinale;
    
    cout << "Enter step size (C): ";
    cin >> dimensionePasso;
    
    // Parameter validation check
    if (!validaInput(temperaturaIniziale, temperaturaFinale, dimensionePasso)) {
        return 1; // Terminate execution with an error code
    }
    
    // Print conversion table header
    cout << endl << "CONVERSION TABLE" << endl;
    cout << "======================" << endl;
    cout << fixed << setprecision(2);
    cout << setw(12) << "Celsius" << setw(12) << "Fahrenheit" << endl;
    cout << setw(12) << "-------" << setw(12) << "----------" << endl;
    
    // Process and print data matrix rows
    double temperaturaCorrente = temperaturaIniziale;
    while (temperaturaCorrente < temperaturaFinale) {
        double fahrenheit = celsiusToFahrenheit(temperaturaCorrente);
        cout << setw(12) << temperaturaCorrente << setw(12) << fahrenheit << endl;
        temperaturaCorrente += dimensionePasso;
    }
    
    cout << endl << "Conversion completed successfully!" << endl;
    
    return 0;
}
