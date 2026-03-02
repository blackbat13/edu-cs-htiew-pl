# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    code_letter = dict()

    with open("morse_alphabet.txt") as file:
        for line in file:
            letter, code = line.split()
            code_letter[code] = letter

    with open("morse.txt") as file:
        for line in file:
            word = ""
            codes = line.split()
            for code in codes:
                word += code_letter[code]
            print(word)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        ifstream file("morse_alphabet.txt");
        map<string, string> codeLetter;
        string letter, code;
        for(int i = 0; i < 36; i++) {
            file >> letter >> code;
            codeLetter[code] = letter; 
        }
        file.close();
        
        string line;
        file.open("morse.txt");
        while(getline(file, line)) {
            code = "";
            line += " ";
            string word = "";
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == ' ') {
                    word += codeLetter[code];
                    code = "";
                } else {
                    code += line[i];
                }
            }
            cout << word << endl;
        }

        file.close();
        
        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    code_letter = dict()
    palindrome_count = 0

    with open("morse_alphabet.txt") as file:
        for line in file:
            letter, code = line.split()
            code_letter[code] = letter

    with open("morse.txt") as file:
        for line in file:
            word = ""
            codes = line.split()
            for code in codes:
                word += code_letter[code]
            
            is_palindrome = True
            for i in range(len(word)):
                if word[i] != word[len(word) - i - 1]:
                    is_palindrome = False

            if is_palindrome:
                palindrome_count += 1

    print(palindrome_count)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        ifstream file("morse_alphabet.txt");
        map<string, string> codeLetter;
        string letter, code;
        int palindromeCount = 0;
        for(int i = 0; i < 36; i++) {
            file >> letter >> code;
            codeLetter[code] = letter; 
        }
        file.close();
        
        string line;
        file.open("morse.txt");
        while(getline(file, line)) {
            code = "";
            line += " ";
            string word = "";
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == ' ') {
                    word += codeLetter[code];
                    code = "";
                } else {
                    code += line[i];
                }
            }
            
            bool isPalindrome = true;
            for(int i = 0; i < word.length(); i++) {
                if(word[i] != word[word.length() - i - 1]) {
                    isPalindrome = false;
                }
            }

            if(isPalindrome) {
                palindromeCount++;
            }
        }

        file.close();

        cout << palindromeCount << endl;
        
        return 0;
    }
    ```

## Zadanie 3


## Zadanie 4

=== "Python"

    ```python linenums="1"
    code_letter = dict()
    words = []

    with open("morse_alphabet.txt") as file:
        for line in file:
            letter, code = line.split()
            code_letter[code] = letter

    with open("morse.txt") as file:
        for line in file:
            word = ""
            codes = line.split()
            for code in codes:
                word += code_letter[code]
            
            word = sorted(word)
            words.append(word)

    anagrams_count = 0

    for i in range(len(words)):
        for j in range(i + 1, len(words)):
            word1 = words[i]
            word2 = words[j]
            if word1 == word2:
                anagrams_count += 1

    print(anagrams_count)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>
    #include <algorithm>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("morse_alphabet.txt");
        map<string, string> codeLetter;
        vector<string> words;
        string letter, code;
        for(int i = 0; i < 36; i++) {
            file >> letter >> code;
            codeLetter[code] = letter; 
        }
        file.close();
        
        string line;
        file.open("morse.txt");
        while(getline(file, line)) {
            code = "";
            line += " ";
            string word = "";
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == ' ') {
                    word += codeLetter[code];
                    code = "";
                } else {
                    code += line[i];
                }
            }
            
            sort(word.begin(), word.end());
            words.push_back(word);
        }

        file.close();

        int anagramsCount = 0;

        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(words[i] == words[j]) {
                    anagramsCount++;
                }
            }
        }

        cout << anagramsCount << endl;
        
        return 0;
    }
    ```
