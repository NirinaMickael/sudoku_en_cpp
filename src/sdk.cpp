#include<iostream>// stria mampiasa cout sy cin
#include<vector>//mampiasa vector
#include<iomanip>// nikirakira affichage
#include<ctime>//nampiasa rand sy srand
#include<algorithm>
#include<windows.h>//nandoko lettre
#include "sdk.h"
#define MAX 9
using namespace std;
sdk::sdk() // constructeur
{
        int	i;
		for(i=0;i<9;i++){
          Matrice.push_back(vector<int>(9,0));
		}
}
void sdk::affichage(){
   int unsigned i,j;
   Color(3);
   cout<<setfill(' ')<<setw(35)<<" "<<"SUDOKU"<<endl<<endl;
   Color(12);
   cout<<setfill(' ')<<setw(20)<<" "<<"  1   2   3   4   5   6   7   8   9"<<endl;
   Color(11);
   cout<<setfill(' ')<<setw(20)<<" "<<setfill('-')<<setw(36)<<left<<"+"<<"+"<<endl;
   i=0;
   while(i<9){
        j=0;
       Color(12);
       cout<<setfill(' ')<<setw(18)<<" "<<i+1<<" ";
       Color(11);
        while(j<9){
            if(Matrice[i][j]==0){
              Color(11);
              cout<<"|"<<setfill(' ')<<setw(2)<<right<<" ";
              cout<<setfill(' ')<<setw(1)<<left<<" ";
            }
            else{
              cout<<"|"<<setfill(' ')<<setw(2)<<right<<Matrice[i][j];
              cout<<setfill(' ')<<setw(1)<<left<<" ";
            }
        j++;
        }
        cout<<"|"<<endl;
        if(i==2 || i==5 || i==8){
          cout<<setfill(' ')<<setw(20)<<" "<<setfill('_')<<setw(36)<<" "<<endl;
        }else{
        cout<<setfill(' ')<<setw(20)<<" "<<setfill('-')<<setw(36)<<" "<<endl;
        }
    i++;
   }
}
void sdk::Color(int couleurDeText)
{
    HANDLE Handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Handle,couleurDeText);
}
void sdk::aleatoire_place(){
    srand(time(NULL));
    int i,j,nbr_case_vide,pos;
        i=0;
    while(i<9){
        j=0;
         nbr_case_vide=(rand()%7)+1;
        while(j<nbr_case_vide){
          do{
            pos=(rand()%9+1-1)+1;
            t.push_back(pos);
          }while(meme_pos(pos));
         j++;
        }
        sort(begin(t),end(t));
        stock_pos.push_back(t);
        t.erase(begin(t),end(t));
        i++;
    }
    remplir_cage_hasard();
}
void sdk::remplir_cage_hasard(){
int unsigned i,j,pos,valeur;
  i=0;
  while(i<Matrice.size()){
      j=0;
      while(j<stock_pos[i].size()){
        pos=stock_pos[i][j];
        do{ //atao foana mandrapa tsy mampitovy ny "valeur" @valeur hafa
          valeur=(rand()%9)+1;
          Matrice[i][pos]=valeur;
        }while(meme_colonne(i,pos,valeur) || meme_ligne(i,pos,valeur));
        j++;
      }
    i++;
  }
}
bool sdk::meme_pos(int pos){
 int counter=0;
 bool test=false;
 if(t.size()>1){
    counter=count(begin(t),end(t),pos);
    if(counter>1){// s'il y meme chiffre dans le t alors on supprime
        test=true;
        t.erase(end(t)-1,end(t));
    }
    else{
        test=false;
    }
 }
 return test;
}
bool sdk::meme_colonne(int posX,int posY,int valeur){
  int i;
  bool test=false;
  i=0;
  while(i<posX){
     if(valeur==Matrice[i][posY] || valeur==0){
        test=true;
     }
    i++;
  }
   return test;
}
bool sdk::meme_ligne(int posX,int posY,int valeur){
  int i;
  bool test=false;
  i=0;
  while(i<posY){
     if(valeur==Matrice[posX][i] || valeur==0){
        test=true;
     }
    i++;
  }
   return test;
}
void sdk::commencer_jouer(){
   aleatoire_place();
   affichage();
}
bool sdk::verification_pos_utulisateur(int posX,int posY){
  bool test=false;
  if(Matrice[posX-1][posY-1]!=0 && effacer_val(posX,posY)){
    test=true;
  }
  return test;
}
bool sdk::verification_val_utulisateur_colonne(int posX,int posY,int valeur){
    bool test,test1=false,test2=false;
    int unsigned j;
    int i=0;
    while(i<posX && !test1){
       if(valeur==Matrice[i][posY-1] || valeur==0){
        test1=true;
       }
      i++;
    }
    j=posX;
    while(j<Matrice.size() && !test2){
        if(valeur==Matrice[j][posY-1] || valeur==0){
        test2=true;
       }
      j++;
    }
    test=(test1 || test2);
    return test;
}
bool sdk::verification_val_utulisateur_ligne(int posX,int posY,int valeur){
    bool test,test1=false,test2=false;
    int unsigned j;
    int i;
    i=0;
    while(i<posY && !test1){
       if(valeur==Matrice[posX-1][i] || valeur==0){
        test1=true;
       }
      i++;
    }
    j=posY;
    while(j<Matrice.size() && !test2){
        if(valeur==Matrice[posX-1][j] || valeur==0){
        test2=true;
       }
      j++;
    }
    test=(test1 || test2);
    return test;
}
void sdk::effacerconsole(){
system("cls");
affichage();
}
bool sdk::cage_sont_rempli(){
bool test=false;
int unsigned i;
while(i<Matrice[i].size() && !test){
    if(count(begin(Matrice[i]),end(Matrice[i]),0)>0){
        test=true;
    }
i++;
}
return test;
}
void sdk::jouer_maintenant(){
int colonne,ligne,valeur;
 do{
  do{
      cout<<"Remplir la cage vide( ligne colonne  valeur) :";
      cin>>ligne>>colonne>>valeur;
      if(verification_val_utulisateur_colonne(ligne,colonne,valeur) || verification_val_utulisateur_ligne(ligne,colonne,valeur) || verification_pos_utulisateur(ligne,colonne)){
        cout<<"valeur non validE(ou cage deja remplit)"<<endl;
        system("PAUSE");
        effacerconsole();
      }
    }while(verification_val_utulisateur_colonne(ligne,colonne,valeur) || verification_val_utulisateur_ligne(ligne,colonne,valeur) || verification_pos_utulisateur(ligne,colonne));
    Matrice[ligne-1][colonne-1]=valeur;
    effacerconsole();
 }while(!cage_sont_rempli());
 Color(8);
 cout<<"+++++++++++++++++++++++++ GAGNE+++++++++++++++++++++++++++"<<endl;
}
bool sdk::effacer_val(int posX,int posY){
   bool test=false;
   if(count(stock_pos[posX-1].begin(),stock_pos[posX-1].end(),posY-1)>0){
    test=true;
   }
return test;
}
