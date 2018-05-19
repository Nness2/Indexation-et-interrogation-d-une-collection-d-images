#include <iostream>
#include <vector>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/contrib/contrib.hpp"


using namespace std;
using namespace cv;

class image {

 public :

  IplImage* i;
  string nom;
  int resolution_height;
  int resolution_width;
  int sum_pix;
  
  
 public : 
  
  image(){}; //Constructeur par defaut 
  
  image(IplImage* i, string n, int res_width,int res_height){    //Constructeur
    this->i=i;
    this->nom=n;
    this->resolution_height=res_height;
    this->resolution_width=res_width;
  }
};


void affiche (image& );
int moyenne_couleur (int , image );
int sum_histo(image );
void parti_ent(image , image );
void compare_tt(vector<image> , image );
image new_image (vector<image>);

