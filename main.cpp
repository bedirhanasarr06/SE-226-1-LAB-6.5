#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Q2
const int MAX_LENGTH=100;
bool isPalindrome(string s){
    for(int i=0; i<s.length()/2; i++){
        if(s[i]!=s[s.length()-1-i]) return false;}
    return true;}
//Q3
const int MAX_NUMBER=1000000;
int numberList[]={2,3,4,5,6,7,8,9};
bool isPrime[MAX_NUMBER+1];
int sieveOfEratosthenes(int* numbers,int n){
    int numberOfPrimes=0;
    fill_n(isPrime,n,true);

    for(int i=0; i<n; i++){
        if(isPrime[numberList[i]]){
            int num=numberList[i];

            if(num>1) numberOfPrimes++;
            for(int j=num*2; j<=MAX_NUMBER; j+=num) isPrime[j]=false;}}
    return numberOfPrimes;}
//Q4
string toLowercase(string s){
    transform(s.begin(),s.end(),s.begin(),::tolower);
    return s;}
string removeSpaces(string s){
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    return s;}
string sortString(string s){
    sort(s.begin(),s.end());
    return s;}
bool areAnagrams(string s1,string s2){
    s1=sortString(removeSpaces(toLowercase(s1)));
    s2=sortString(removeSpaces(toLowercase(s2)));
    return s1==s2;}

int main(){
//Q1
    int list1[]={0,1,2,3,4,5,6,7,8,9};
    int list2[]={5,8,11,16,17};
    int n1=sizeof(list1)/sizeof(list1[0]);
    int n2=sizeof(list2)/sizeof(list2[0]);
    int commonElements[n1<n2?n1:n2];
    int k=0;

    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(list1[i]==list2[j]){
                bool isUnique=true;
                for(int m=0; m<k; m++){
                    if(commonElements[m]==list1[i]){
                        isUnique=false;
                        break;}}
                if(isUnique)
                    commonElements[k++]=list1[i];}}}
    for(int i=0; i<k; i++)
        cout<<commonElements[i]<<" ";
    cout<<""<<endl;
//Q2
    string list[MAX_LENGTH]={"lol","pop","top","dad","joy","non","racecar","error"};
    string palindromeWords[MAX_LENGTH];
    int c=0;

    for(int i=0; i<MAX_LENGTH; i++){
        if(list[i]=="") break;
        if(isPalindrome(list[i])) palindromeWords[c++]=list[i];}

    for(int i=0; i<c; i++)
        cout<<palindromeWords[i]<<" ";
    cout<<""<<endl;
//Q3
    int length=sizeof(numberList)/sizeof(int);
    int numberOfPrimes= sieveOfEratosthenes(numberList,length);
    cout<<"Number of prime numbers is "<<numberOfPrimes<<endl;

    for(int i=2; i<=MAX_NUMBER; i++){
        if(isPrime[i])
            cout<<i<<" ";}
    cout<<""<<endl;
//Q4
    string word="listen";
    string wordList[]={"enlist","google","inlets","banana","silten"};
    int n=sizeof(wordList)/sizeof(wordList[0]);

    for(int i=0; i<n; i++){
        if(areAnagrams(word,wordList[i]))
            cout<<wordList[i]<<" ";}
    cout<<""<<endl;

    return 0;
}