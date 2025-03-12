//to be continued
//not ready yet
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int fillCells(string hex) {
    int size=hex.size(),base=1,dec_val=0;
    for (int i = size - 1; i >= 0; i--) {
        // If character lies in '0'-'9', so we will convert it to integral 0-9 by subtracting 48 from ASCII value
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec_val += (int(hex[i]) - 48) * base;

            // incrementing base by power
            base *= 16;
        }

            // If character lies in 'A'-'F' , so we will convert it to integral 10 - 15 by subtracting 55 from ASCII value
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec_val += (int(hex[i]) - 55) * base;

            // Incrementing base by power
            base *= 16;
        }
    }
    return dec_val;
}
int main() {
    string k ;
    cout<<fillCells("A3");
    return 0;
}
