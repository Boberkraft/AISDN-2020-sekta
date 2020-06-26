#include <iostream>

#define BUFFER_SIZE (1024*32)
char mybuffer[BUFFER_SIZE+1] = {0};
unsigned int mybuffer_pos = BUFFER_SIZE;

void read_ahead() {
    if (mybuffer_pos + (64/2) > BUFFER_SIZE) {
        memmove(mybuffer, mybuffer+mybuffer_pos, BUFFER_SIZE-mybuffer_pos);
        fread(mybuffer + BUFFER_SIZE - mybuffer_pos, 1, BUFFER_SIZE - (BUFFER_SIZE - mybuffer_pos), stdin);
        mybuffer_pos = 0;
    }
}

long long get_int() {
    read_ahead();
    long long int x = 0;
    bool neg = false;

    while (mybuffer[mybuffer_pos] == ' ' || mybuffer[mybuffer_pos] == '\n')
        ++mybuffer_pos;

    if (mybuffer[mybuffer_pos] == '-') {
        neg = true;
        ++mybuffer_pos;
    }

    while (mybuffer[mybuffer_pos] != ' ' && mybuffer[mybuffer_pos] != '\n') {
        x *= 10;
        x += mybuffer[mybuffer_pos] - '0';
        ++mybuffer_pos;
    }        

    return neg ? -x : x;
}

unsigned long long oblicz(long long ilosc_ludzi, long long k) {
    if (k < 0) {
        k = ilosc_ludzi + k  + 1;
    }

    unsigned long long pierwszy = 1;

    unsigned long long przerwa_pomiedzy_ludzmi = 1;
    unsigned long long umarlo = 0;

    while (ilosc_ludzi >= 0) {
        
        // std::cout << umarlo << " " << umarlo + ilosc_ludzi/2 << std::endl;
        if (k - umarlo <= ilosc_ludzi/2) {
            unsigned long long ile_jeszcze_musi_umrzec = k - umarlo;
            return pierwszy + przerwa_pomiedzy_ludzmi * (ile_jeszcze_musi_umrzec * 2 - 1);
            // std::cout << "Jeszcze musi umrzec: " << ile_jeszcze_musi_umrzec << std::endl;

            // long long umrze_za_nim = (pierwszy + (przerwa_pomiedzy_ludzmi * (ile_jeszcze_musi_umrzec - 1)));
            // long long umrze_przed_nim = (pierwszy + (przerwa_pomiedzy_ludzmi * (ile_jeszcze_musi_umrzec + 1 - 1)));
            // return (umrze_za_nim + umrze_przed_nim) / 2 ;
        }

        przerwa_pomiedzy_ludzmi *= 2;
        bool nieparzyscie = ilosc_ludzi % 2;
        ilosc_ludzi = ilosc_ludzi / 2;

        umarlo += ilosc_ludzi;

        if (nieparzyscie) {
            umarlo += 1;
            pierwszy += przerwa_pomiedzy_ludzmi;
        }
    }

    return 999;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long ilosc_testow = get_int();;

    long long ilosc_ludzi;
    long long ktory;
    for (long i = 0; i < ilosc_testow; i++) {
        ilosc_ludzi = get_int();
        ktory = get_int();
        unsigned long long wynik = oblicz(ilosc_ludzi, ktory);
        printf("%llu\n", wynik);
    }
}
