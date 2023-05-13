#define and &&
#define or ||
#define xor ^
int counter;
void rout(){
 counter  =  counter  + 1;
};
struct Human{
int age;
double weight;
int gender;
};
struct Human People[ counter ];
struct Human HumanConstructor(int age, double weight, int gender){
struct Human Result;
 Result . age  =  age ;
 Result . weight  =  weight ;
 Result . gender  =  gender ;
return  Result ;
};
struct Human Bob;
struct Human Alice;
struct Human Charlie;
struct Human Dave;
int underAge;
int countUnderage(struct Human peopleArray[]){
int total = 0;
for (int  i = 1; i < (sizeof( peopleArray ) / sizeof(struct Human)); i++){
if ( peopleArray [ i -1  ]. age  <= 16){
 total  =  total  + 1;
};
};
return  total ;
};
void simulateAging(struct Human person, int targetAge){
while( person . age  <  targetAge ){
 person . age  =  person . age  + 1;
 person . weight  =  person . weight  * 1.050000;
};
};
void agePeople(struct Human peopleArray[], int targetAge){
for (int  i = 1; i < (sizeof( peopleArray ) / sizeof(struct Human)); i++){
simulateAging( peopleArray [ i -1  ],  targetAge );
};
};
int arithmeticsDemo(int a, int b, int c, int d){
return  a  -  b  +  c  %  d  * 4 * 2 /  a ;
};
int mathDemo;
int gcd(int a, int b){
if ( b  == 0){
return  a ;
};
return gcd( b ,  a  %  b );
};
int gcdDemo;
int isBetween(int a, int leftb, int rightb){
if ( a  >=  leftb  and  a  <=  rightb ){
return 1;
} else {
return 0;
};
};
int booleanDemo;
int main() {
counter = 0;
Human Bob = HumanConstructor(16, 89.199997, 1);
Human Alice = HumanConstructor(14, 72.300003, 0);
Human Charlie = HumanConstructor(15, 81.500000, 0);
Human Dave = HumanConstructor(17, 90.099998, 1);
 People [0] =  Bob ;
 People [1] =  Alice ;
 People [2] =  Charlie ;
 People [3] =  Dave ;
underAge = 0;
 underAge  = countUnderage( People );
agePeople( People , 80);
mathDemo = arithmeticsDemo(5, 3, 29, 17);
gcdDemo = gcd(150, 100);
booleanDemo = isBetween(4, 2, 8);
}

