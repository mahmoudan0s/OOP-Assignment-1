// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: Asignment.cpp
// Last Modification Date:	09/10/2023
// Author1 and ID and Group:	Menna Ahmed - 20221163
// Author2 and ID and Group:	Haidy Ehab -  20221191
// Author3 and ID and Group:	Mohamed Anas - 20220323
#include <iostream>
using namespace std;
#include "bmplib.h"
#include <unistd.h>
#include <fstream>
#include <cstring>
unsigned char imgGs[SIZE][SIZE];

void loadImage();
void saveImage();
void Invert();
void Rotate();

int main() {
    loadImage();
    saveImage();
    showGSBMP(imgGs);
    return 0;
}
    void loadImage () {
        string Image_Name,path = "\\imgs\\";
        string filters[] = {"1.Black and White", "2.Invert", "3.Merge", "4.Flip", "5.Rotate",
                            "6.Darken and Lighten", "7.Detect Image Edges", "8.Enlarge Image",
                            "9.Shrink", "a.Mirror", "b.Shuffle", "c.Blur", "d.crop", "e.Skew Horizontally",
                            "f.Skew Vertically"};
        cout << "Please Enter Image Name From Image Folder (Add .bmp at The End of Image Name)" << endl;
        cin >> Image_Name;
        path+= Image_Name;
        char cwd [PATH_MAX];
        readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGs);
        cout << "Please Choose The Filter You Want" << endl;
        for (int i = 0; i < 15; i++) {
            cout << filters[i] << endl;
        }
        int choice;
        cin >> choice;
        if ( choice == '2') {
        }
        else if ( choice == '5'){
        }
    }

void saveImage () {
    char imageFileName[100];
    cout << "Please Enter Target Image Name";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, imgGs);
}
void Invert () {
    for ( int i = 0; i < SIZE; i++){
        for ( int j  = 0; j < SIZE; j++) {
            imgGs[i][j] = 255 - imgGs[i][j];
        }
    }
}
void rotate (){
}

