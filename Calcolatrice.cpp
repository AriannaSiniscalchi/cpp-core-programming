// Inclusion of required standard libraries
#include <iostream>     // For standard input/output streams (cin, cout)
#include <iomanip>      // For output stream formatting (setprecision)
#include <limits>       // For data type limits properties

using namespace std;    // Allows using standard names without the std:: prefix

int main() {
    // Variable declaration for the three input integers
    int n1, n2, n3;
    // Variable to store the user's menu selection
    char scelta;
    
    // Loop to read and validate the three input values
    do {
        // Prompt the user to enter three integers
        cout << "Enter three integer values between 1 and 100: ";
        // Read the three values from the standard input
        cin >> n1 >> n2 >> n3;
    } while (n1 < 1 || n1 > 100 || n2 < 1 || n2 > 100 || n3 < 1 || n3 > 100);
    // The loop continues as long as at least one value falls outside the 1-100 range
    
    // Main application loop; runs until the user chooses to exit
    do {
        // Display the available arithmetic operations menu
        cout << "\n=== OPERATIONS MENU ===" << endl;
        cout << "A - Sum of n1, n2, and n3" << endl;                    // Option A: Addition
        cout << "B - Product of n1 and n2" << endl;                     // Option B: Multiplication
        cout << "C - Subtraction of n1 from n3" << endl;                // Option C: Subtraction
        cout << "D - Division of n1 by n2 (double precision result)" << endl; // Option D: Division
        cout << "X - Exit program" << endl;                             // Option X: Exit
        cout << "Choice: ";                                             // Input prompt
        
        // Read the character chosen by the user
        cin >> scelta;
        
        // Switch structure to execute the operation corresponding to the choice
        switch(scelta) {
            // Case A: Addition of all three numbers (accepts both uppercase and lowercase)
            case 'A':
            case 'a':
                // Print the mathematical expression and its result
                cout << "Operation: " << n1 << " + " << n2 << " + " << n3 << " = " 
                     << (n1 + n2 + n3) << endl;
                break;  // Break out of the switch statement
                
            // Case B: Product of n1 and n2 (accepts both uppercase and lowercase)
            case 'B':
            case 'b':
                // Print the mathematical expression and its result
                cout << "Operation: " << n1 << " * " << n2 << " = " 
                     << (n1 * n2) << endl;
                break;  // Break out of the switch statement
                
            // Case C: Subtraction of n1 from n3 (accepts both uppercase and lowercase)
            case 'C':
            case 'c':
                // Print the mathematical expression and its result
                cout << "Operation: " << n3 << " - " << n1 << " = " 
                     << (n3 - n1) << endl;
                break;  // Break out of the switch statement
                
            // Case D: Division of n1 by n2 (accepts both uppercase and lowercase)
            case 'D':
            case 'd':
                // Safe check to prevent division-by-zero runtime errors
                if (n2 != 0) {
                    // Set fixed-point floating-point formatting
                    cout << fixed << setprecision(2);
                    // Explicitly cast n1 to double to ensure floating-point division
                    cout << "Operation: " << n1 << " / " << n2 << " = " 
                         << (static_cast<double>(n1) / n2) << endl;
                } else {
                    // Error message displayed if division by zero is attempted
                    cout << "Error: Division by zero is undefined!" << endl;
                }
                break;  // Break out of the switch statement
                
            // Case X: Terminates the application (accepts both uppercase and lowercase)
            case 'X':
            case 'x':
                // Exit confirmation message
                cout << "Exiting the program." << endl;
                break;  // Break out of the switch statement
                
            // Default case: Handles all invalid inputs gracefully
            default:
                // No action taken; invalid characters are safely ignored.
                // The menu will re-render on the next iteration loop.
                break;  // Break out of the switch statement
        }
        
    } while (scelta != 'X' && scelta != 'x');  // Exit condition: Loop stops when selection is X/x
    
    return 0;  // Terminate application with exit code 0 (Success)
}
