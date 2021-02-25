#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class obrazek {
    public:
    ifstream fileIn;
    
    string obr [20] [20];
    void run();
    	bool rewers(string obraz [20] [20]);
};

void obrazek::run() {
    fileIn.open("dane_obrazki.txt");
    string linijka;
    string skipL;
    for(int i = 0; i < 200; i++) {
		for(int j = 0; j < 20; j++) {
            fileIn >> linijka;
            for(int l = 0 ; l < 20; l++) {
                obr[j][l] = linijka[l];
            }
        }
        fileIn >> skipL;
        
        if(rewers(obr)) {
            cout << endl << "Jest rewersem \n";
        } else {
            cout << endl << "Nie jest rewersem X\n";
        }
    }
}

bool obrazek::rewers(string obraz [20] [20]) {
    int czarnyPixel = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(obraz[i][j] == "0") {
                czarnyPixel++;
            }
        }
    }
    if(czarnyPixel > (20 * 20 / 2)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    obrazek IsReverse;
    IsReverse.run();
    return 0;
}
