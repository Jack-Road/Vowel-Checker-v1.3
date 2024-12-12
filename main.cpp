#include <iostream>

using namespace std;

int inputTotal;//defining values
int nonalphCount;
int checkPosition;

int vowelCheck(int inputTotal, string inputSentence){//vowelCheck function returns the total number of vowels present in the user's input string
    int resultVowel, checkPosition;//resultVowel contains the vowel total, and is returned by this function
    resultVowel = 0;
    nonalphCount = 0;


    while(checkPosition < inputTotal){//check position is an integer which holds the position in the sentence of our character identifier
        char checkTicker = inputSentence[checkPosition];//defines checkTicker as X letter in the inputted sentence, where X is the position of checkPosition
        if(checkTicker == 'A' || checkTicker == 'E' || checkTicker == 'I' || checkTicker == 'O' || checkTicker == 'U' || checkTicker == 'a' || checkTicker == 'e' || checkTicker == 'i' || checkTicker == 'o' || checkTicker == 'u'){
            resultVowel++;
            cout << "- - - - - - - - -\n[Content Position #" << checkPosition + 1 << "]\n[Vowel Found: (" << checkTicker << ")]" << endl;//data processing display feed
        }
        if(checkTicker == ' ' || checkTicker == ',' || checkTicker == '.' || checkTicker == '\''){
            nonalphCount++;
        }
        checkPosition++;
    }
    return resultVowel;

}


int main()
{
    string phraseRun = "\nI will tell you how many vowels a sentence contains.\nPlease enter a sentence:\n";//defining cycle phrases for the console to display
    string phraseResultP1 = "\nYour sentence contains ";
    string phraseResultP2 = " valid ASCII character(s), ";
    string phraseResultP3 = " of which were vowels.\n";
    string phraseRunCheck = "Run again?\n[Y/N]: ";
    string phraseDebug = "*[END OPERATIONS]*\n\n";
    string phraseAll[5] = {phraseRun, phraseResultP1, phraseResultP2, phraseResultP3, phraseRunCheck};//arrays cycle phrases within "phraseAll[]"

    bool kill = false;//initalizing "While Loop" boolean


    while(!kill){//"While Loop" to execute vowel check operation multiple times in one program execution

        cout << phraseAll[0] << endl;//requests user content string for vowel check data processing
        string inputSentence;
        getline(cin, inputSentence);//obtains content string for vowel check data processing
        inputTotal = inputSentence.length();//obtains length of content string
        int resultVowel;
        resultVowel = vowelCheck(inputTotal, inputSentence);//calls on the "vowelCheck" function to count vowels in content string, excludes NON-ASCII from count

        cout << phraseDebug << phraseAll[1] << inputTotal - nonalphCount << phraseAll[2] << resultVowel << phraseAll[3] << endl;//displays results of current "When Loop"
        cout << phraseAll[4];//asks user if they will execute the "When Loop" again
        char inputRunCheck;
        cin >> inputRunCheck;

        if(inputRunCheck == 'n' || inputRunCheck == 'N'){//comprehends "When Loop" binary input, kills loop if 'n/N' is read
            kill = true;
            break;
        }
        cin.ignore();//clears input buffer before cycling "When Loop"
    }
    return 0;

}
