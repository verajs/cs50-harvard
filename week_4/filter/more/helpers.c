#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avg2 = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int avg = round(avg2);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create copy of the original image
    RGBTRIPLE copy[height][width];

    //Four nested loops, first two are to get needed pixels, other two are to get the 3x3 grid
    for (int a = 0; a < height; a++)
    {
        //Loop for width
        for (int b = 0; b < width; b++)
        {
            //declaring variables again to set them to 0 each time we go to next pixel
            float ravg = 0;
            float gavg = 0;
            float bavg = 0;
            float counter = 0;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    //Condition that takes edge cases into account
                    if (i + a < 0 || i + a > (height - 1) || b + j < 0 || b + j > (width - 1))
                    {
                        continue;
                    }
                    //Assign all rgb pixel values into their variables to average them later
                    ravg += image[a + i][b + j].rgbtRed;
                    gavg += image[a + i][b + j].rgbtGreen;
                    bavg += image[a + i][b + j].rgbtBlue;
                    counter++;
                }
            }
            //Asign new averaged color values into the copy file
            copy[a][b].rgbtRed = round(ravg / counter);
            copy[a][b].rgbtGreen = round(gavg / counter);
            copy[a][b].rgbtBlue = round(bavg / counter);
        }
    }

    //Copying temp copy image into the original one
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Make copy of the original image
    RGBTRIPLE copy[height][width];

    //Declare sobel 2D arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //Loop through through the height of the image
    for (int i = 0; i < height; i++)
    {
        //Loop through the width of the image
        for (int j = 0; j < width; j++)
        {
            //Set all variables to 0 for each pixel
            float Gx_r = 0;
            float Gx_g = 0;
            float Gx_b = 0;
            float Gy_r = 0;
            float Gy_g = 0;
            float Gy_b = 0;
            //Loop for 2d 3x3 array
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    //Taking edge cases into account
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }
                    if (l + j < 0 || l + j > width - 1)
                    {
                        continue;
                    }
                    //Doing sobel filter math
                    Gx_r += image[i + k][l + j].rgbtRed * Gx[k + 1][l + 1];
                    Gx_g += image[i + k][l + j].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_b += image[i + k][l + j].rgbtBlue * Gx[k + 1][l + 1];
                    Gy_r += image[i + k][l + j].rgbtRed * Gy[k + 1][l + 1];
                    Gy_g += image[i + k][l + j].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_b += image[i + k][l + j].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
            //Doing final Gx values
            int red = round(sqrt(Gx_r * Gx_r + Gy_r * Gy_r));
            int green = round(sqrt(Gx_g * Gx_g + Gy_g * Gy_g));
            int blue = round(sqrt(Gx_b * Gx_b + Gy_b * Gy_b));

            //Locking values to 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            //Adding values into copy image
            copy[i][j].rgbtRed = red;
            copy[i][j].rgbtGreen = green;
            copy[i][j].rgbtBlue = blue;
        }
    }

//Copying copy image into the original one
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
            image[i][j] = copy[i][j];
            image[i][j] = copy[i][j];
        }
    }
    return;
}

