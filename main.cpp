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
unsigned char imgGs2[SIZE][SIZE];


void loadImage();
void saveImage();
void Black_and_White();
void Invert();
void Merge ();
void Flip();
void Rotate();
void Darken_and_Lighten();
void Filters();
void Another_Process();

int main() {
    loadImage();
    Filters();
    saveImage();
    Another_Process();
    return 0;
}
    void loadImage () {
        string Image_Name, path = "\\imgs\\";
        cout << "Please Enter Image Name From Image Folder (Add .bmp at The End of Image Name)" << endl;
        cin >> Image_Name;
        path += Image_Name;
        char cwd[PATH_MAX];
        readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGs);
    }
    void Filters(){
        string filters[] = {"1.Black and White", "2.Invert", "3.Merge", "4.Flip", "5.Rotate",
                            "6.Darken and Lighten"};
        cout << "Please Choose The Filter You Want" << endl;
        for (int i = 0; i < 6; i++) {
            cout << filters[i] << endl;
        }
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                break;
            case 2:
                Invert();
                break;
            case 3:
                Merge();
                break;
            case 4:
                break;
            case 5:
                Rotate();
                break;
            case 6:
                Darken_and_Lighten();
                break;
            default:
                cout << "Invalid Choice,Please Choose Suitable Choice" << endl;
                Filters();
        }
    }
    void saveImage () {
        char imageFileName[100];
        cout << "Please Enter Target Image Name";
        cin >> imageFileName;
        strcat (imageFileName, ".bmp");
        writeGSBMP(imageFileName, imgGs);
        cout << "Image Is Saved In Folder" << endl;
    }
    void Another_Process(){
    cout << "Do You Want To Make Another Process (1.Yes/ 2.No)" << endl;
    int choice4;
    cin >> choice4;
        switch (choice4) {
            case 1:
                loadImage();
                Filters();
                saveImage();
                Another_Process();
                break;
            case 2:
                cout << "Thank You" << endl;
                break;
            default:
                cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
                Another_Process();
        }
    }
    void Black_and_White(){
    }
    void Invert () {
        for ( int i = 0; i < SIZE; i++){
            for ( int j  = 0; j < SIZE; j++) {
                imgGs[i][j] = 255 - imgGs[i][j];
            }
        }
    }
    void Merge () {
        string Merge_Image, path = "\\imgs\\";
        cout << "Please Enter Image Name From Image Folder (Add .bmp at The End of Image Name)" << endl;
        cin >> Merge_Image;
        path += Merge_Image;
        char cwd[PATH_MAX];
        readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGs2);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imgGs[i][j] = (imgGs[i][j]+imgGs2[i][j])/2;
            }
        }
    }
    void Flip(){
    }
    void Rotate(){
    int choice3;
    cout << "Please Enter The Rotating Degree (90,180,270)" << endl;
    cin >> choice3;
        switch (choice3){
            case 90:
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE/2; j++) {
                        swap(imgGs[i][j],imgGs[i][SIZE-1-j]);
                    }
                }
                break;
            case 180:
                for (int i = SIZE - 1; i >= 0; i--) {
                    for (int j = SIZE - 1; j >= 0; j--){
                        imgGs[i][j] = imgGs[i][j];
                    }
                }
                showGSBMP(imgGs);
                break;
            case 270:
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        imgGs[j][SIZE - i - 1] = imgGs[i][j];

                    }
                }
                showGSBMP(imgGs);
                break;
            default:
        cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
        Rotate();
    }
}
    void Darken_and_Lighten() {
        string choice2;
        cout << "Want You The Image Lighten or Darken ? ( 1.Light / 2.Dark )" << endl;
        cin >> choice2;
        if (choice2 == "1") {
            int MaxPixelValue = 255;
            int NewPixelValue;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    NewPixelValue = imgGs[i][j] + MaxPixelValue * 0.5;
                    if (NewPixelValue > MaxPixelValue) {
                        NewPixelValue = MaxPixelValue;
                    }
                    imgGs[i][j] = NewPixelValue;
                }
            }
        }
        else if (choice2 == "2") {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGs[i][j] = imgGs[i][j] / 2;
                }
            }
        }
        else {
            cout << "Invalid Choice" << endl;
            Darken_and_Lighten();
        }
    }