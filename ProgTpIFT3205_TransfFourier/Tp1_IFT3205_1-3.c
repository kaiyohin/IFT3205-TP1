/*------------------------------------------------------*/
/* Prog    : Tp1_IFT3205-1-3.c                          */
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
#define NAME_VISUALISER "display "
#define NAME_IMG_IN1  "D1r"
#define NAME_IMG_IN2  "D1r"
#define NAME_IMG_IN3  "D11r"
#define NAME_IMG_IN4  "D46r"

#define NAME_IMG_OUT1 "image-Tp1_IFT3205-1-3"
#define NAME_IMG_OUT2 "image-Tp1_IFT3205-1-4a"
#define NAME_IMG_OUT3 "image-Tp1_IFT3205-1-4b"
#define NAME_IMG_OUT4 "image-Tp1_IFT3205-1-4c"

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
  MatriceImgR=LoadImagePgm(NAME_IMG_IN1,&length,&width);
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

  /*Module*/
  Mod(MatriceImgM,MatriceImgR,MatriceImgI,length,width);

  /*Log*/
  applyLog(MatriceImgM, length, width);

  /*Pour visu*/
  Recal(MatriceImgM,length,width);
  //Mult(MatriceImgM,100.0,length,width);

  /* Re Center image */
  CenterImg(&MatriceImgM, length, width);

  
  /*Sauvegarde de MatriceImgM sous forme d'image pgm*/
  SaveImagePgm(NAME_IMG_OUT1,MatriceImgM,length,width);

  /*Liberation memoire pour les matrices*/
  free_fmatrix_2d(MatriceImgR);
  free_fmatrix_2d(MatriceImgI); 
  free_fmatrix_2d(MatriceImgM);    

  /*Commande systeme: visualisation de Ingout.pgm*/
  strcpy(BufSystVisuImg,NAME_VISUALISER);
  strcat(BufSystVisuImg,NAME_IMG_OUT1);
  strcat(BufSystVisuImg,".pgm&");
  printf(" %s",BufSystVisuImg);
  system(BufSystVisuImg);



     /*Allocation memoire pour la matrice image*/
     MatriceImgR=LoadImagePgm(NAME_IMG_IN2,&length,&width);
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

     /*Module*/
     Mod(MatriceImgM,MatriceImgR,MatriceImgI,length,width);

     /*Log*/
     applyLog(MatriceImgM, length, width);

     /*Pour visu*/
     Recal(MatriceImgM,length,width);
     //Mult(MatriceImgM,100.0,length,width);

     /* Re Center image */
     CenterImg(&MatriceImgM, length, width);


     /*Sauvegarde de MatriceImgM sous forme d'image pgm*/
     SaveImagePgm(NAME_IMG_OUT2,MatriceImgM,length,width);

     /*Liberation memoire pour les matrices*/
     free_fmatrix_2d(MatriceImgR);
     free_fmatrix_2d(MatriceImgI);
     free_fmatrix_2d(MatriceImgM);

     /*Commande systeme: visualisation de Ingout.pgm*/
     strcpy(BufSystVisuImg,NAME_VISUALISER);
     strcat(BufSystVisuImg,NAME_IMG_OUT2);
     strcat(BufSystVisuImg,".pgm&");
     printf(" %s",BufSystVisuImg);
     system(BufSystVisuImg);


     /*Allocation memoire pour la matrice image*/
     MatriceImgR=LoadImagePgm(NAME_IMG_IN3,&length,&width);
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

     /*Module*/
     Mod(MatriceImgM,MatriceImgR,MatriceImgI,length,width);

     /*Log*/
     applyLog(MatriceImgM, length, width);

     /*Pour visu*/
     Recal(MatriceImgM,length,width);
     //Mult(MatriceImgM,100.0,length,width);

     /* Re Center image */
     CenterImg(&MatriceImgM, length, width);


     /*Sauvegarde de MatriceImgM sous forme d'image pgm*/
     SaveImagePgm(NAME_IMG_OUT3,MatriceImgM,length,width);

     /*Liberation memoire pour les matrices*/
     free_fmatrix_2d(MatriceImgR);
     free_fmatrix_2d(MatriceImgI);
     free_fmatrix_2d(MatriceImgM);

     /*Commande systeme: visualisation de Ingout.pgm*/
     strcpy(BufSystVisuImg,NAME_VISUALISER);
     strcat(BufSystVisuImg,NAME_IMG_OUT3);
     strcat(BufSystVisuImg,".pgm&");
     printf(" %s",BufSystVisuImg);
     system(BufSystVisuImg);



     /*Allocation memoire pour la matrice image*/
     MatriceImgR=LoadImagePgm(NAME_IMG_IN4,&length,&width);
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

     /*Module*/
     Mod(MatriceImgM,MatriceImgR,MatriceImgI,length,width);

     /*Log*/
     applyLog(MatriceImgM, length, width);

     /*Pour visu*/
     Recal(MatriceImgM,length,width);
     //Mult(MatriceImgM,100.0,length,width);

     /* Re Center image */
     CenterImg(&MatriceImgM, length, width);


     /*Sauvegarde de MatriceImgM sous forme d'image pgm*/
     SaveImagePgm(NAME_IMG_OUT4,MatriceImgM,length,width);

     /*Liberation memoire pour les matrices*/
     free_fmatrix_2d(MatriceImgR);
     free_fmatrix_2d(MatriceImgI);
     free_fmatrix_2d(MatriceImgM);

     /*Commande systeme: visualisation de Ingout.pgm*/
     strcpy(BufSystVisuImg,NAME_VISUALISER);
     strcat(BufSystVisuImg,NAME_IMG_OUT4);
     strcat(BufSystVisuImg,".pgm&");
     printf(" %s",BufSystVisuImg);
     system(BufSystVisuImg);



  /*retour sans probleme*/ 
  printf("\n C'est fini ... \n\n");
  return 0; 	 
}


