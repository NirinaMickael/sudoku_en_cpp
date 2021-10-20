#ifndef SDK_H
#define SDK_H
#define MAX 9
class sdk
{
   private:
      std::vector<std::vector<int>>Matrice;
      void Color(int couleurDeText);
      std::vector<int>t;
      std::vector<std::vector<int>>stock_pos;// variable pour stoker les pos que la machine choisit au hasard
       bool meme_pos(int pos);
       bool meme_colonne(int posX,int posY,int valeur);
       bool meme_ligne(int posX,int posY,int valeur);
       void remplir_cage_hasard();//Mameno ny kazy
       void effacerconsole();
   public:
       sdk();
       bool effacer_val(int posX,int posY);//mamafa valeur
       void affichage();//Manapoitra ny interface
       void aleatoire_place();//les valeurs seront choisir au hasard
       void commencer_jouer();
       void jouer_maintenant();//commencer alors a jouer
       bool verification_val_utulisateur_ligne(int posX,int posY,int valeur);//verificatio chaque ligne
       bool verification_val_utulisateur_colonne(int posX,int posY,int valeur);//verification chaque colonne
       bool verification_pos_utulisateur(int posX,int posY);//verifier les position entrer par l'utulisateur
       bool cage_sont_rempli();//verification si les cages sont bient rempli
};

#endif // SDK_H
