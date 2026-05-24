// Inclusione delle librerie necessarie
#include <iostream>     // Per input/output (cin, cout)
#include <iomanip>      // Per la formattazione dell'output (setprecision)
#include <limits>       // Per i limiti dei tipi di dati

using namespace std;    // Permette di usare i nomi standard senza std::

int main() {
    // Dichiarazione delle variabili per i tre numeri
    int n1, n2, n3;
    // Variabile per memorizzare la scelta dell'utente
    char scelta;
    
    // Ciclo per la lettura dei tre valori con controllo di validità
    do {
        // Richiesta all'utente di inserire i tre valori
        cout << "Inserisci tre valori interi compresi tra 1 e 100: ";
        // Lettura dei tre valori da tastiera
        cin >> n1 >> n2 >> n3;
    } while (n1 < 1 || n1 > 100 || n2 < 1 || n2 > 100 || n3 < 1 || n3 > 100);
    // Il ciclo continua finché almeno uno dei valori non è compreso tra 1 e 100
    
    // Ciclo principale del programma che si ripete finché l'utente non sceglie di uscire
    do {
        // Stampa il menu delle operazioni disponibili
        cout << "\n=== MENU DI OPERAZIONI ===" << endl;
        cout << "A - somma tra n1, n2 e n3" << endl;           // Opzione A: somma
        cout << "B - prodotto tra n1 e n2" << endl;            // Opzione B: prodotto
        cout << "C - sottrazione tra n3 e n1" << endl;         // Opzione C: sottrazione
        cout << "D - divisione tra n1 e n2 (risultato double)" << endl; // Opzione D: divisione
        cout << "X - uscita dal programma" << endl;            // Opzione X: uscita
        cout << "Scelta: ";                                    // Prompt per la scelta
        
        // Lettura del carattere scelto dall'utente
        cin >> scelta;
        
        // Struttura switch per eseguire l'operazione corrispondente alla scelta
        switch(scelta) {
            // Caso A: somma dei tre numeri (accetta sia maiuscolo che minuscolo)
            case 'A':
            case 'a':
                // Stampa l'operazione e il risultato
                cout << "Operazione: " << n1 << " + " << n2 << " + " << n3 << " = " 
                     << (n1 + n2 + n3) << endl;
                break;  // Esce dallo switch
                
            // Caso B: prodotto tra n1 e n2 (accetta sia maiuscolo che minuscolo)
            case 'B':
            case 'b':
                // Stampa l'operazione e il risultato
                cout << "Operazione: " << n1 << " * " << n2 << " = " 
                     << (n1 * n2) << endl;
                break;  // Esce dallo switch
                
            // Caso C: sottrazione tra n3 e n1 (accetta sia maiuscolo che minuscolo)
            case 'C':
            case 'c':
                // Stampa l'operazione e il risultato
                cout << "Operazione: " << n3 << " - " << n1 << " = " 
                     << (n3 - n1) << endl;
                break;  // Esce dallo switch
                
            // Caso D: divisione tra n1 e n2 (accetta sia maiuscolo che minuscolo)
            case 'D':
            case 'd':
                // Controllo per evitare la divisione per zero
                if (n2 != 0) {
                    // Imposta la formattazione per numeri decimali
                    cout << fixed << setprecision(2);
                    // Stampa l'operazione e il risultato con conversione a double
                    cout << "Operazione: " << n1 << " / " << n2 << " = " 
                         << (static_cast<double>(n1) / n2) << endl;
                } else {
                    // Messaggio di errore se si tenta di dividere per zero
                    cout << "Errore: divisione per zero!" << endl;
                }
                break;  // Esce dallo switch
                
            // Caso X: uscita dal programma (accetta sia maiuscolo che minuscolo)
            case 'X':
            case 'x':
                // Messaggio di conferma uscita
                cout << "Uscita dal programma." << endl;
                break;  // Esce dallo switch
                
            // Caso default: gestisce tutti i caratteri non validi
            default:
                // Non fa nulla, il carattere viene ignorato
                // Il menu verrà ripresentato al prossimo ciclo
                break;  // Esce dallo switch
        }
        
    } while (scelta != 'X' && scelta != 'x');  // Condizione di uscita: quando scelta è X o x
    
    return 0;  // Termina il programma con codice di uscita 0 (successo)
}
