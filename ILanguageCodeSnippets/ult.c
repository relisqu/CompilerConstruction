#define and &
#define or |
#define xor ^
int main() {
    struct Human{
        int age;
        double weight;
        int gender;
    };
    struct Human HumanConstructor(int age, double weight, int gender){
        struct Human Result;
        Result . age  =  age ;
        Result . weight  =  weight ;
        Result . gender  =  gender ;
        return  Result ;
    }
    ;
    struct Human Bob = HumanConstructor(16, 89.199997, 1);
    struct Human Alice = HumanConstructor(14, 72.300003, 0);
    struct Human Charlie = HumanConstructor(15, 81.500000, 0);
    struct Human Dave = HumanConstructor(17, 90.099998, 1);
    struct Human People[4];
    People [1] =  Bob ;
    People [2] =  Alice ;
    People [3] =  Charlie ;
    People [3] =  Dave ;
    int underAge = 0;
    int countUnderage(struct Human peopleArray[]){
        int total = 0;
        for (int  i = 1; i < (sizeof( peopleArray ) / sizeof(struct Human)); i++){
            if ( peopleArray [ i ]. age  <= 16){
                total  =  total  + 1;
            }
            ;
        }
        ;
        return  total ;
    }
    ;
    underAge  = countUnderage( People );
    void simulateAging(struct Human person, int targetAge){
        while( person . age  <  targetAge ){
            person . age  =  person . age  + 1;
            person . weight  =  person . weight  * 1.050000;
        }
        ;
    }
    ;
    void agePeople(struct Human peopleArray[], int targetAge){
        for (int  i = 1; i < (sizeof( peopleArray ) / sizeof(struct Human)); i++){
            simulateAging( peopleArray [ i ],  targetAge );
        }
        ;
    }
    ;
    agePeople( People , 80);
    int arithmeticsDemo(int a, int b, int c, int d){
        return  a  -  b  +  c  %  d  * 4 * 2 /  a ;
    }
    ;
    int mathDemo = arithmeticsDemo(5, 3, 29, 17);
    int gcd(int a, int b){
        if ( b  == 0){
            return  a ;
        }
        ;
        return gcd( b ,  a  %  b );
    }
    ;
    int gcdDemo = gcd(150, 100);
    int isBetween(int a, int leftb, int rightb){
        if ( a  >=  leftb  and  a  <=  rightb ){
            return 1;
        }
        else {
            return 0;
        }
        ;
    }
    ;
    int booleanDemo = isBetween(4, 2, 8);
}