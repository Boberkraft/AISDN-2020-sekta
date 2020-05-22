◀  
Login: 182619


Tab: WS Cmt 
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174


#include <iostream>


// inline long long zamien_od_konca_na_od_poczatku(long long n, long long ilosc_ludzi) {
//     if (n >= 0) {
//         return n;
//     }
//     return ilosc_ludzi + n + 1;
// }

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

    // std::cout << ilosc_ludzi << std::endl;
    // std::cout << k << std::endl;
    // exit(0);
    unsigned long long pierwszy = 1;

    unsigned long long przerwa_pomiedzy_ludzmi = 1;
    unsigned long long umarlo = 0;

    // bool fast = ilosc_ludzi == k;
    while (ilosc_ludzi >= 0) {
        
        // std::cout << umarlo << " " << umarlo + ilosc_ludzi/2 << std::endl;
        // std::cout << k - umarlo  << " " << ilosc_ludzi/2 << std::endl;
        if (k - umarlo <= ilosc_ludzi/2) {
            unsigned long long ile_jeszcze_musi_umrzec = k - umarlo;
            return pierwszy + przerwa_pomiedzy_ludzmi * (ile_jeszcze_musi_umrzec * 2 - 1);

            
            // std::cout << "Jeszcze musi umrzec: " << ile_jeszcze_musi_umrzec << std::endl;


            // long long umrze_za_nim = (pierwszy + (przerwa_pomiedzy_ludzmi * (ile_jeszcze_musi_umrzec - 1)));
            // long long umrze_przed_nim = (pierwszy + (przerwa_pomiedzy_ludzmi * (ile_jeszcze_musi_umrzec + 1 - 1)));
            // std::cout << umrze_za_nim << "-" << umrze_przed_nim << std::endl;
            // std::cout << ":";
            // std::cout << (umrze_za_nim + umrze_przed_nim) / 2  << std::endl;
            // return (umrze_za_nim + umrze_przed_nim) / 2 ;

            // std::cout << (pierwszy ) + przerwa_pomiedzy_ludzmi  << std::endl;
            // std::cout << ile_jeszcze_musi_umrzec - przerwa_pomiedzy_ludzmi/2 << std::endl;
            // std::cout << (pierwszy ) + przerwa_pomiedzy_ludzmi * ile_jeszcze_musi_umrzec - przerwa_pomiedzy_ludzmi/2  << std::endl;
            
       
        }

        przerwa_pomiedzy_ludzmi *= 2;
        bool nieparzyscie = ilosc_ludzi % 2;
        ilosc_ludzi = ilosc_ludzi / 2;

        umarlo += ilosc_ludzi;

            // std::cout << pierwszy  << std::endl;
            // std::cout << przerwa_pomiedzy_ludzmi  << std::endl << std::endl;
        
        // std::cout << ":" << pierwszy  << std::endl;
        if (nieparzyscie) {
            umarlo += 1;
            pierwszy += przerwa_pomiedzy_ludzmi;
        }
    }

    return 999;
    // std::cout << "err";
    // exit(0);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // setvbuf(stdin, NULL, _IOFBF, 16384);
    long long ilosc_testow = get_int();;

    long long ilosc_ludzi;
    long long ktory;
    for (long i = 0; i < ilosc_testow; i++) {
        ilosc_ludzi = get_int();
        ktory = get_int();
        // scanf("%lld %lld", &ilosc_ludzi, &ktory);
        unsigned long long wynik = oblicz(ilosc_ludzi, ktory);
        // if (wynik == -6911526650887436131) {
        //     std::cout << ilosc_ludzi << " " << ktory;
        //     exit(0);
        // }
        printf("%llu\n", wynik);
    }
}
    // std::cout << oblicz(12, 6); //12
    // std::cout << "\n\n";
    // std::cout << oblicz(12, 6+1); //3
    // std::cout << "\n\n";
    // std::cout << oblicz(12, 9); // 11
    // std::cout << "\n\n";
    // std::cout << oblicz(12, 9+1); // 5
    // std::cout << "\n\n";
    // std::cout << oblicz(12, 9+2); // 1
    // std::cout << "\n\n";
    // std::cout << oblicz(4, 4); // 1
    // std::cout << "\n\n";
    // std::cout << oblicz(5, zamien_od_konca_na_od_poczatku(-2, 5)); // 5



    // std::cout << "\n\n";
    // std::cout << oblicz(6, 5); // 1

    // std::cout << "\n\n";
    // std::cout << oblicz(7591391751727473782, 3481242367959221983); // 1
    // return 0;
// }

/**

1 2 3 4 5 6 7 8 9 10
1 . . . 5 . . . 9 ..
pierwszy = 1

przerwa = 3

czy umrze 7?
muszę zobaczyć czy 7, to wielokrotność 1 + (3)

7 - pierwszy mod 3
6 mod 3 = 0

czy umrze 8?
7 mod 3 = 1

czy umrze 9?
8 mod 3 = 2

czy umrze 10?
9 mod 3 = 0
**/
