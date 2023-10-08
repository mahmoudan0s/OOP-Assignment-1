// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: Asignment.cpp
// Purpose: Demonstrate using of bmplip for handling
//          bmp grayscale images
//          Program loads a gray image and stores it in another file
//          Making changes to images
// Last Modification Date:	09/10/2023
// Author1 and ID and Group:	Menna Ahmed - 20221163
// Author2 and ID and Group:	Haidy Ehab -  20221191
// Author3 and ID and Group:	Mahmoud Mustafa Anas - 20220323
#include<bits/stdc++.h>
using namespace std;
#include "bmplib.h"
#include <unistd.h>
unsigned char imgGs[SIZE][SIZE];
unsigned char imgGs2[SIZE][SIZE];
unsigned char imgGs3[SIZE][SIZE];

void loadImage();
void Filters();
void Another_Process();
void saveImage();
void Black_and_White();
void Invert();
void Merge ();
void Flip();
void Rotate();
void Darken_and_Lighten();
//void enlarge();
//void shrink();
void Mirror_Image();

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
                        "6.Darken and Lighten","8.Enlarge","9.Shrink","a.Mirror Image"};
    cout << "Please Choose The Filter You Want" << endl;
    for (const auto & filter : filters) {
        cout << filter << endl;
    }
    char choice;
    cin >> choice;
    switch (choice) {
        case '1':
            Black_and_White();
            break;
        case '2':
            Invert();
            break;
        case '3':
            Merge();
            break;
        case '4':
            Flip();
            break;
        case '5':
            Rotate();
            break;
        case '6':
            Darken_and_Lighten();
            break;
//        case 9:
//            shrink();
        case 'a':
            Mirror_Image();
            break;
        default:
            cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
            Filters();
    }
}
void saveImage () {
    char imageFileName[100];
    cout << "Please Enter Target Image Name"<<endl;
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
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (imgGs[i][j]>127)
                imgGs[i][j]=255;
            else
                imgGs[i][j]=0;
        }
    }
}
void Invert () {
    for (auto & imgG : imgGs){
        for (unsigned char & j : imgG) {
            j = 255 - j;
        }
    }
}
void Merge () {
    string Merge_Image, path = "\\imgs\\";
    cout << "Please Enter The Name of Image You Want To Merge From Image Folder (Add .bmp at The End of Image Name)" << endl;
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
    cout<<"flip the image horizontally or vertically?( 1.horizontally / 2.vertically )"<<endl;
    int type;
    cin>>type;
    if (type == 1) {
    for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 127; j++) {
                swap(imgGs[i][j],imgGs[i][SIZE-1-j]);
            }
        }

    }
    else if(type==2){
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j < 256; j++) {
                swap(imgGs[i][j],imgGs[SIZE-1-i][j]);
            }
        }
    }
    else {
        cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
        Flip();
    }
}

void Rotate(){
    int choice3;
    cout << "Please Enter The Rotating Degree (90,180,270)" << endl;
    cin >> choice3;
    switch (choice3) {
        case 90:
            // Traverse each cycle
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = i; j < SIZE - i - 1; j++) {
                    // Swap elements of each cycle
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
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, k = SIZE - 1; j < k; j++, k--) {
                    swap(imgGs[j][i], imgGs[k][i]);
                }
            }
            break;
        case 270:
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = i; j < SIZE - i - 1; j++) {
                    // Swap elements of each cycle
                    // in clockwise direction
                    int temp = imgGs[i][j];
                    imgGs[i][j] = imgGs[SIZE - 1 - j][i];
                    imgGs[SIZE - 1 - j][i] = imgGs[SIZE - 1 - i][SIZE - 1 - j];
                    imgGs[SIZE - 1 - i][SIZE - 1 - j] = imgGs[j][SIZE - 1 - i];
                    imgGs[j][SIZE - 1 - i] = temp;
                }
            }
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0, k = SIZE - 1; j < k; j++, k--) {
                    swap(imgGs[j][i], imgGs[k][i]);
                }
            }
            break;
        default:
            cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
            Rotate();
    }
}
void Darken_and_Lighten() {
    string choice2;
    cout << "Do You Want The Image Lightened or Darkened ? ( 1.Light / 2.Dark )" << endl;
    cin >> choice2;
    if (choice2 == "1") {
        int MaxPixelValue = 255;
        int NewPixelValue;
        for (auto & imgG : imgGs) {
            for (unsigned char & j : imgG) {
                NewPixelValue = j + MaxPixelValue * 0.5;
                if (NewPixelValue > MaxPixelValue) {
                    NewPixelValue = MaxPixelValue;
                }
                j = NewPixelValue;
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
        Darken_and_Lighten();
    }

}
void Mirror_Image(){
    cout<<"mirror the Left 1/2 or Right 1/2 or Upper 1/2 or Lower 1/2 of the image?( 1.Left / 2.Right / 3.Upper / 4.Lower )"<<endl;
    int type2;
    cin>>type2;
    switch (type2) {
        case 1:
            for (int i = 0; i <SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGs[i][SIZE-j]=imgGs[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i <SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGs[i][j]=imgGs[i][SIZE-j];
                }
            }
            break;

        case 3:
            for (int i = 0; i <SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGs[SIZE-i][j]=imgGs[i][j];
                }
            }
            break;
        case 4:
            for (int i = 0; i <SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imgGs[i][j]=imgGs[SIZE-i][j];
                }
            }
            break;
        default:
            cout << "Invalid Choice, Please Choose Suitable Choice" << endl;
            Mirror_Image();
    }
}
