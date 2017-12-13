// author : Nathan Easton
// date : 10/16/17
/*
Programs takes in users string and encodes it using either a beaufort crypt or a vigenere crypt
*/

#include<cmath>
#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
string strip(string s){//brings in string s and returns f_string 
/*Takes given string and removes any chars not from the const string above.*/
    string f_string="";
    for (int i = 0; i < s.length(); i++) {
        // cout<<s[i];
        if (alphabet.find(s[i])!=std::string::npos){
            f_string+=s[i];
        }
    }
    return f_string;
} 
string rotate_left(int rotations,string s){
    //Takes in an int and a string returns a string.
    //Rotates letters arround each other r number of times
    if (rotations<1) return s;
    return s.substr(rotations,s.length())+s.substr(0,rotations);
}


char beaufort_letter(char plain,char key){
    //Takes in 2 chars and returns a char
    //Applies the beaufort cipher
    if (alphabet.find(plain)!=std::string::npos && alphabet.find(key)!=std::string::npos){//Checks to see if the letter is in the const declaired at the top
        string rot_alpha=rotate_left((int)plain-'a',alphabet);
        std::size_t found=rot_alpha.find(key);
        return alphabet[found];
    }else{return plain;}
}

char vigenere_letter(char plain, char key){
    //Takes in 2 chars and returns a char
    //Applies the vigenere cipher
        if (alphabet.find(plain)!=std::string::npos && alphabet.find(key)!=std::string::npos){//Checks to see if the letter is in the const declaired at the top
        string rot_alpha=rotate_left((int)plain-'a',alphabet);
        std::size_t found=alphabet.find(key);
        return rot_alpha[found];
        
        // return (char)((int)key+((int)plain-int('a')));
    }else{return plain;}
}
//Takes in two strings and returns an encoded string using the beaufort crypt
string encode_beaufort(string plain_text, string key){
    string finalkey="";
    plain_text=strip(plain_text);//Strips any chars not from const a top
    key=strip(key);//Strips any chars not from const a top
    while (key.length()<plain_text.length()){
        //Makes the key long enough for the plain text
        key+=key;
    }
    for (int i = 0; i < plain_text.length(); i++) {
        if (alphabet.find(plain_text[i])!=std::string::npos){
            finalkey+=beaufort_letter(plain_text[i],key[i]);
        }
    }
    return finalkey;
}
//Takes in two strings and returns an encoded string using the vigenere crypt
string encode_vigenere(string plain_text, string key){
    string finalkey="";
    plain_text=strip(plain_text);//Strips any chars not from const a top
    key=strip(key);//Strips any chars not from const a top
    while (key.length()<plain_text.length()){
        //Makes the key long enough for the plain text
        key+=key;
    }//Just loops through the string one char at a time. 
    for (int i = 0; i < plain_text.length(); i++) {
        if (alphabet.find(plain_text[i])!=std::string::npos){
            // cout<<plain_text[i]<<": "<<abs((int)vigenere_letter(plain_text[i],key[i]))<<endl;
            finalkey+=vigenere_letter(plain_text[i],key[i]);
        }
    }
    return finalkey;
}

int main (){
    // rotate_left(2,"bcdz");
  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
    
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main
