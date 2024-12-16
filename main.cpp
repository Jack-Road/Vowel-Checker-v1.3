#include <iostream>

using namespace std;

int inputCheckV(int inputCharTotal, string userString){//This function obtains the total number of Vowels present in user content.
    int inputResultV = 0;
    int checkerA = 0;
    char checkerContentA;

    cout << "\n\n*BEGIN OPERATIONS\n";
    while(checkerA < inputCharTotal){//Loop to obtain the number of Vowels present in user content, using a "ticker".
        checkerContentA = userString[checkerA];
        if(checkerContentA == 'A' || checkerContentA == 'E' || checkerContentA == 'I' || checkerContentA == 'O' || checkerContentA == 'U' || checkerContentA == 'a' || checkerContentA == 'e' || checkerContentA == 'i' || checkerContentA == 'o' || checkerContentA == 'u'){
            cout << "- - - - - - - - - - -\n[Content Position #" << checkerA + 1 << "]\n[Vowel Found: (" << checkerContentA << ")]" << endl;
            inputResultV++;
        }
        checkerA++;
    }
    cout << "- - - - - - - - - - -\n*[END OPERATIONS]*\n" << endl;
    return inputResultV;
}

int inputCheckNA(int inputCharTotal, string userString){//This function obtains the total number of Non-Alphanumeric characters present in user content, to be omitted from letter count.
    int inputResultNA = 0;
    int checkerB = 0;
    char checkerContentB;

    while(checkerB < inputCharTotal){//Loop to obtain the number of Non-Alphanumeric characters present in user content, using a "ticker".
        checkerContentB = userString[checkerB];//Defining the "ticker" which operates within the loop, to obtain each character's content within the user content.
        if(checkerContentB == ' ' || checkerContentB == ',' || checkerContentB == '.' || checkerContentB == '\''){//Checks if "ticker" content is a Non-Alphanumeric character.
            inputResultNA++;//Iterates count of Non-Alphanumeric Characters if one such character is obtained.
        }
        checkerB++;//Moves "ticker" location to next character, after "ticker" character content check.
    }
    return inputResultNA;//Returns total number of Non-Alphanumeric characters present in the user content, to be omitted from the letter count.
}

int inputCheckRun(char userRunString){//This function obtains the answer to "Run Again?" query.
    bool inputRunLoop = true;
    bool inputResultRun = true;

    while(inputRunLoop){//Loop to check if user wants to run program an additional time, or exit the application.
        cout << "\n\nRun again?\n[Y/N]: ";
        char userRunString = 0;
        string inputRunQuery;
        getline(cin, inputRunQuery);//Obtains user input for program execution query.
        userRunString = inputRunQuery[0];

        if(userRunString == 'n' || userRunString == 'N'){//Checks if inputRunQuery == [n/N], then kills program if [n/N] is obtained, and kills query loop.
            inputRunLoop = false;
            inputResultRun = false;
        }else
        if(userRunString == 'y' || userRunString == 'Y'){//Checks if inputRunQuery == [y/Y], then executes program again if [y/Y] is obtained, and kills query loop.
            inputRunLoop = false;
            inputResultRun = true;
        }else
        cout << "\n*[INPUT ERROR]*\n";//String that is output in console if an invalid inputRunQuery is obtained, through (else) motion.
    }
    return inputResultRun;//Returns answer to "Run Again?" query.
}

//"I see the vowel check function, and the NA-character check function, but how are the counts of letters and consonants obtained without a check function?"
//  This is done through deducting the NA-character count from the string length, giving us the total number of letters in the string.
//      [   (characters) - (NA characters) = (letters)  ]
//
//  We can further deduct our vowel count from this total number of letters, and obtain the number of consonants.
//      [   (letters) - (vowels) = (consonants)  ]
//
//  That is the logic of how the counts of both letter(s) and consonant(s) are obtained.
int main(){//Main function. Contains primary/root "While Loop" for processing user input, program kill function.
    bool kill = false;//Declares program kill as false, meaning program is "live".

    cout << "I can tell you the total count of precisely how many Vowels, Consonants,\nand Non-Alphanumeric characters there are contained within a provided\ncontent string.\n";

    while(!kill){//Primary "While Loop" to process user input, and to then to call on functions for this processing.
        int inputCharTotal = 0;//Declaring variables to be used in main scope.
        int inputResultV = 0;
        int inputResultNA = 0;
        bool inputResultRun;
        string userString;
        char userRunString = 0;

        cout << "\nPlease enter a content string for processing,\nand press the Enter Key to submit:\n\n";
        getline(cin, userString);//Obtains user content string for processing
        inputCharTotal = userString.length();//Finds length of user content string, and defines inputCharTotal as that length.
        inputResultV = inputCheckV(inputCharTotal, userString);//Calls on vowel counting function.
        inputResultNA = inputCheckNA(inputCharTotal, userString);//Calls on Non-Alphanumeric character counting function.

        cout << "\nTOTAL VOWEL COUNT: (" << inputResultV << ") vowels\nTOTAL LETTER COUNT: (" << inputCharTotal - inputResultNA << ") letters\n";//Displays results of count.

        inputResultRun = inputCheckRun(userRunString);//Calls on the inputCheckRun function which asks the user if they want to process another string.
        if(!inputResultRun){//Kills the program if user input declares bool kill = true;.
            kill = true;//Sets primary "While Loop" to false.
            break;
            }
        }
    return 0;
}
