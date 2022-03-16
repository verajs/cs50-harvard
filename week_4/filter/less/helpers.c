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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sepiaRed1 = (image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189);
            int sepiaRed = round(sepiaRed1);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            double sepiaGreen1 = (image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168);
            int sepiaGreen = round(sepiaGreen1);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            double sepiaBlue1 = (image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131);
            int sepiaBlue = round(sepiaBlue1);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
