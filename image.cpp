#include "image.h"
#include <iostream>

void affiche (image& im){
  //string name = im.nom;
  const char* name (im.nom.c_str());
  cout << "~> " << im.nom << "\n";
} 




int moyenne_couleur (int c, image im){
  CvScalar pixel;
  int i;
  int j;
  int add = 0;
  for (i = 0; i <= im.resolution_height - 1; i++){     //Parcourt pixel par pixel

    for (j = 0; j <= im.resolution_width - 1; j++){
      j++;
      pixel=cvGet2D(im.i ,i ,j);            //Récup pixel aux coordonnées donnée
      add += (int)pixel.val[c];             //Cast CvScalar en Int + somme pour calculer la moyenne
    }  
  }
  add = add / (im.resolution_width * im.resolution_height);    //On divise par le nombre de pixel pour avoir la moyenne
  return add;
}




int sum_histo(image im){
  int pix_blu;
  int pix_gre;
  int pix_red;
  int somme;
  pix_blu=moyenne_couleur(0, im); // bleu
  pix_gre=moyenne_couleur(1, im); // vert
  pix_red=moyenne_couleur(2, im); // rouge
  somme=(pix_blu+pix_gre+pix_red)*(pix_blu+pix_gre+pix_red);  
  
  return somme;
}




void parti_ent(image im1, image im2){    // ici comparaison entre deux images //
    unsigned int ent = sum_histo(im1) - sum_histo(im2); //somme des carres des deux images //
    //cout << "ent :" << ent << "\n";

    if (ent < 87783 ){  //Affinement
        cout <<"~> L'image "<<im1.nom <<" est ressemblante a l'image : " <<im2.nom<<endl;
    }

    else {
        cout <<"~> L'image :"<<im1.nom <<" n'est  pas ressemblante a l'image : " <<im2.nom<<endl;

    }
}    




void compare_tt(vector<image> v, image im_compa){    //Compart une nouvelle image avec la bibliotheque
    image ll;
    for (int x=0; x < v.size() ; x++){   //On calcule l'histogramme pour toute les images
        ll=v[x];
        sum_histo(ll);
    }
    sum_histo (im_compa);   
    for (int y=0; y<v.size(); y++){  //On compare la nouvelle image avec la bibliotheque grace à la fonction parti_ent (distance des couleurs)
        ll=v[y];
        parti_ent(ll,im_compa);
    }

}




image new_image (vector<image> v){  // Ajoute une nouvelle image 
  string chemin;    
  string name;
  IplImage* i;
  cout << "Entrez le chemin de votre image (ex : Image/nom_de_l'image.jpg)" << endl;
  cin >> chemin;
  const char* chemin2 (chemin.c_str());

  cout << "Entrez le Nom de l'image"<<endl ;
  cin >> name;
  i = cvLoadImage(chemin2 , CV_LOAD_IMAGE_COLOR);
  image newI (i, name, i->width, i->height);
  return newI;
 
}
