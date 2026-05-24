#include<iostream>
#include<cstring>

using namespace std;

struct STUDENTE{
	int matricola;
	char nome[20];
	char cognome[30];
};

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
    for (i = 0; i < 3; i++)
    {
        cout << endl << "Inserisci Matricola, Nome, Cognome\n";
        bool check;
        do {
            check = false;
            cin >> studenti[i].matricola;
            for(int j = 0; j < i; j++) {
                if(studenti[i].matricola == studenti[j].matricola) {
                    cout << endl << "Matricola già presente" << endl;
                    check = true;
                }
            }
        } while(check);
        cin.ignore(100, '\n');
        cin.getline(studenti[i].nome, 100, '\n');
        cin.getline(studenti[i].cognome, 100, '\n');
    }
	
	cout << endl;
	cout << "Ora si chiederanno i voti degli studenti appartenenti a questo corso";
	cout << endl << endl;
	
	for(int i = 0; i < 7; i++){
		cout << "Inserisci la matricola dello studente: ";
		cin >> esami[i].matricola;
		cin.ignore();
		
		cout << "Inserisci l'esame di questo studente (" << (i+1) << " esame segnato nell'array): ";
		cin.getline(esami[i].nome_esame, 30);
		
		cout << "Inserisci il voto dello studente: ";
		cin >> esami[i].voto;
	}
	
	cout << endl << endl;

	for(int i = 0; i < 3; i++){
		cout << endl << endl;
		somma_voti = 0;
		for(int j = 0; j < 7; j++){
			if(studenti[i].matricola == esami[j].matricola){
				somma_voti = somma_voti + esami[j].voto;
			}
		}
		cout << "somma dei voti di " << studenti[i].nome << ", " << studenti[i].cognome << ", matricola -> " << studenti[i].matricola << " = " << somma_voti << endl << endl;
	}

	return 0;
}

