#include <iostream>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;
/*generer un mot random*/
string creer_mot( int langueur)
{
    static const char alpha[] ="abcdefghijklmnopqrstuvwxyz";
    string mot;
    mot.reserve(langueur);

    for (int i = 0; i < langueur; i++)
    {
        mot+=alpha[rand() % (sizeof(alpha)-1)];
    }
    return mot;
}
/*generer un dictionnaire random */
void creer_dictionnaire(const string &dic,int nbmot)
{
    ofstream myFile(dic);

    for(int i=0; i<nbmot; i++)
    {
        string mot1=creer_mot(rand()%10);
        myFile<<mot1<<endl;
    }
    myFile.close();
}

/*pour trier le dictionnaire*/
void trier_dictionnaire(const string &source,const string &dest)
{
    vector<string> vec;
    fstream file;
    string word;
    file.open(source);
    while(file >> word)
    {
        vec.push_back(word);
    }
    file.close();
    std::sort(vec.begin(), vec.end());

    ofstream file_trie(dest);
    for(auto & i : vec)
    {
        file_trie<<i<<"\n";
    }
    file_trie.close();
}

void chercher_mot(vector<string>v,string mot)
{
    vector<string>::iterator it;
    it=find(v.begin(),v.end(),mot);
    if(it!=v.end())
        cout<<"le mot "<<mot<<" exist \n";
    else
        cout<<"le mot "<<mot<<" n'existe pas !!\n";
}

int main()
{
    string w;
    vector<string> vec,ve;
    srand(NULL);
    creer_dictionnaire("dic.txt",1000);
    trier_dictionnaire("dic.txt","dic_trie.txt");
    fstream NDFile;
    NDFile.open("dic.txt");
    fstream DFile;
    DFile.open("dic_trie.txt");
    while (NDFile>>w)
          ve.push_back(w);
    while (DFile >> w)
        vec.push_back(w);


        // pour afficher le dictionnaire non triee
        cout<<"dictionnaire non triee"<<endl;
        for(auto & i:ve)
        {
            cout<<i<<endl;
        }
        // pour afficher le dictionnaire triee
        cout<<"dictionnaire triee"<<endl;
        for(auto & i:vec)
        {
            cout<<i<<endl;
        }

    chercher_mot(vec,"sixhvd");

    return 0;
}
