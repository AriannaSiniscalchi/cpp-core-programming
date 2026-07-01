#include<iostream>
#include<cstring>

using namespace std;

// Structured data records for student directories
struct STUDENTE{
    int matricola;
    char nome[20];
    char cognome[30];
};

// Structured records for academic assessment outcomes
struct ESAME{
    int matricola;
    char nome_esame[30];
    int voto;
};

int main(){
    STUDENTE studenti[3];
    ESAME esami[7];
    int somma_voti;
    
    int i, j;
    // Database instantiation loop for Student records
    for (i = 0; i < 3; i++)
    {
        cout << endl << "Enter Student ID (Matricola), First Name, Last Name:\n";
        bool check;
        // Strict relational database validation: Enforce primary key uniqueness
        do {
            check = false;
            cin >> studenti[i].matricola;
            for(int j = 0; j < i; j++) {
                if(studenti[i].matricola == studenti[j].matricola) {
                    cout << endl << "Error: Student ID already exists in system records." << endl;
                    check = true;
                }
            }
        } while(check);
        cin.ignore(100, '\n'); // Clear residual input stream characters
        cin.getline(studenti[i].nome, 100, '\n');
        cin.getline(studenti[i].cognome, 100, '\n');
    }
    
    cout << endl;
    cout << "Populating course grade assessment database records...";
    cout << endl << endl;
    
    // Database instantiation loop for Exam evaluations
    for(int i = 0; i < 7; i++){
        cout << "Enter Student ID (Matricola): ";
        cin >> esami[i].matricola;
        cin.ignore();
        
        cout << "Enter Exam Title (" << (i+1) << " record entry): ";
        cin.getline(esami[i].nome_esame, 30);
        
        cout << "Enter Grade: ";
        cin >> esami[i].voto;
    }
    
    cout << endl << endl;

    // Relational Database Querying Simulation using multi-nested iterative loops
    for(int i = 0; i < 3; i++){
        cout << endl << endl;
        somma_voti = 0;
        for(int j = 0; j < 7; j++){
            // Join condition matching key values
            if(studenti[i].matricola == esami[j].matricola){
                somma_voti = somma_voti + esami[j].voto;
            }
        }
        cout << "Total grade score for " << studenti[i].nome << " " << studenti[i].cognome 
             << " [ID: " << studenti[i].matricola << "] = " << somma_voti << endl << endl;
    }

    return 0;
}
