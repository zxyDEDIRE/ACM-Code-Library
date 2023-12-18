    #include<bits/stdc++.h>
    using namespace std;
    int cases;

    int main(){
        system("g++ j.cpp -o AC");
        system("g++ jj.cpp -o WA");
        system("g++ make.cpp -o make");
        while(1){
            printf("The result of No. %d Case is:  ",++cases);
            system("./make > a.in");
            system("./AC < a.in > AC.out");
            system("./WA < a.in > WA.out");
            if(system("diff AC.out WA.out")){
                puts("Wrong Answer\n");
                return 0;
            }
            puts("Accepted");
        }
        return 0;
    }