/*------------------------------------------------------*/
/* Prog    : Tp1_IFT3205-2-2.c                          */
/* Auteur  :  Loïc Daudé Mondet (20243814)  Adel Abdeladim (20127626)  adel.abdeladim@umontreal.ca   */
/* Emails  :  loic.daude.mondet@umontreal.ca   adel.abdeladim@umontreal.ca  */
/* Date    : 18/05/2010                                 */
/* version :                                            */
/* langage : C                                          */
/* labo    : DIRO                                       */
/*------------------------------------------------------*/

/*------------------------------------------------*/
/* FICHIERS INCLUS -------------------------------*/
/*------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "FonctionDemo1.h"

/*------------------------------------------------*/
/* DEFINITIONS -----------------------------------*/   
/*------------------------------------------------*/
#define NAME_VISUALISER "gwenview "
#define NAME_IMG_IN  "photograph"
#define NAME_IMG_OUT "image-TpIFT3205-2-2"

/*------------------------------------------------*/
/* PROTOTYPE DE FONCTIONS  -----------------------*/   
/*------------------------------------------------*/
void CenterImg(float*** MatriceImgM,int length, int width){
    float ** CenteredMatrix = fmatrix_allocate_2d(length, width);
    int center_length = length%2==0 ? length/2-1 : length/2;
    int center_width = width%2==0 ? width/2-1 : width/2;
    for (int i=0; i<width; i++) {
        for (int j=0; j<length; j++) {

            if (i<=center_width) {
                if (j<=center_length) {

                    CenteredMatrix[i+center_width+1][j+center_length+1]=(*MatriceImgM)[i][j];
                } else {
                    CenteredMatrix[i+center_width+1][j-center_length-1]=(*MatriceImgM)[i][j];
                }
            } else {
                if (j<=center_length) {
                    CenteredMatrix[i-center_width-1][j+center_length+1]=(*MatriceImgM)[i][j];
                } else {
                    CenteredMatrix[i-center_width-1][j-center_length-1]=(*MatriceImgM)[i][j];
                }
            }
        }
    }

    free_fmatrix_2d(*MatriceImgM);
    *MatriceImgM=CenteredMatrix;
}

void applyLog(float ** MatriceImgM, int length, int width) {
    for (int i=0; i<width; i++) {
        for (int j=0; j<length; j++) {
            MatriceImgM[i][j]=logf(1+MatriceImgM[i][j]);
        }
    }
}


void filter(float ** MatriceImgR, float ** MatriceImgI, int length, int width) {
    int center_length = length%2==0 ? length/2 : length/2+1;
    int center_width = width%2==0 ? width/2 : width/2+1;
    float val1 = MatriceImgR[center_length-2][center_width-1];
    float val2 = MatriceImgI[center_length-2][center_width-1];
    float val3 = MatriceImgR[center_length+2][center_width+1];
    float val4 = MatriceImgI[center_length+2][center_width+1];
    for (int i=0; i<length; i++) {
        for (int j=0; j<width; j++) {
            if (sqrtf(powf(i-center_length, 2) + powf(j-center_width, 2)) > 2) {
                MatriceImgR[i][j]=0;
                MatriceImgI[i][j]=0;
            } else {
                MatriceImgR[i][j]=MatriceImgR[i][j]*0.01;
                MatriceImgI[i][j]=MatriceImgI[i][j]*0.01;
            }
        }
    }
    MatriceImgR[center_length-2][center_width-1]=val1;
    MatriceImgI[center_length-2][center_width-1]=val1;



    MatriceImgR[center_length+2][center_width+1]=val3;
    MatriceImgI[center_length+2][center_width+1]=val4;



}

/*------------------------------------------------*/
/* PROGRAMME PRINCIPAL   -------------------------*/                     
/*------------------------------------------------*/
int main(int argc,char **argv)
 {
  int i,j,k;
  int length,width;
  char BufSystVisuImg[100];
  float** MatriceImgR;
  float** MatriceImgI;
  float** MatriceImgM;

  /*Allocation memoire pour la matrice image*/
  MatriceImgR=LoadImagePgm(NAME_IMG_IN,&length,&width);
  MatriceImgI=fmatrix_allocate_2d(length,width);
  MatriceImgM=fmatrix_allocate_2d(length,width);

  /*Initialisation a zero de toutes les matrices */
  for(i=0;i<length;i++) 
    for(j=0;j<width;j++) 
      {
	MatriceImgI[i][j]=0.0;
	MatriceImgM[i][j]=0.0;
      }
  
  /*FFT*/
  FFTDD(MatriceImgR,MatriceImgI,length,width);


  CenterImg(&MatriceImgR, length, width);
  CenterImg(&MatriceImgI, length, width);

  filter(MatriceImgR, MatriceImgI, length,width);

  CenterImg(&MatriceImgR, length, width);
  CenterImg(&MatriceImgI, length, width);

  Mod(MatriceImgM,MatriceImgR,MatriceImgI,length,width);
  Recal(MatriceImgM,length,width);
  Mult(MatriceImgM,100.0,length,width);
  CenterImg(&MatriceImgM, length, width);

  IFFTDD(MatriceImgR, MatriceImgI, length, width);
  Recal(MatriceImgR,length,width);

  /*Sauvegarde de MatriceImgM sous forme d'image pgm*/
  SaveImagePgm(NAME_IMG_OUT,MatriceImgR,length,width);

  /*Liberation memoire pour les matrices*/
  free_fmatrix_2d(MatriceImgR);
  free_fmatrix_2d(MatriceImgI); 
  free_fmatrix_2d(MatriceImgM);    

  /*Commande systeme: visualisation de Ingout.pgm*/
  strcpy(BufSystVisuImg,NAME_VISUALISER);
  strcat(BufSystVisuImg,NAME_IMG_OUT);
  strcat(BufSystVisuImg,".pgm&");
  printf(" %s",BufSystVisuImg);
  system(BufSystVisuImg);

  /*retour sans probleme*/ 
  printf("\n C'est fini ... \n\n");
  return 0; 	 
}


