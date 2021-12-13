/* Project Name: Vigenere Cipher Decryption
   Mumber name: Jou-Chih Chang, Juan Yin
   Time: 12/1/2021
*/

#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <bits/stdc++.h> 
#include <stdio.h>
using namespace std;

int main() 
{
  // variables
  int i, j;
  int choice;
  string inputt;
  string output = "";
  string keyy; 
  ofstream repo;

  //do loop to get input from user at least once.
  do{

    // get input
    cout << "Enter cipertext and press enter to continue.(Or just press enter to quit): ";
    getline(cin, inputt);

    // convert string to char
    char input[inputt.size()+1];
    strcpy(input, inputt.c_str());
    
    // change lowercase to uppercase
    for(i = 0; i < inputt.length(); i++)
    {
      input[i] = toupper(input[i]);
    }
    
    // get keyword
    cout<<"Please input key for code: ";
    getline(cin,keyy); 

    // convert string to char
    char key[keyy.size()+1];
    strcpy(key, keyy.c_str());

    // change lowercase to uppercase
    for(i = 0; i < keyy.length(); i++)
    {
      key[i] = toupper(key[i]);
    }
  
    // get new generated key
    char newKey[inputt.length()];
    char output[inputt.length()];
    for(i = 0, j = 0; i < inputt.length(); ++i, ++j)
    {
        if(j == keyy.length())
            j = 0;
 
        newKey[i] = key[j];
    }
    
    newKey[i] = '\0';

    // ask user for encrypt or decrypt.
    cout<<"Enter 1 to encrypt or 2 to decrypt: ";
    cin>>choice;
    
    //encrypt
    if (choice == 1)
    {
      for(i = 0; i < inputt.length(); ++i)
      output[i] = ((input[i] + newKey[i]) % 26) + 'A';
    
      output[i] = '\0';

      cout << "Original String: " << inputt << endl;
      cout << "New String: " << output << endl;

    //open File
    repo.open("repo.txt", fstream::app);
    repo<<"\n---FOR ENCRYPTION---";
    repo<<"\nOriginal Sring: "<<inputt;
    repo<<"\nKey: "<<keyy;
    repo<<"\nNew Generated Key: "<<newKey;
    repo<<"\nEncrypted String: "<<output;
    repo<<"\n------------------------------------";
    //close File
    repo.close();
    }

    //decrypt
    if (choice == 2)
    {
      for(i = 0; i < inputt.length(); ++i)
      output[i] = (((input[i] + newKey[i]) + 26) % 26) + 'A');
    
      output[i] = '\0';
      cout << "Original String: " << inputt << endl;
      cout << "New String: " << output << endl;

    //Open File
    repo.open("repo.txt", fstream::app);
    repo<<"\n---FOR ENCRYPTION---";
    repo<<"\nOriginal Sring: "<<inputt;
    repo<<"\nKey: "<<keyy;
    repo<<"\nNew Generated Key: "<<newKey;
    repo<<"\nEncrypted String: "<<output;
    repo<<"\n------------------------------------";
    //Close File
    repo.close();
    }
  }while(inputt.length() != 0);
    
  return 0;
}
