// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: Asignment.cpp
// Purpose: Demonstrate using of bmplip for handling
//          bmp grayscale images
//          Program loads a gray image and stores it in another file
//          Making changes to images
// Last Modification Date:	09/10/2023
// Author1 and ID :	Menna Ahmed - 20221163
// Author2 and ID :	Haidy Ehab -  20221191
// Author3 and ID :	Mahmoud Mustafa Anas - 20220323

#include<bits/stdc++.h>
using namespace std;
#include "bmplib.h"
#include <unistd.h>
unsigned char imgGs[SIZE][SIZE];
unsigned char imgGs2[SIZE][SIZE];
unsigned char imgGs3[SIZE][SIZE];



void loadImage();
void filters();
void another_Process();
void saveImage();
void black_and_white();
void invert();
void merge ();
void flip();
void rotate();
void darken_and_lighten();
void enlarge();
void shrink();

int main() {
    loadImage();
    filters();
    saveImage();
    another_Process();
    return 0;
}
void loadImage () {
    string image_name, path = "\\imgs\\";
    cout << "Please Enter Image Name From Image Folder (Add .bmp at The End of Image Name)" << endl;
    cin >> image_name;
    path += image_name;
    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGs);
}
void filters(){
    string choices[] = {"1.Black and White", "2.Invert", "3.Merge", "4.Flip", "5.Rotate",
                        "6.Darken and Lighten","8.Enlarge","9.Shrink"};
    cout << "Please Choose The Filter You Want" << endl;
    for (const auto & filter : choices) {
        cout << filter << endl;
    }
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            black_and_white();
            break;
        case 2:
            invert();
            break;
        case 3:
            merge();
            break;
        case 4:
            flip();
            break;
        case 5:
            rotate();
            break;
        case 6:
            darken_and_lighten();
            break;
        case 9:
            shrink();
        default:
            cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
            filters();
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
void another_Process(){
    cout << "Do You Want To Make Another Process (1.Yes/ 2.No)" << endl;
    int choice4;
    cin >> choice4;
    switch (choice4) {
        case 1:
            loadImage();
            filters();
            saveImage();
            another_Process();
            break;
        case 2:
            cout << "Thank You" << endl;
            break;
        default:
            cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
            another_Process();
    }
}
void black_and_white(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (imgGs[i][j]>127)
                imgGs[i][j]=255;
            else
                imgGs[i][j]=0;
        }
    }
}
void invert () {
    for (auto & imgG : imgGs){
        for (unsigned char & j : imgG) {
            j = 255 - j;
        }
    }
}
void merge () {
    string merge_image, path = "\\imgs\\";
    cout << "Please Enter The Name of Image You Want To Merge From Image Folder (Add .bmp at The End of Image Name)" << endl;
    cin >> merge_image;
    path += merge_image;
    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imgGs2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imgGs[i][j] = (imgGs[i][j]+imgGs2[i][j])/2;
        }
    }
}
void flip(){
    cout<<"Do You Want to Flip The Image Horizontally or Vertically?( 1.Horizontally / 2.Vertically )"<< endl;
    int type;
    cin >> type;
    if (type == 1) {
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 127; j++) {
                swap(imgGs[i][j],imgGs[i][255-1-j]);
            }
        }
    }
    else if (type == 2){
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j < 255; j++) {
                swap(imgGs[i][j],imgGs[255-1-i][j]);
            }
        }
    }
    else {
        cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
        flip();
    }
}

void rotate(){
    int choice3;
    cout << "Please Enter The Rotating Degree (90,180,270)" << endl;
    cin >> choice3;
    switch (choice3) {
        case 90:
            // Rotating image by 90 degrees in clock-wise direction
            // Looping at all pixels one by one
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = i; j < SIZE - i - 1; j++) {
                    // Swap pixels of each cycle
                    // in clockwise direction
                    int temp = imgGs[i][j];
                    imgGs[i][j] = imgGs[SIZE - 1 - j][i];
                    imgGs[SIZE - 1 - j][i] = imgGs[SIZE - 1 - i][SIZE - 1 - j];
                    imgGs[SIZE - 1 - i][SIZE - 1 - j] = imgGs[j][SIZE - 1 - i];
                    imgGs[j][SIZE - 1 - i] = temp;
                }
            }
            break;
        case 180:
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE; j++) {
                    swap(imgGs[i][j], imgGs[SIZE - i - 1][SIZE - j - 1]);
                }
            }
            break;
        case 270:
            // To rotate image by 270 degrees
            // we simply can rotate it by 90 degrees in anti-clockwise direction
            // Looping at all pixels one by one
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = i; j < SIZE - i - 1; j++) {
                    // Store current pixel in
                    // temp variable
                    int temp = imgGs[i][j];
                    // Move pixels from right to top
                    imgGs[i][j] = imgGs[j][SIZE - 1 - i];
                    // Move pixels from bottom to right
                    imgGs[j][SIZE - 1 - i] = imgGs[SIZE - 1 - i][SIZE - 1 - j];
                    // Move pixels from left to bottom
                    imgGs[SIZE - 1 - i][SIZE - 1 - j] = imgGs[SIZE - 1 - j][i];
                    // Assign temp to left
                    imgGs[SIZE - 1 - j][i] = temp;
                }
            }
            break;
        default:
            cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
            rotate();
    }
}
void darken_and_lighten() {
    string choice2;
    cout << "Do You Want The Image Lightened or Darkened ? ( 1.Light / 2.Dark )" << endl;
    cin >> choice2;
    if (choice2 == "1") {
        int maxPixelValue = 255;
        int newPixelValue;
        for (auto & imgG : imgGs) {
            for (unsigned char & j : imgG) {
                newPixelValue = j + maxPixelValue * 0.5;
                if (newPixelValue > maxPixelValue) {
                    newPixelValue = maxPixelValue;
                }
                j = newPixelValue;
            }
        }
    }
    else if (choice2 == "2") {
        for (auto & imgG : imgGs) {
            for (unsigned char & j : imgG) {
                j = j / 2;
            }
        }
    }
    else {
        cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
        darken_and_lighten();
    }
}
