////// file :CS112_A3_Part1_19_20230397_20230091_20230424.cpp.
////// purpose : this program works on inserting photos and choosing which filter the user want to apply then saving the new one
////// author: name: Mariam Mohamed Elsawy, ID: 20230397, section:19, the part she did: Black & white filter, flip image, menu;
//////         name: Basmala Mohamed Sobhy, ID: 20230091, section:19, the part she did: grayscale filter, merge images;
//////         name: Menna Mohamed Elabsiry, ID: 20230424, section 19, the part she did: invert image;  
//  
//#include <iostream>
//#include <cstdlib> 
//using namespace std;
//#include "Image_Class.h"
//// function to convert from coloured image to gray one 
//void gray(Image& image) {
//
//    for (int i = 0; i < image.width; i++) {
//        for (int j = 0; j < image.height; j++) {
//            int avg = 0;// setting an average to 0
//
//            for (int k = 0; k < 3; k++) {
//                avg += image(i, j, k);// equating pixel values to the average
//            }
//            avg /= 3;// Calculate average
//            // equating  every channel to the average value
//            image(i, j, 0) = avg;
//            image(i, j, 1) = avg;
//            image(i, j, 2) = avg;
//        }
//
//    }
//
//}
//
//
//// function to convert from coloured image to black&white one
//void b_w(Image& image) {
//    for (int i = 0; i < image.width; ++i) {
//        for (int j = 0; j < image.height; ++j) {
//            unsigned  int average = 0; // setting an average value to change the pixels
//
//            for (int k = 0; k < 3; ++k) {
//                average += image(i, j, k); // equating pixel values to the average
//            }
//
//            average /= 3; // Calculate average
//            if (average > 127) {
//                average = 255;
//            }
//            else {
//                average = 0;
//            }
//
//            // equating  every channel to the average value
//            image(i, j, 0) = average;
//            image(i, j, 1) = average;
//            image(i, j, 2) = average;
//
//        }
//    }
//
//
//}
//// function to invert image  
//void invert(Image& image2) {
//
//    for (int i = 0; i < image2.width; ++i) {
//        for (int j = 0; j < image2.height; ++j) {
//            for (int k = 0; k < 3; ++k) {
//                // Reverse the color by subtracting the current value from 255
//                image2(i, j, k) = 255 - image2(i, j, k);
//            }
//        }
//    }
//}
//
//int main() {
//    string file_name, m1, m2;
//    int choice, choice2;
//    int cot;
//    while (true) {
//        cout << "Do u wanna exit?\n 1) yes\n 2) no "; // make the user to choose if he want to continue or not
//        cin >> cot;
//        if (cot == 1) {
//            break;
//        }
//        else {
//            cout << "choose:\n 1) Grayscale conversion\n 2) Black and white\n 3) Invert image\n 4) merge images\n 5) flip image \n";
//            cin >> choice;
//            if (choice == 1) { // grayscale
//                cout << "pls enter colored image name to convert it to grayscale: ";
//                cin >> file_name;
//
//                Image image(file_name);
//                gray(image); // call the function which convert the image into gray
//                cout << "pls enter image name to store new image\n";
//                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//
//                cin >> file_name;
//                image.saveImage(file_name);// save the new image in a file
//                system(file_name.c_str());
//            }
//            if (choice == 2) { //black&white
//                cout << "Pls enter colored image name to turn to Black and white: ";
//                cin >> file_name;
//
//                Image image(file_name);
//                b_w(image); // call the function which convert the image into gray
//                cout << "pls enter image name to store new image\n";
//                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//
//                cin >> file_name;
//                image.saveImage(file_name);// save the new image in a file
//                system(file_name.c_str());
//            }
//            if (choice == 3) { //invert 
//
//                cout << "Enter the image: ";
//                cin >> file_name;
//                Image image2(file_name);
//                invert(image2); // call the function which invert the image 
//                cout << "enter the file name : ";
//                cin >> file_name;
//
//                image2.saveImage(file_name);// save the new image in a file
//                system(file_name.c_str());
//
//            }
//            if (choice == 4) { //merge
//                string image1, image2, filename;
//                cout << "Enter the two images: ";
//                cin >> image1 >> image2; // get the two files of image from the user 
//
//                Image im1(image1);
//                Image im2(image2);
//
//                while (true) {
//                    int choice2;
//                    cout << "Do you want to merge photos with crop or resize?\n"
//                        << "1) Crop\n"
//                        << "2) Resize\n";
//                    cin >> choice2;
//
//                    if (choice2 == 1) { // by crop
//                        int small_width = min(im1.width, im2.width);
//                        int small_height = min(im1.height, im2.height);
//
//                        Image newxx(small_width, small_height); //make a new image its dimensions equal to the smallest width and height
//
//                        for (int i = 0; i < small_width; i++) {
//                            for (int j = 0; j < small_height; j++) {
//                                for (int k = 0; k < 3; k++) {
//                                    newxx(i, j, k) = (im1(i, j, k) + im2(i, j, k)) / 2;
//                                }
//                            }
//                        }
//
//                        cout << "Enter the file name to save the merged image: ";
//                        cin >> filename;
//                        newxx.saveImage(filename);// save the new image in a file
//                        system(filename.c_str());
//                    }
//                    else if (choice2 == 2) { // by resize
//                        int biggest_width = max(im1.width, im2.width);
//                        int biggest_height = max(im1.height, im2.height);
//                        Image new_size(biggest_width, biggest_height);//make the first image its dimensions equal to the largest width and height
//
//                        for (int i = 0; i < biggest_width; i++) {
//                            for (int j = 0; j < biggest_height; j++) {
//                                int row = i * (im1.width - 1) / (biggest_width - 1);
//                                int col = j * (im1.height - 1) / (biggest_height - 1);
//                                new_size.setPixel(i, j, 0, im1(row, col, 0));
//                                new_size.setPixel(i, j, 1, im1(row, col, 1));
//                                new_size.setPixel(i, j, 2, im1(row, col, 2));
//                            }
//                        }
//
//                        Image new_size2(biggest_width, biggest_height);//make the second image its dimensions equal to the smallest width and height
//
//                        for (int i = 0; i < biggest_width; i++) {
//                            for (int j = 0; j < biggest_height; j++) {
//                                int row = i * (im2.width - 1) / (biggest_width - 1);
//                                int col = j * (im2.height - 1) / (biggest_height - 1);
//                                new_size2.setPixel(i, j, 0, im2(row, col, 0));
//                                new_size2.setPixel(i, j, 1, im2(row, col, 1));
//                                new_size2.setPixel(i, j, 2, im2(row, col, 2));
//                            }
//                        }
//
//                        Image merged(biggest_width, biggest_height);
//                        for (int i = 0; i < biggest_width; i++) {
//                            for (int j = 0; j < biggest_height; j++) {
//                                for (int k = 0; k < 3; k++) {
//                                    int pixel1 = new_size(i, j, k);
//                                    int pixel2 = new_size2(i, j, k);
//                                    int merged_pixel = (pixel1 + pixel2) / 2; //merge the two image together
//                                    merged.setPixel(i, j, k, merged_pixel);
//                                }
//                            }
//                        }
//
//                        cout << "Enter the file name to save the merged image: ";
//                        cin >> filename;
//                        merged.saveImage(filename); // save the new image in a file
//                        system(filename.c_str());
//                    }
//                    else {
//                        cout << "invalid choice ";
//                        continue;
//                    }
//                    break;
//                }
//            }
//
//            else if (choice == 5) { // flip
//                cout << "please enter image name to flip it: ";
//                cin >> file_name; //get the file name of image from the user 
//                Image image(file_name);
//                while (true) {
//                    int choice2;
//                    cout << " do you want to flip image horizontally or vertically : \n1) horiz \n2) vecti \n";
//                    cin >> choice2;
//                    if (choice2 == 1) { //horizontally
//                        for (int i = 0; i < image.width; ++i) {
//
//                            for (int j = 0; j < image.height; ++j) {
//
//                                for (int k = 0; k < 3; ++k) {
//                                    unsigned int temp = image(i, j, k);
//                                    if (i < image.width / 2) {
//                                        image(i, j, k) = image(image.width - i - 1, j, k);
//                                        image(image.width - i - 1, j, k) = temp;
//
//                                    }
//                                }
//                            }
//                        }  cout << "pls enter image name to store new image\n";
//                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//
//                        cin >> file_name;
//                        image.saveImage(file_name); // save the new image in a file 
//                        system(file_name.c_str());
//
//                    }
//                    else if (choice2 == 2) { //vertically
//                        for (int i = 0; i < image.width; ++i) {
//                            for (int j = 0; j < image.height; ++j) {
//                                for (int k = 0; k < 3; ++k) {
//                                    unsigned int temp = image(i, j, k);
//                                    if (j < image.height / 2) {
//                                        image(i, j, k) = image(i, image.height - j - 1, k);
//                                        image(i, image.height - j - 1, k) = temp;
//
//                                    }
//
//                                }
//
//                            }
//
//                        }  cout << "pls enter image name to store new image\n";
//                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//
//                        cin >> file_name;
//                        image.saveImage(file_name);// save the new image in a file
//                        system(file_name.c_str());
//
//                    }
//                    else {
//                        break;
//                    }
//                    break;
//                }
//
//            }
//            else {
//                cout << "invalid choice ";
//                continue;
//            }
//        }
//    }
//    return 0;
//}

//#include <iostream>
//#include <cstdlib> 
//using namespace std;
//#include "Image_Class.h"
//int main() {
//	int d1, d2;
//	string filename;
//	cout << "Enter the image u wanna crop it ";
//	cin >> filename;
//	
//	Image image(filename);
//	cout << "Enter ur  starting points ";
//	int m, n;
//	cin >> m >> n;
//	cout << "Enter ur dimensions ";
//	cin >> d1 >> d2;
//	Image image1(d1, d2);
//	
//	for (int i = 0; i < d2; i++) {
//		for (int j = 0; j < d1; j++) {
//			for (int k = 0; k < 3; ++k) {
//				image1(i,j,k)=image(i+m, j+n, k);
//				
//				
//			}
//			
//		}
//	}
//	cout << "pls enter image name to store new image\n";
//     cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//     cin >> filename;
//     image1.saveImage(filename);// save the new image in a file
//   system(filename.c_str());
//
//	return 0;
//}
//
//#include <iostream>
//#include <cstdlib> 
//
//using namespace std;
//#include "Image_Class.h"
//int main() {
//	int d1, d2;
//	string filename;
//	cout << "Enter the image u wanna resize it ";
//	cin >> filename;
//
//	Image image(filename);
//	
//	cout << "Enter ur dimensions ";
//	
//	cin >> d1 >> d2;
//	Image image1(d1, d2);
//	
//	double x = double(image.height) / d2;
//
//	double y = double( image.width) / d1;
//	
//
//	for (int i = 0; i < d2; ++i) {
//		for (int j = 0; j < d1; ++j) {
//			int h = round(x * i);
//			int w = round(y * j);
//			for (int k = 0; k < 3; ++k) {
//				image1(j,  i, k) = image(w, h, k);
//
//
//			}
//
//		}
//	}
//	cout << "pls enter image name to store new image\n";
//	cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//	cin >> filename;
//	image1.saveImage(filename);// save the new image in a file
//	system(filename.c_str());
//
//	return 0;
//}



//
//#include <iostream>
//#include <cstdlib> 
//using namespace std;
//#include "Image_Class.h"
//// function to convert from coloured image to gray one 
//int main() {
//    	string filename;
//	cout << "Enter the image u wanna change it ";
//	cin >> filename;
//    Image image(filename);
//	for (int i = 0; i < image.width; ++i) {
//	    for (int j = 0; j < image.height; ++j) {
//		    unsigned  int average = 0; // setting an average value to change the pixels
//		
//		      for (int k = 0; k < 3; ++k) {
//		          average += image(i, j, k); // equating pixel values to the average
//		      }
//		
//		       average /= 3; // Calculate average
//		           
//		            // equating  every channel to the average value
//		            image(i, j, 0) = 255;
//		            image(i, j, 1) = 255- average;
//		            image(i, j, 2) = 255- average;
//		
//		        }
//		    }
//
//
//    cout << "pls enter image name to store new image\n";
//	cout << "and specify extension .jpg, .bmp, .png, .tga: ";
//	cin >> filename;
//	image.saveImage(filename);// save the new image in a file
//	system(filename.c_str());
//
//	return 0;
//}


#include <iostream>
#include <cstdlib>
using namespace std;
#include "Image_Class.h"
// function to convert from coloured image to gray one
void gray(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int avg = 0;// setting an average to 0
            for (int k = 0; k < 3; k++) {
                avg += image(i, j, k);// equating pixel values to the average
            }
            avg /= 3;// Calculate average
            // equating  every channel to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}
// function to convert from coloured image to black&white one
void b_w(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int average = 0; // setting an average value to change the pixels
            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k); // equating pixel values to the average
            }
            average /= 3; // Calculate average
            if (average > 127) {
                average = 255;
            }
            else {
                average = 0;
            }
            // equating  every channel to the average value
            image(i, j, 0) = average;
            image(i, j, 1) = average;
            image(i, j, 2) = average;
        }
    }
}
// function to invert image
void invert(Image& image2) {

    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Reverse the color by subtracting the current value from 255
                image2(i, j, k) = 255 - image2(i, j, k);
            }
        }
    }
}
void merged_crop(Image& image) {
    string im2;
    cout << " enter the file name of the second image to be merged: ";
    cin >> im2;
    Image image2(im2);
    int small_width = min(image.width, image2.width);
    int small_height = min(image.height, image2.height);

    Image newxx(small_width, small_height); //make a new image its dimensions equal to the smallest width and height

    for (int i = 0; i < small_width; i++) {
        for (int j = 0; j < small_height; j++) {
            for (int k = 0; k < 3; k++) {
                newxx(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;
            }
        }
    }
    cout << "Enter the file name to save the merged image: ";
    string filename;
    cin >> filename;
    newxx.saveImage(filename);// save the new image in a file
    system(filename.c_str());
}
void merged_resize(Image& image) {
    string im2;
    cout << " enter the file name of the second image to be merged: ";
    cin >> im2;
    Image image2(im2);
    int biggest_width = max(image.width, image2.width);
    int biggest_height = max(image.height, image2.height);
    Image new_size(biggest_width, biggest_height);//make the first image its dimensions equal to the largest width and height

    for (int i = 0; i < biggest_width; i++) {
        for (int j = 0; j < biggest_height; j++) {
            int row = i * (image.width - 1) / (biggest_width - 1);
            int col = j * (image.height - 1) / (biggest_height - 1);
            new_size.setPixel(i, j, 0, image(row, col, 0));
            new_size.setPixel(i, j, 1, image(row, col, 1));
            new_size.setPixel(i, j, 2, image(row, col, 2));
        }
    }

    Image new_size2(biggest_width, biggest_height);//make the second image its dimensions equal to the smallest width and height

    for (int i = 0; i < biggest_width; i++) {
        for (int j = 0; j < biggest_height; j++) {
            int row = i * (image2.width - 1) / (biggest_width - 1);
            int col = j * (image2.height - 1) / (biggest_height - 1);
            new_size2.setPixel(i, j, 0, image2(row, col, 0));
            new_size2.setPixel(i, j, 1, image2(row, col, 1));
            new_size2.setPixel(i, j, 2, image2(row, col, 2));
        }
    }

    Image merged(biggest_width, biggest_height);
    for (int i = 0; i < biggest_width; i++) {
        for (int j = 0; j < biggest_height; j++) {
            for (int k = 0; k < 3; k++) {
                int pixel1 = new_size(i, j, k);
                int pixel2 = new_size2(i, j, k);
                int merged_pixel = (pixel1 + pixel2) / 2; //merge the two image together
                merged.setPixel(i, j, k, merged_pixel);
            }
        }
    }
    cout << "Enter the file name to save the merged image: ";   string filename;
    cin >> filename;
    merged.saveImage(filename); // save the new image in a file
    system(filename.c_str());

}
void flip_horiz(Image& image) {
    for (int i = 0; i < image.width; ++i) {

        for (int j = 0; j < image.height; ++j) {

            for (int k = 0; k < 3; ++k) {
                unsigned int temp = image(i, j, k);
                if (i < image.width / 2) {
                    image(i, j, k) = image(image.width - i - 1, j, k);
                    image(image.width - i - 1, j, k) = temp;

                }

            }

        }

    }
}
void flip_vert(Image& image) {
    for (int i = 0; i < image.width; ++i) {

        for (int j = 0; j < image.height; ++j) {

            for (int k = 0; k < 3; ++k) {
                unsigned int temp = image(i, j, k);
                if (j < image.height / 2) {
                    image(i, j, k) = image(i, image.height - j - 1, k);
                    image(i, image.height - j - 1, k) = temp;
                }
            }
        }
    }
}
void brightness(Image& image)
{
    int w = image.width;
    int h = image.height;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            unsigned char red = image.getPixel(i, j, 0);
            unsigned char green = image.getPixel(i, j, 1);
            unsigned char blue = image.getPixel(i, j, 2);
            auto r = min(255.0, red * 1.5);
            auto g = min(255.0, green * 1.5);
            auto b = min(255.0, blue * 1.5);

            red = static_cast<unsigned char>(r);
            green = static_cast<unsigned char>(g);
            blue = static_cast<unsigned char>(b);

            image.setPixel(i, j, 0, red);
            image.setPixel(i, j, 1, green);
            image.setPixel(i, j, 2, blue);
        }
    }

}
void darkness(Image& image)
{
    int w = image.width;
    int h = image.height;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            unsigned char red = image.getPixel(i, j, 0);
            unsigned char green = image.getPixel(i, j, 1);
            unsigned char blue = image.getPixel(i, j, 2);

            red = static_cast<unsigned char>(red * 0.5);
            green = static_cast<unsigned char>(green * 0.5);
            blue = static_cast<unsigned char>(blue * 0.5);

            image.setPixel(i, j, 0, red);
            image.setPixel(i, j, 1, green);
            image.setPixel(i, j, 2, blue);
        }
    }
}
void crop(Image& image) {
    int d1, d2;
    cout << "Enter ur  starting points ";
    int m, n;
    cin >> m >> n;
    cout << "Enter ur dimensions ";
    cin >> d1 >> d2;
    Image image1(d1, d2);
    for (int i = 0; i < d2; i++) {
        for (int j = 0; j < d1; j++) {
            for (int k = 0; k < 3; ++k) {
                image1(i, j, k) = image(i + m, j + n, k);
            }
        }
    }          cout << "pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    string filename;
    cin >> filename;
    image1.saveImage(filename);// save the new image in a file
    system(filename.c_str());

}
void edged_image(Image& image) {
    int sobel_x[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int sobel_y[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };
    int height = image.height;
    int width = image.width;
    Image edge(width, height);
    // Convert the image to grayscale and perform edge detection
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int avg = 0;
            for (int k = 0; k < 3; k++) {
                avg += image(x, y, k);
            }
            avg /= 3;
            image(x, y, 0) = avg;
            image(x, y, 1) = avg;
            image(x, y, 2) = avg;

            // Edge detection
            if (x > 0 && x < width - 1 && y > 0 && y < height - 1) {
                int Gx = 0, Gy = 0;
                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {
                        int pixell = image(x + i, y + j, 0);
                        Gx += sobel_x[j + 1][i + 1] * pixell;
                        Gy += sobel_y[j + 1][i + 1] * pixell;
                    }
                }

                double result = sqrt(Gx * Gx + Gy * Gy);

                if (result > 255) {
                    result = 225;
                }
                edge.setPixel(x, y, 0, result);
                edge.setPixel(x, y, 1, result);
                edge.setPixel(x, y, 2, result);
            }
        }
    } for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixell = edge(x, y, 0);
            int invertedVal = 255 - pixell;
            edge(x, y, 0) = invertedVal;
            edge(x, y, 1) = invertedVal;
            edge(x, y, 2) = invertedVal;
            if (invertedVal > 127) {
                edge(x, y, 0) = 255;
                edge(x, y, 1) = 255;
                edge(x, y, 2) = 255;
            }

        }
    }
    string Filename;
    cout << "enter the file name to save new image; ";
    cin >> Filename;
    edge.saveImage(Filename);
    system(Filename.c_str());
}
void resize(Image& image) {
    int d1, d2;
    cout << "Enter ur dimensions ";
    cin >> d1 >> d2;
    Image image1(d1, d2);
    double x = double(image.height) / d2;
    double y = double(image.width) / d1;
    for (int i = 0; i < d2; ++i) {
        for (int j = 0; j < d1; ++j) {
            int h = round(x * i);
            int w = round(y * j);
            for (int k = 0; k < 3; ++k) {
                image1(j, i, k) = image(w, h, k);
            }
        }
    }cout << "pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    string filename;
    cin >> filename;
    image1.saveImage(filename);// save the new image in a file
    system(filename.c_str());
}
void purple(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            green = green * 0.7; //to decrease green colour
            image.setPixel(i, j, 0, red);
            image.setPixel(i, j, 1, green);
            image.setPixel(i, j, 2, blue);

        }
    }
}
void infrared(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int average = 0; // setting an average value to change the pixels

            for (int k = 0; k < 3; ++k) {
                average += image(i, j, k); // equating pixel values to the average
            }

            average /= 3; // Calculate average

            // equating  every channel to the average value
            image(i, j, 0) = 255;
            image(i, j, 1) = 255 - average;
            image(i, j, 2) = 255 - average;
        }
    }
}
int main() {
    cout << "Enter name of the picture ";
    string filename;
    cin >> filename;
    Image image(filename);
    int choice, cot;
    while (true) {
        cout << "Do u wanna exit?\n 1) yes\n 2) no "; // make the user to choose if he want to continue or not
        cin >> cot;
        if (cot == 1) {
            cout << "end of program";
            break;
        }
        if (cot == 2){
            cout << "choose:\n 1) Grayscale conversion\n 2) Black and white\n 3) Invert image\n 4) merge images\n 5) flip image \n 6) darken and lighten\n 7) crop \n 8) edge detection\n 9) resize\n 10) purple\n 11)infrared\n";
            cout << "Enter your choice";
            cin >> choice;
            if (choice == 1) { // grayscale
                gray(image); // call the function which convert the image into gray
                cout << "pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                string file_name;
                cin >> file_name;
                image.saveImage(file_name);// save the new image in a file
                system(file_name.c_str());
                continue;
            }
            if (choice == 2) { //black&white
                b_w(image); // call the function which convert the image into gray
                string file_name;
                cout << "pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:";
                cin >> file_name;
                image.saveImage(file_name);// save the new image in a file
                system(file_name.c_str());
                continue;
            }
            if (choice == 3) { //invert
                invert(image); // call the function which invert the image
                string file_name;
                cout << "pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga:";
                cin >> file_name;

                image.saveImage(file_name);// save the new image in a file
                system(file_name.c_str());
                continue;
            }
            if (choice == 4) { //merge
                int choice2;
                cout << "Do you want to merge photos with crop or resize?\n"
                    << "1) Crop\n"
                    << "2) Resize\n";
                while (true) {
                    cin >> choice2;
                    if (choice2 == 1) { // by crop
                        merged_crop(image);
                        break;
                    }
                    if (choice2 == 2) {
                        merged_resize(image);
                        break;
                    }
                    else {
                        cout << "invalid choice ";
                    }
                }
            }
            if (choice == 5) {

                int choice2;
                cout << "Do you want to flip photo horizontal or vertical?\n"
                    << "1) horizontal\n"
                    << "2) vertical\n";
                while (true) {
                    cin >> choice2;
                    if (choice2 == 1) { // horizontal
                        flip_horiz(image);
                        cout << "pls enter image name to store new image\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        string file_name;
                        cin >> file_name;
                        image.saveImage(file_name);
                        system(file_name.c_str());
                        break;
                    }
                    if (choice2 == 2) {
                        flip_vert(image);
                        cout << "pls enter image name to store new image\n";
                        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                        string file_name;
                        cin >> file_name;
                        image.saveImage(file_name);
                        system(file_name.c_str());
                        break;
                    }
                    else {
                        cout << "invalid choice ";
                    }
                }
            }
            if (choice == 6) {
                int choice2;
                cout << "Do yoy want darken or lighten ?\n";
                cout << "1) lighten \n 2) darken\n";
                while (true) {
                    cin >> choice2;
                    if (choice2 == 1) {
                        brightness(image);
                        string filename2;
                        cout << "Enter the filename to save the modified image: ";
                        cin >> filename2;
                        image.saveImage(filename2);
                        system(filename2.c_str());
                        break;
                    }
                    if (choice2 == 2) {
                        darkness(image);
                        string filename2;
                        cout << "Enter the filename to save the modified image: ";
                        cin >> filename2;
                        image.saveImage(filename2);
                        system(filename2.c_str());
                        break;
                    }
                    else {
                        cout << "invalid choice";
                    }
                }
            }

            if (choice == 7) {
                crop(image);
                continue;
            }if (choice == 8) {
                edged_image(image);
                continue;
            }if (choice == 9) {
                resize(image);
                continue;
            }
            if (choice == 10) {
                purple(image);
                cout << "pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                string filename;
                cin >> filename;
                image.saveImage(filename);// save the new image in a file
                system(filename.c_str());
            }
            if (choice == 11) {
                infrared(image);
                cout << "pls enter image name to store new image\n";
                cout << "and specify extension .jpg, .bmp, .png, .tga: ";
                cin >> filename;
                image.saveImage(filename);// save the new image in a file
                system(filename.c_str());

            }
            else {
                cout << "invalid choice ";
                continue;
            }
        }
        else {
            cout << " Inavlid choice";
        }
    }
    return 0;
}