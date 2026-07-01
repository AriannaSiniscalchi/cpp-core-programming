#include <iostream>
#include <cstring>

using namespace std;

// ==========================================
// 1. DATA STRUCTURE DEFINITIONS
// ==========================================
struct VENDITA {
    char codice_scontrino[15];
    char data[11];
    char codice_prodotto[14];
    char categoria[31];
    char punto_vendita[51];
    int quantita;
    int ricavo;
};

struct NODO {
    VENDITA dato;
    NODO *next;
};

// Helper function to insert a node at the head of the list
int ins_testa(NODO * &head, VENDITA dato) {
    NODO *t = new NODO;
    if (t == NULL) {
        cout << "Allocation Error";
        return -1;
    }
    t->dato = dato;
    t->next = head;
    head = t;
    return 0;
}

// ==========================================
// 2. AUXILIARY SUPPORT FUNCTIONS
// ==========================================

// Checks if the product code is present in the CodiciProdotti array
int cerca_prodotto(char codice[], char *CodiciProdotti[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(codice, CodiciProdotti[i]) == 0)
            return i;
    }
    return -1;
}

// Function to calculate counts related to product sales revenue
void CalcolaConteggiVendite(NODO *lista, char *CodiciProdotti[], int size, int conteggi[], bool isLista1) {
    NODO *p = lista;
    int pos;

    // Initialize the count array elements to zero
    for (int i = 0; i < size; i++) {
        conteggi[i] = 0;
    }

    while (p != NULL) {
        if (isLista1) {
            // For lista1 (online): increment count if revenue is strictly greater than 100 euros
            if (p->dato.ricavo > 100) {
                pos = cerca_prodotto(p->dato.codice_prodotto, CodiciProdotti, size);
                if (pos >= 0)
                    conteggi[pos]++;
            }
        } else {
            // For lista2 (in-store): increment count if revenue is less than or equal to 100 euros
            if (p->dato.ricavo <= 100) {
                pos = cerca_prodotto(p->dato.codice_prodotto, CodiciProdotti, size);
                if (pos >= 0)
                    conteggi[pos]++;
            }
        }
        p = p->next;
    }
}

// Second scan over lista1 to perform selective copying
int CopiaSeProdottoFlop(NODO *lista1, char *CodiciProdotti[], int size, int conteggioL1[], int conteggioL2[], NODO * &listaOut) {
    NODO *p = lista1;
    int pos;

    while (p != NULL) {
        // Criterion 3: Revenue must be strictly greater than 100 euros
        if (p->dato.ricavo > 100) {
            pos = cerca_prodotto(p->dato.codice_prodotto, CodiciProdotti, size);
            // Criterion 2: Count in lista1 must be strictly lower than count in lista2
            if (pos >= 0 && conteggioL1[pos] < conteggioL2[pos]) {
                if (ins_testa(listaOut, p->dato) == -1)
                    return -1; // Dynamic allocation failure error
            }
        }
        p = p->next;
    }
    return 0;
}

// ==========================================
// 3. MAIN REQUIRED COMPONENT FUNCTION
// ==========================================
NODO* SelezionaProdottiFlop(NODO *lista1, NODO *lista2, char *CodiciProdotti[], int size) {
    if (size < 1 || CodiciProdotti == NULL)
        return NULL;

    // Dynamic allocation of temporary support tracking arrays
    int *conteggioL1 = new int[size];
    int *conteggioL2 = new int[size];
    
    if (conteggioL1 == NULL || conteggioL2 == NULL) {
        delete[] conteggioL1;
        delete[] conteggioL2;
        return NULL;
    }

    NODO *listaOut = NULL;

    // (1) SCANNING AND COUNTING (1st scan of lista1 and single unique scan of lista2)
    CalcolaConteggiVendite(lista1, CodiciProdotti, size, conteggioL1, true);
    CalcolaConteggiVendite(lista2, CodiciProdotti, size, conteggioL2, false);

    // (2 & 3) FILTERING AND COPYING (2nd target scan of lista1)
    if (CopiaSeProdottoFlop(lista1, CodiciProdotti, size, conteggioL1, conteggioL2, listaOut) == -1) {
        // Error handling: Clean up and deallocate partial list and local arrays
        while (listaOut != NULL) {
            NODO *temp = listaOut;
            listaOut = listaOut->next;
            delete temp;
        }
        delete[] conteggioL1;
        delete[] conteggioL2;
        return NULL;
    }

    // Final resource cleanup of local auxiliary tracking memory arrays
    delete[] conteggioL1;
    delete[] conteggioL2;

    return listaOut;
}
