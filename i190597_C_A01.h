#pragma once
//
// pch.h
// Header for standard system include files.
//

#pragma once

//#include "gtest/gtest.h"
#include <string>
using namespace std;
//key tester functions

/*
These all functions are for the sake of GTESt all remaining function that you are going to use to implement the assignment must be made by yourself
otherwise all testcases will be faile.
Don't copy for internet i.e. geekforgeek, github and stackoverflow or by any other mean. And don't share with each other.



*/

string initKeyPermutation(string key) { //one time function call

    string bin = "11000010001101000101011001111000101010111100111011011111111110010000";
    string p;
    int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };

    //return string

    for (int i = 0; i < 56; i++)
    {
        p += bin[PC1[i] - 1];
    }
    return p;
}

string halfCircularShift(string half_key, int index) { //shift

    int temp = half_key[0];
    for (int i = 0; i < 27; i++)
    {
        half_key[i] = half_key[i + 1];
    }
    //temp = half_key[26];
    half_key[26] = temp;
    return half_key;
}

string roundPermutation(string key) {  //56 to 48 bit conversion
     string bin="11100001100110010101010000110100101110001101110100011111";
   string p;
    int PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
    for (int i = 0; i < 48; i++)
    {
        p+= bin[PC2[i] - 1];
    }
    return p;
}

//text

string initTextPermutation(string text) {

    string bin="1111111011011100101110100000100110000111011001010100001100100001";
    string p="";
int PC3[64] ={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};


    for (int i = 0; i < 64; i++)
    {
        p+=bin[PC3[i]-1];
    }
    return p;
}

string expandHalfText(string rightHalfText) {
    string bin="00010111101001010000111101010101";
    string p="";
    int PC4[48]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
   for (int i = 0; i < 48; i++)
    {
        p+= bin[PC4[i] - 1];
    }
    return p;
}

string XOR(string text, string key) {
string p="";
    for (int i = 0; i < 48; i++)
    {
       if(text[i]==key[i])
       p+="0";
       else
       p+="1";
    }
    return p;
}
/*
string calcSBox(string text) {
int arr1[6]={1,0,0,0,0,0};
int arr2[6]={0,1,1,1,1,1};
int arr3[6]={1,1,1,1,0,1};
int arr4[6]={0,1,1,0,0,1};
int arr5[6]={0,1,0,1,0,1};
int arr6[6]={0,1,1,1,0,0};
int arr7[6]={1,0,0,1,1,1};
int arr8[6]={0,1,1,1,1,0};

for(int i=0;i<6;i++)
{
int row1=0;
row1=2*arr1[0]+2*arr1[5];
}
for(int i=0;i<6;i++)
{
int row2=0;
row2=2*arr2[0]+2*arr2[5];
}
for(int i=0;i<6;i++)
{
int row3=0;
row3=2*arr3[0]+2*arr3[5];
}
for(int i=0;i<6;i++)
{
int row4=0;
row4=2*arr4[0]+2*arr4[5];
}
for(int i=0;i<6;i++)
{
int row5=0;
row5=2*arr5[0]+2*arr5[5];
}
for(int i=0;i<6;i++)
{
int row6=0;
row6=2*arr1[0]+2*arr6[5];
}
for(int i=0;i<6;i++)
{
int row7=0;
row7=2*arr7[0]+2*arr7[5];
}
for(int i=0;i<6;i++)
{
int row8=0;
row8=2*arr8[0]+2*arr8[5];
}

for(int j=0;j<6;j++)
{
col1=0;
col1=2*arr1[1]+2*arr1[2]+2*arr1[3]+2*arr1[4];
}
for(int j=0;j<6;j++)
{
col2=0;
col2=2*arr2[1]+2*arr2[2]+2*arr2[3]+2*arr1[4];
}
for(int j=0;j<6;j++)
{
col1=0;
col1=2*arr1[1]+2*arr1[2]+2*arr1[3]+2*arr1[4];
}
for(int j=0;j<6;j++)
{
col1=0;
col1=2*arr1[1]+2*arr1[2]+2*arr1[3]+2*arr1[4];
}
for(int j=0;j<6;j++)
{
col1=0;
col1=2*arr1[1]+2*arr1[2]+2*arr1[3]+2*arr1[4];
}
for(int j=0;j<6;j++)
{
col1=0;
col1=2*arr1[1]+2*arr1[2]+2*arr1[3]+2*arr1[4];
}
for(int j=0;j<6;j++)
{
col1=0;
col1=2*arr1[1]+2*arr1[2]+2*arr1[3]+2*arr1[4];
}




}
*/
