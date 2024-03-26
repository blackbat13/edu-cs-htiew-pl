# Rozwiązania

## Część II

### Zadanie 4

#### a)

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main()
    {
        ifstream file("anagram.txt");
        for(int row = 0; row < 200; row++) {
            string words[5];
            for(int word_num = 0; word_num < 5; word_num++) {
                file >> words[word_num];
            }

            int word_length = words[0].length();
            bool same_length = true;
            for(int word_num = 1; word_num < 5; word_num++) {
                if(words[word_num].length() != word_length) {
                    same_length = false;
                    break;
                }
            }

            if(same_length) {
                for(auto word : words) {
                    cout << word << " ";
                }

                cout << endl;
            }
        }

        file.close();

        return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    with open("anagram.txt") as file:
        for line in file:
            words = line.split()
            word_length = len(words[0])
            same_length = True
            for word in words:
                if len(word) != word_length:
                    same_length = False
                    break

            if same_length:
                print(*words)
    ```

#### b)

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <algorithm>

    using namespace std;

    int main()
    {
        ifstream file("anagram.txt");
        for(int row = 0; row < 200; row++) {
            string words[5], sorted_words[5];
            for(int word_num = 0; word_num < 5; word_num++) {
                file >> words[word_num];
                sorted_words[word_num] = words[word_num];
                sort(sorted_words[word_num].begin(), sorted_words[word_num].end());
            }

            bool anagrams = true;
            for(int word_num = 1; word_num < 5; word_num++) {
                if(sorted_words[word_num] != sorted_words[0]) {
                    anagrams = false;
                    break;
                }
            }

            if(anagrams) {
                for(auto word : words) {
                    cout << word << " ";
                }
                cout << endl;
            }
        }

        file.close();

        return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    with open("anagram.txt") as file:
        for line in file:
            words = line.split()
            words_sorted = [sorted(word) for word in words]
            anagrams = True
            for word in words_sorted:
                if word != words_sorted[0]:
                    anagrams = False
                    break

            if anagrams:
                print(*words)
    ```

### Zadanie 6

[:material-microsoft-access: Access](../../../assets/2010_zad6.accdb)