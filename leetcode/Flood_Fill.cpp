#include<iostream>
#include<vector>
using namespace std;
// 題目 :
// An image is represented by a 2 - D array of integers,
// each integer representing the pixel value of the image(from 0 to 65535).

// Given a coordinate(sr, sc) representing the starting pixel(row and column) of the flood fill,
// and a pixel value newColor, "flood fill" the image.

//                             To perform a "flood fill",
// consider the starting pixel,
// plus any pixels connected 4 - directionally to the starting pixel of the same color as the starting pixel,
// plus any pixels connected 4 - directionally to those pixels(also with the same color as the starting pixel),
// and so on.Replace the color of all of the aforementioned pixels with the newColor.

// At the end,
// return the modified image.

//     Example 1 : Input : 
//            0 1 2 row(行) 這裡有兩個row
// image = 0[[1,1,1], 1st row
//         1 [1,1,0], 2ed row
//              ^ row=1 column=1       
//         2 [1,0,1]]
// sr = 1, sc = 1, newColor = 2

// Output: [[2,2,2], 從(1,1)擴散 只要值與(1,1)相同則上下左右也跟者改變(newcolor)，並改變基準點
//          [2,2,0],
//          [2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
// Note:

// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535]

//***要先改成-1(不再範圍內的值) 因為當target=newColor會跑不出遞迴 當然也可以直接 if(target!=newColor)在呼叫(更下面的有)
void change_color(vector<vector<int>>& image,int newrow,int newcolum,int row,int column,int target)
{
    if(newrow>=row||newcolum>=column||newrow<0||newcolum<0)
        return;
    if(image[newrow][newcolum]!=target)
        return;
    image[newrow][newcolum] = -1;
    change_color(image, newrow + 1, newcolum, row, column, target);
    change_color(image, newrow - 1, newcolum, row, column, target);
    change_color(image, newrow , newcolum + 1, row, column, target);
    change_color(image, newrow , newcolum - 1, row, column, target);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int row = image.size(); //2
    int column = image[0].size(); //3
    int target = image[sr][sc];//1
    change_color(image,sr, sc, row, column, target);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(image[i][j]==-1)
                image[i][j]=newColor;
        }
    }
        
    return image;
}

void change_color2(vector<vector<int>>& image,int newrow,int newcolum,int row,int column,int target,int newColor)
{
    if(newrow>=row||newcolum>=column||newrow<0||newcolum<0)
        return;
    if(image[newrow][newcolum]!=target)
        return;
    image[newrow][newcolum] = newColor;
    change_color2(image, newrow + 1, newcolum, row, column, target,newColor);
    change_color2(image, newrow - 1, newcolum, row, column, target,newColor);
    change_color2(image, newrow , newcolum + 1, row, column, target,newColor);
    change_color2(image, newrow , newcolum - 1, row, column, target,newColor);
}

vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int row = image.size(); //2        [0,0,0]
    int column = image[0].size(); //3  [0,1,1]
    int target = image[sr][sc];//1
    if(target!=newColor)
        change_color2(image,sr, sc, row, column, target,newColor);
    return image;
}