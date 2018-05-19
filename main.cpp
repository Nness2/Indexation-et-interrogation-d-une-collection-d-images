#include "image.h"



int main (int argc, char *argv[]){
	vector<image> bibliotheque;
	IplImage* img;
	char choix;

	cout<<"/*****************************************************************/"<<endl;

	//image de la bibliothèque de base
	img=cvLoadImage ("Images/Lave.jpg",CV_LOAD_IMAGE_COLOR);
	image im(img, "Lave", img->width, img->height);
	bibliotheque.push_back(im);

	img=cvLoadImage("Images/Montagne.jpg",CV_LOAD_IMAGE_COLOR);
	image im2(img, "Montagne", img->width, img->height);
	bibliotheque.push_back(im2);


	img=cvLoadImage("Images/Durouge.jpg",CV_LOAD_IMAGE_COLOR);
	image im3(img, "Durouge", img->width, img->height);
	bibliotheque.push_back(im3);


	img=cvLoadImage("Images/Prairie.jpg",CV_LOAD_IMAGE_COLOR);
	image im4(img, "Prairie", img->width, img->height);
	bibliotheque.push_back(im4);


	img=cvLoadImage("Images/Desert.jpg",CV_LOAD_IMAGE_COLOR);
	image im5(img, "Desert", img->width, img->height);
	bibliotheque.push_back(im5);
	//end image de la bibliothèque de base


	//Menu
	while(choix!='4'){

		//information menu
		cout<<"Selectionnez :"<<endl<<"1 : Pour ajouter une nouvelle image à la bibliothèque."
							  <<endl<<"2 : Pour comparer la nouvelle image avec le reste de la bibliothèque."
							  <<endl<<"3 : Afficher le nom des images de la bibliothèque."
							  <<endl<<"4 : Pour sortir du programme."<< "\n";

		//entrez choix :	
		cout << "Choisissez une des quatre options" << "\n" ;
		cin>>choix;

		switch (choix){

			//ajout image dans le vecteur
			case '1' :
			bibliotheque.push_back(new_image (bibliotheque));
			break;

			case '2' :
			//Compare la nouvelle image avec le reste de la bibliothèque
			cout << "COMPARAISON: " << "\n";
			compare_tt (bibliotheque, new_image(bibliotheque));
			cout<<"/*****************************************************************/"<<endl;
			break;

			case '3' :
			cout << "Voici les images de la bibliotheque :" << "\n";
			for (int i = 0; i < bibliotheque.size() ; i++)
				affiche (bibliotheque[i]);
			break;

			case '4':
			break;
			default : 
			cout<<"Erreur entrez une option valide"<<endl;
			//cin>>choix;
		}//end switch
	}//end while


return 0;
}
