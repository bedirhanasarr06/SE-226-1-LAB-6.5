import math
import random

#Q1
def common_integers(list1,list2):
    return [n for n in list1 if n in list2]

list1=[0,1,2,3,4,5,6,7,8,9]
list2=[5,8,11,16,17]
list3=common_integers(list1,list2)
print(list3)
#Q2
def palindrome_words(list):
    palindrome_words=[]
    for word in list:
        if word==word[::-1]:
            palindrome_words.append(word)
    return palindrome_words

list=["lol","pop","top","dad","joy","non","racecar","error"]
palindrome_words=palindrome_words(list)
print(palindrome_words)
#Q3
def prime_numbers(list):
    max_number=max(list)
    sieve=[True]*(max_number+1)
    sieve[0]=sieve[1]=False
    prime_numbers=[]

    for n in list:
        if sieve[n]:
            prime_numbers.append(n)
            for m in range(n*2,max_number+1,n):
                sieve[m]=False
    return prime_numbers

number_list=[1,2,3,4,5,6,7,8,9]
prime_list=prime_numbers(number_list)
print(prime_list)
#Q4
def anagrams(word,word_list):
    word_chars=sorted(word.lower().replace(" ",""))
    anagrams_list=[]
    for w in word_list:
        if sorted(w.lower().replace(" ",""))==word_chars:
            anagrams_list.append(w)
    return anagrams_list

word="listen"
word_list=["enlist","google","inlets","banana","silten"]
anagrams_list=anagrams(word,word_list)
print(anagrams_list)