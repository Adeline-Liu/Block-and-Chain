#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
    return data.size();
}
int Block::height() const
{
    return data[0].size();
}

void Block::render(PNG &im, int column, int row) const
{
    for (int x = 0; x < width(); x++) {
        for (int y = 0; y < height(); y++) {
            * im.getPixel(column + x, row + y) = data[x][y];
        }
    }
}

void Block::build(PNG &im, int column, int row, int width, int height)
{

    data.resize(width, vector<RGBAPixel>(height));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            data[x][y] = * im.getPixel(column + x, row + y);
        }
    }
}

void Block::flipVert()
{
    int h = height();

    int mid;
    if(h%2 == 0) {
         mid = h/2;
    } else {
    mid = h/2+1;
    }

    for (int x = 0; x < width(); x++) {
        for (int y = 0; y < height() / 2; y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[x][y + mid];
            data[x][y + mid] = temp;
        }
    }
}

void Block::flipHoriz()
{
    int w = width();

    int mid;
    if (w%2 == 0) {
         mid = w/2;
    } else {
         mid = w/2+1;
    }

    for (int x = 0; x < width() / 2; x++) {
        for (int y = 0; y < height(); y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[x + mid][y];
            data[x + mid][y] = temp;
        }
    }
}

void Block::rotateRight()
{

    /* for (int x = 0; x < width(); x++) {
        for (int y = 0; y < height(); y++) {
            RGBAPixel temp = data[x][y];
            date[x][y] = data[width-y-1][x];
            data
        }
    } */

    for(int x = 0; x < height() - height() / 2; x++) {
        for(int y = 0; y < height() / 2; y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[y][height()-1-x];
            data[y][height()-1-x] = data[height()-1-x][height()-1-y];
            data[height()-1-x][height()-1-y] = data[height()-1-y][x];
            data[height()-1-y][x] = temp;
        }
    } 
    
    /* for (int i = 0; i < height() / 2; i++) {
        for (int j = i; j < width() - i - 1; j++) {
 
            RGBAPixel temp = data[i][j];

            data[i][j] = data[height() - 1 - j][i];
            data[height() - 1 - j][i] = data[height() - 1 - i][width() - 1 - j];
            data[height() - 1 - i][width() - 1 - j] = data[j][width() - 1 - i];
            data[j][width() - 1 - i] = temp;
        }
    } */
}
