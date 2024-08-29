#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// Function to increment and clamp key pointer
inline void incrementKeyPointer(int& keyPtr, const string& key) {
    keyPtr++;
    if (keyPtr >= key.length()) keyPtr = 0;
}

// Function to skip non-alphabetic characters and print them
inline void skipNonAlpha(const string& str, int& keyPtr) {
    while (!isalpha(str[keyPtr])) {
        cout << str[keyPtr];
        incrementKeyPointer(keyPtr, str);
    }
}

int main() {
    string key, received;
    string opcode;
    
    // Read the key
    getline(cin, key);
    
    while (cin >> opcode) {
        cin.ignore(); // Ignore the newline after opcode
        
        // Read the input string
        getline(cin, received);
        
        if (opcode == 'D') {
            // Decoding process
            int i = 3, code = 0;
            for (char r : received) {
                if (!isalpha(r)) continue;
                code += (islower(r) << (i - 1));
                
                if (i > 0) {
                    i--;
                    continue;
                }
                
                if (islower(r)) code++;
                i = 3;
                
                if (code == 10) cout << '-';
                else if (code == 11) cout << ',';
                else cout << code;
                
                code = 0;
            }
        } else {
            // Encoding process
            int keyPtr = 0;
            
            for (char r : received) {
                int code = 0;
                
                if (r == '-') code = 10;
                else if (r == ',') code = 11;
                else code = r - '0';
                for (int shift = 3; shift >= 0; shift--) {
                    skipNonAlpha(key, keyPtr);
                    if (code & (1 << shift))
                        cout << (char)tolower(key[keyPtr]);
                    else
                        cout << (char)toupper(key[keyPtr]);
                    incrementKeyPointer(keyPtr, key);
                }
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}
