#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Forward declarations for UI menu and low-level pointer utilities
int menu();
void clear_screen();
void lettura(char *);
void stampa(char *);
void inverti(char *, char *);
void maiuscolo(char *, char *);
void nospazi(char *, char *);
int numparole(char *);
void cambiacar(char *, char, char);
int ricorrenza(char *, char);

int main()
{
    int scelta;
    char frase[100];
    char frase1[100];
    char vecchio, nuovo;
    
    lettura(frase);
    do
    {
        cout << endl;
        scelta = menu();
        switch (scelta)
        {
        case 1:
            stampa(frase);
            break;
        case 2:
            inverti(frase, frase1);
            stampa(frase1);
            break;
        case 3:
            maiuscolo(frase, frase1);
            stampa(frase1);
            break;
        case 4:
            nospazi(frase, frase1);
            stampa(frase1);
            break;
        case 5:
            cout << "Word count: " << numparole(frase) << endl;
            break;
        case 6:
            cout << "Character to replace: ";
            cin >> vecchio;
            cout << "New character: ";
            cin >> nuovo;
            cambiacar(frase, vecchio, nuovo);
            break;
        case 7:
            cout << "Character to analyze: ";
            cin >> vecchio;
            cout << "The character appears " << ricorrenza(frase, vecchio) << " times." << endl;
            break;
        }
    } while (scelta != 8);
    return 0;
}

// Renders the interaction menu with boundary controls
int menu()
{
    int s;
    do
    {
        clear_screen();
        cout << " - 1 - Print String" << endl;
        cout << " - 2 - Reverse String" << endl;
        cout << " - 3 - Convert to Uppercase" << endl;
        cout << " - 4 - Remove Whitespaces" << endl;
        cout << " - 5 - Count Words" << endl;
        cout << " - 6 - Swap Character" << endl;
        cout << " - 7 - Count Character Occurrences" << endl;
        cout << " - 8 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> s;
    } while (s < 1 || s > 8);
    return (s);
}

void lettura(char *f)
{
    cout << "Enter a string: ";
    cin.getline(f, 100);
}

void stampa(char *f)
{
    cout << f;
}

// Reverses a string using double pointer positioning arithmetic
void inverti(char *f, char *f1)
{
    int j;
    int len;
    len = strlen(f);
    f1 += len - 1; // Position the destination pointer at the end of the block
    for (j = len - 1; j >= 0; j--)
    {
        *f1 = *f;
        f1--;
        f++;
    }
    *f1 = '\0'; // Append the string terminator
}

// Conversions using ASCII transformations on character sequences
void maiuscolo(char *f, char *f1)
{
    int len;
    int j;
    len = strlen(f);
    for (j = 0; j < len; j++)
    {
        if (*f >= 'a' && *f <= 'z')
            *f1 = *f - 32; // Mathematical transformation to uppercase
        else
            *f1 = *f;
        f++;
        f1++;
    }
    *f1 = '\0';
}

void nospazi(char *f, char *f1)
{
    int len;
    int j;
    len = strlen(f);
    for (j = 0; j < len; j++)
    {
        if (*f != ' ')
        {
            *f1 = *f;
            f1++;
        }
        f++;
    }
    *f1 = '\0';
}

int numparole(char *f)
{
    int nump = 0;
    while (*f != '\0')
    {
        while (*f != ' ' && *f != '\0')
            f++;
        nump++;
        while (*f == ' ')
            f++;
    }
    return (nump);
}

void cambiacar(char *f, char v, char n)
{
    while (*f != '\0')
    {
        if (*f == v)
            *f = n;
        f++;
    }
}

int ricorrenza(char *f, char c)
{
    int conta = 0;
    while (*f != '\0')
    {
        if (*f == c)
            conta++;
        f++;
    }
    return (conta);
}

// Cross-platform CLI shell terminal clearer function
void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX-compliant environment shell environment
    std::system("clear");
#endif
}
