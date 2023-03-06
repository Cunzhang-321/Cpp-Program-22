#include "class.h"

using namespace std;

PersonScore::PersonScore(char* i, char* n, int m, int e, int c) {
    i="00000000";
    n="name";
    strcpy(id,i);
    strcpy(name,n);
}

PersonScore::~PersonScore() {
    //该函数为析构函数
}

void PersonScore::GiveValue(int m, int e, int c){
    math=m;
    English=e;
    CS=c;
}

void PersonScore::Display(){
    cout<<id<<" "<<name<<" "<<math<<" "<<English<<" "<<CS<<endl;
}

int PersonScore::GetHigh(){
    int h1,h2;
    h1=(math>English)?math:English;
    h2=(CS>h1)?CS:h1;
}

int PersonScore::GetLow(){
    int l1,l2;
    l1=(math<English)?math:English;
    l2=(CS<l1)?CS:l1;
}

bool PersonScore::isMathPass(){
    if(math>=60) return true;
    else return false;
}

bool PersonScore::isEnglishPass(){
    if(English>=60) return true;
    else return false;
}

bool PersonScore::isCSPass(){
    if(CS>=60) return true;
    else return false;
}
