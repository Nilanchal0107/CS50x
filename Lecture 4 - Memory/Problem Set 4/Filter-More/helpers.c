#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round(
                (image[i][j].rgbtRed +
                 image[i][j].rgbtGreen +
                 image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image (box blur)
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Copy original image
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalR = 0, totalG = 0, totalB = 0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height &&
                        nj >= 0 && nj < width)
                    {
                        totalR += copy[ni][nj].rgbtRed;
                        totalG += copy[ni][nj].rgbtGreen;
                        totalB += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float) totalR / count);
            image[i][j].rgbtGreen = round((float) totalG / count);
            image[i][j].rgbtBlue = round((float) totalB / count);
        }
    }
}

// Detect edges using Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] =
    {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    // Copy original
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRx = 0, sumGx = 0, sumBx = 0;
            int sumRy = 0, sumGy = 0, sumBy = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < height &&
                        nj >= 0 && nj < width)
                    {
                        int kx = Gx[di + 1][dj + 1];
                        int ky = Gy[di + 1][dj + 1];

                        sumRx += copy[ni][nj].rgbtRed * kx;
                        sumGx += copy[ni][nj].rgbtGreen * kx;
                        sumBx += copy[ni][nj].rgbtBlue * kx;

                        sumRy += copy[ni][nj].rgbtRed * ky;
                        sumGy += copy[ni][nj].rgbtGreen * ky;
                        sumBy += copy[ni][nj].rgbtBlue * ky;
                    }
                }
            }

            int finalR = round(sqrt(sumRx * sumRx + sumRy * sumRy));
            int finalG = round(sqrt(sumGx * sumGx + sumGy * sumGy));
            int finalB = round(sqrt(sumBx * sumBx + sumBy * sumBy));

            if (finalR > 255) finalR = 255;
            if (finalG > 255) finalG = 255;
            if (finalB > 255) finalB = 255;

            image[i][j].rgbtRed = finalR;
            image[i][j].rgbtGreen = finalG;
            image[i][j].rgbtBlue = finalB;
        }
    }
}