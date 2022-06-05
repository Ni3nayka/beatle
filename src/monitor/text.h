#define size_text 22
#define size_text_message 4
#define size_text_line 21

/*const char TEXT2[size_text][size_text_message*size_text_line] PROGMEM = {
  "                                                                                    ",
  "qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!",
  "werwerw",
  "werwerw",
  "werwerw",
  "qwertqwertqwertqwert!sdfgsdfgsdt!qwertqwertqwertqwert!qwertqwertqwertqwert!         ",
  "sdfgsdfgsdfgdfsg",
  "qwertqsdfgsdfgsdfgdf!",
  "qwertqwertqwertqwert!qwdbfxdb!qwertqwertqwertqwert!",
  "qwertqwertqwertqwert!qwertqwertqwertqwert!",
  "qwert fbfdzb tqwertqwert!qwertqwertqwertqwert!",
  "qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!",
  "qwertqwertqwertqwert!qwertqwertqwertqwertqwertqwertqwert!",
  "qweertqwert!",
  "qwertqwertqwertqwert!qweqwert!",
};*/

#include <avr/pgmspace.h>
/*const char string_0[] PROGMEM = "String 0                                                                            "; // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "String 1                                                                            ";
const char string_2[] PROGMEM = "String 2  абвнрй                                ннн              шш             ееее";
const char string_3[] PROGMEM = "String 3                                                                            ";
const char string_4[] PROGMEM = "qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!";
const char string_5[] PROGMEM = "String 5                                                                            ";
const char string_6[] PROGMEM = "АбвгдежзипАбвгдежзип                                                                ";
const char string_7[] PROGMEM = "String 7                                                                            ";*/

const char string_0[]  PROGMEM = "String 0                                                                            "; // "String 0" etc are strings to store - change to suit.
const char string_1[]  PROGMEM = "aA+bB=cC+dD          Kp=Cc^c*Cd^d/Ca^a*Cb Eovr>0 reak.idet samaEovr<0 reak.ne idet  ";
const char string_2[]  PROGMEM = "Eovr=Eok-Evos        dG=-nFEovr n-count/e pri ovr F=96500 dG>0 pram.napr dG<0 obrat ";
const char string_3[]  PROGMEM = "K-E1>E2-A-okislenie  (*)-(K)Cu|Cu(No3)2)||AgNo3|Ag(A)-reak-Me  Eeds = Ea-Ek         ";
const char string_4[]  PROGMEM = "(*): Katod okislitelipH<7: 2H+2e          pH>=7:-O2+4e+2H2O    Eok>Ea-samproiz.koroz";
const char string_5[]  PROGMEM = "КЧ=8=z*2 UO2-6     X(C2O4)=CO+CO2+XO    La[]4f[5s5p]5d6s     Ak[][6s6p]5f6d7s     ";
const char string_6[]  PROGMEM = "n nomer orbit        l s=0,p=1,d=2        m -3-2-10+1+2        s 1/2 1/2 ...        ";
const char string_7[]  PROGMEM = "Karbonat.ochistka    U3O8+MnO2+H2SO4=>    UO2SO4(+..)+MnSO4+H2O?                    ";
const char string_8[]  PROGMEM = "UO2SO4+Na2CO3=>      Na[Uo2(CO3)3]+Na2SO4 Fe2(SO4)3+Na2CO3+H2O Fe(OH)3+H2CO3+Na2SO4 ";
const char string_9[]  PROGMEM = "C=gramm/0.1litr dT   n=10*C/M i=dT/nE     E=1.86 krioscopich   Const               ?";
const char string_10[] PROGMEM = "i>1-elektrolit       i=1-ne elektrolit    i<1-associat         C=C0*e^(-kt)-raspad  ";
const char string_11[] PROGMEM = "dG=dH-TdS            dH>0-reak.idet.T>>1                                            ";
const char string_12[] PROGMEM = "1-H2=2H dH1=..       2-Cl2=2Cl dH2=..     3dHobrHCl=..         1/2H2+1/2Cl2=HCl ?   ";
const char string_13[] PROGMEM = "E(H-Cl)=dH(HCl)      HCl=Cl+H             dH=E=1/2dH1+1/2dH2-  -dH3                 ";
const char string_14[] PROGMEM = "CM=m/M*V             Cm=m(pastv.vesh)/    /M(pastv)*m(rastvoritw=m(v-va)/m(r-ra)    ";
const char string_15[] PROGMEM = "E=E0+(RT/F)1/|z|ln(X)E=E0+0.059*lg(X)/|z| X=Aok/Avos                                ";
const char string_16[] PROGMEM = "I=1/2*sum(Ci*Zi)1..n Z=..=>y+-=..         A=C*y+-=..                                ";
const char string_17[] PROGMEM = "Vodorod-svyazi           =O..HO-          CH3-C     C-CH3          -OH..O=          ";
const char string_18[] PROGMEM = "Razbavl.Ostfald      Kg=a*a*C/(1-a)       A<<1=>a=sqrt(Kg/C)                        ";
const char string_19[] PROGMEM = "1s2 2s2 2p6 3s2 3p6  4s2 3d10 4p6 5s2 4d10 5p6 6s2 4f14 5d10   6p6 7s2 5f14 6d10 7p6";
const char string_20[] PROGMEM = "Arenius:             K=A*e(-Ea/RT)        k-const skorost                           ";
const char string_21[] PROGMEM = "Gessa:dHpramaya=     =dHobratnaya reakcia Debay-Hugens:        A=yC                 ";

const char *const TEXT[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10, string_11, string_12, string_13, string_14, string_15, string_16, string_17, string_18, string_19, string_20, string_21};

//                   |                    |                    |                    |
