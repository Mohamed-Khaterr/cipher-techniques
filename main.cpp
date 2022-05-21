#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<bits/stdc++.h>


using namespace std;

map<int,int> keyMap;

void setPermutationOrder(string key){
    // Add the permutation order into map
    for(int i=0; i < key.length(); i++){
        keyMap[key[i]] = i;
    }
}

// Global variable declaration:
char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//Caeser Cipher
void caeser_encrypt();
void caeser_decrypt();

//Poly alphabetic Cipher
void poly_encrypt();
void poly_decrypt();


// Transposition Cipher
void transposition_encrypt();

int main(){

    /* Cipher Techniques */

    cout<<"Choose in Techniques: \n 1.Caeser Cipher \n 2.Poly Alphabetic \n 3.Transposition"<<endl;


    int tech;
    cout<< "Enter number of Techniques: "; cin>>tech;

    int method;

    if(tech == 1){
        cout<<"Choose in method: \n 1.Encrypt \n 2.Decrypt"<<endl;
        cout<< "Enter number of method: "; cin>>method;

        if(method == 1){
            caeser_encrypt();

        }else if(method == 2){
            caeser_decrypt();

        }else{
            cout<<"Error**: Please Enter Correct Number!"<<endl;
        }

    }else if(tech == 2){
        cout<<"Choose in method: \n 1.Encrypt \n 2.Decrypt"<<endl;
        cout<< "Enter number of method: "; cin>>method;
        if(method == 1){
            poly_encrypt();

        }else if(method == 2){
            poly_decrypt();

        }else{
            cout<<"Error**: Please Enter Correct Number!"<<endl;
        }
    }else if (tech == 3){
        transposition_encrypt();
    }else{
        cout<<"Error**: Please Enter Correct Number!"<<endl;
    }

    return 0;
}

// hello
// key = 3
void caeser_encrypt(){
    cout<<"\n Caeser Cipher (Encrypt) \n"<<endl;
    string message;
    cout<< "Enter the message: "; cin>>message;

    int key;
    cout<< "Enter the key: "; cin>>key;

    //convert string into array of char
    char charMessage[message.length()];
    strcpy(charMessage, message.c_str());

    //get length of message
    int msgLength = sizeof(charMessage)/sizeof(*charMessage);

    string C;

    for(int i = 0; i < msgLength; i++){
        int P = distance(alphabet, find(alphabet, alphabet + 26, charMessage[i]));

        int index = (P + key)%26;
        C += alphabet[index];
    }

    cout<<"Cipher Text is:  " <<C<<endl;
}

// khoor
// key = 3
void caeser_decrypt(){
    cout<<"\n Caeser Cipher (Decrypt)\n"<<endl;
    string message;
    cout<< "Enter the message: "; cin>>message;

    int key;
    cout<< "Enter the key: "; cin>>key;

    //convert string into array of char
    char charMessage[message.length()];
    strcpy(charMessage, message.c_str());

    //get length of message
    int msgLength = sizeof(charMessage)/sizeof(*charMessage);

    string P;

    for(int i = 0; i < msgLength; i++){
        //get the index of message letter in message
        int C = distance(alphabet, find(alphabet, alphabet + 26, charMessage[i]));

        int index = ((C - key)%26);
        P += alphabet[index];
    }

    cout<<"Plain Text is:  " <<P<<endl;
}

//--------------------------------------------------------------------------------
// hello
// key = meme
void poly_encrypt(){
    cout<<"\n Poly Alphabetic Cipher (Encrypt)\n"<<endl;

    string message;
    cout<< "Enter the message: "; cin>>message;

    string key;
    cout<< "Enter the key: "; cin>>key;

    //convert string into array of char
    char charMessage[message.length()];
    strcpy(charMessage, message.c_str());

    //get length of message
    int msgLength = sizeof(charMessage)/sizeof(*charMessage);

    char charKey[key.length()];
    strcpy(charKey, key.c_str());

    int keyLength = sizeof(charKey)/sizeof(*charKey);


    char pt[msgLength];

    int count = 0;
    for(int i = 0; i < msgLength; i++){
        if(count == keyLength){
            count = 0;
        }

        pt[i] = charKey[count];

        count ++;
    }

    string C;
    for(int i = 0; i < msgLength; i++){
        //get the index of letter in message
        int P = distance(alphabet, find(alphabet, alphabet + 26, charMessage[i]));
        //get the index of letter in key
        int k = distance(alphabet, find(alphabet, alphabet + 26, pt[i]));

        //calculate cipher text
        int index = (P + k)%26;
        C += alphabet[index];
    }

    cout<<"Cipher Text is:  " <<C<<endl;

}

// tixpa
// key = meme
void poly_decrypt(){
    cout<<"\n Poly Alphabetic Cipher (Decrypt)\n"<<endl;

    string message;
    cout<< "Enter the message: "; cin>>message;

    string key;
    cout<< "Enter the key: "; cin>>key;

    //convert string into array of char
    char charMessage[message.length()];
    strcpy(charMessage, message.c_str());

    //get length of message
    int msgLength = sizeof(charMessage)/sizeof(*charMessage);

    char charKey[key.length()];
    strcpy(charKey, key.c_str());

    int keyLength = sizeof(charKey)/sizeof(*charKey);


    char pt[msgLength];

    int count = 0;
    for(int i = 0; i < msgLength; i++){
        if(count == keyLength){
            count = 0;
        }

        pt[i] = charKey[count];

        count ++;
    }

    string P;
    for(int i = 0; i < msgLength; i++){
        //get the index of letter in message
        int C = distance(alphabet, find(alphabet, alphabet + 26, charMessage[i]));
        //get the index of letter in charKey
        int k = distance(alphabet, find(alphabet, alphabet + 26, pt[i]));

        //calculate cipher text
        int index = (C - k + 26)%26;
        P += alphabet[index];
    }

    cout<<"Plain Text is:  " <<P<<endl;

}

//--------------------------------------------------------------------------------

// hello
// key = hey
void transposition_encrypt() {
    cout<<"\n Transposition Cipher (Encrypt)\n"<<endl;

    string message;
    cout<< "Enter the message: "; cin>>message;

    string key;
    cout<< "Enter the key: "; cin>>key;

    setPermutationOrder(key);

    int row,col,j;
    string cipher = "";

    /* calculate column of the matrix*/
    col = key.length();

    /* calculate Maximum row of the matrix*/
    row = message.length()/col;

    if (message.length() % col)
        row += 1;

    char matrix[row][col];

    for (int i=0,k=0; i < row; i++)
    {
        for (int j=0; j<col; )
        {
            if(message[k] == '\0')
            {
                /* Adding the padding character ' ' */
                matrix[i][j] = ' ';
                j++;
            }

            if( isalpha(message[k]) || message[k]==' ')
            {
                /* Adding only space and alphabet into matrix*/
                matrix[i][j] = message[k];
                j++;
            }
            k++;
        }
    }

    for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
    {
        j=ii->second;

        // getting cipher text from matrix column wise using permuted key
        for (int i=0; i<row; i++)
        {
            if( isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]==' ')
                cipher += matrix[i][j];
        }
    }

    cout<<"Cipher Text is:  " <<cipher<<endl;
}



