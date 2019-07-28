#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>


using namespace std;

int search( string word)
{
    //cout<<"First letter is: "<<word[0]<<endl;

    string path;
    char s='a';
    string x="dictionary\\a.txt";
    for(int i=0; i<26; i++)
    {
        if(word[0]==s)
        {
            path=x;
        }
        s++;
        x[11]=s;
    }

    //string path="words.txt" ;

    ifstream file( path.c_str()) ;

    int countwords = 0 ;

    if( file.is_open() )
    {
        //cout << "File '" << path << "' opened."<<endl ;


        string candidate ;
        while( file >> candidate ) // for each word read from the file
        {
            if( word == candidate )
            {
                countwords++;

            }
        }


    }

    else
    {
        cout<< "Error! File not found!"<<endl;
        return 0 ;
    }

    //cout << "The word '" << word << "' has been found " << countwords << " times."<<endl;

    return countwords;

}

int check=0;

void permute(string a, int l, int r)
{
    int i;

    if (l == r)
    {
        //cout<<a<<endl;
        check=search(a);
        //cout<<check<<endl;
        if(check==1)
        {
            cout<<"Did you mean '"<<a<<"' ?"<<endl;
        }

    }
    else
    {
        for (i = l; i <= r; i++)
        {
            if(check==1)
            {
                break;  //Comment this out if want to view all correct words
            }
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]); //backtrack


        }

    }


}


void autocorrect()
{
    cout << "Write the word you want to auto-correct: ";
     string word ;
     cin >> word ;
     cout<<endl;

     int check=search(word);

     if(check==1)
     {
         cout<<"Word is already Correct"<<endl;
     }
     else
     {
         //cout<<"Word is wrong"<<endl;
         //string s = word;
         //string correct;
         int n = word.length();
         permute(word, 0, n-1);

         //cout<<"No Nearest Word found"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Returning to main menu is 5 sec..";
}

void add_to_dictionary()
{
    string word1;

    cout<<"Enter Word: ";
    cin>>word1;
    fstream input;

    char s='a';
    string path="dictionary/a.txt";
    //cout<<path[11]<<endl;
    for(int i=0; i<26; i++)
    {
        if(word1[0]==s)
        {
            ofstream input(path,ofstream::out | std::ofstream::app);

            if (!input)
            {
                cout<< "Could not open the file!" << std::endl;
            }
            else
            {
                input<<word1<<endl;
                cout<<"'"<<word1<<"'"<<" added to Dictionary"<<endl;
            }
        }
        s++;
        path[11]++;
    }

    cout<<endl<<endl;

    cout<<"Returning to main menu is 5 sec..";
}
int main()
{

    place:
    /* cout << "Write the word you want to auto-correct: ";
     string word ;
     cin >> word ;
     cout<<endl;

     int check=search(word);

     if(check==1)
     {
         cout<<"Word is Correct"<<endl;
     }
     else
     {
         //cout<<"Word is wrong"<<endl;
         //string s = word;
         //string correct;
         int n = word.length();
         permute(word, 0, n-1);

         //cout<<"No Nearest Word found"<<endl;
     }
    */
    for(int i=0; i<50; i++)
    {
        cout<<"\\";
    }
    cout<<endl<<endl;

    for(int i=0; i<11; i++)
    {
        cout<<" ";
    }

    cout<<"AutoCorrect program"<<endl<<endl;

    for(int i=0; i<50; i++)
    {
        cout<<"\\";
    }

    cout<<endl<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<" ";
    }

    cout<<"By Syed Muhammad Usman (16PWCSE1444)"<<endl<<endl;


    for(int i=0; i<50; i++)
    {
        cout<<"-";
    }

    cout<<endl;

    cout << "1 - AutoCorrect"<<endl;
    cout << "2 - Add to Dictionary"<<endl;
    cout << "3 - Exit Program"<<endl;

    cout<<endl;
    cout << "Selection: ";

    int select;
    cin>>select;


    switch ( select )
    {

    case 1 :
        system("cls");

        autocorrect();
        Sleep(5000);
        system("cls");

        break;

    case 2 :
        system("cls");
        cout<<"Add To Dictionary";
        add_to_dictionary();
        Sleep(5000);
        system("cls");
        break;

    case 3 :
        system("cls");
        return 0;
        break;


    default :

        cout<<"YOUR ENTRY IS INVALID, Please try again!"<<endl;
        cout<<endl;
        break;

    }

    goto place;



}
