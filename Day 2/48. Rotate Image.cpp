#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &image)
{
    int rows = image.size(), cols = image[0].size();
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int rows,cols;
    cout<<"Enter number of rows and cols: ";
    cin>>rows>>cols;
    vector<vector<int>> image(rows, vector<int> (cols)); // declaring 2D vector of size rows , vectors each of size cols

    vector<vector<int>> image_90(rows, vector<int> (cols)); 
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin>>image[i][j];
        }
    }


    cout<<endl<<"2D vector: "<<endl;
    display(image);

    cout<<endl<<"2D vector after 90 degree rotation: "<<endl; // using auxarily vector
    for(int i = 0,k = cols-1 ; i<rows, k>= 0; i++, k--)
    {
        for(int j = 0, l = 0; j < cols, l < rows; j++, l++)
        {
            image_90[l][k] = image[i][j];
        }
    }

    display(image_90);

    return 0;
}

// T ==> O(2(n^2)) ---> using auxarily matrix making its 1st row as last coln of new matrix 
// S ==> O(N^2)

//Optimal soln 
// T ==> O(N^2) ---> 1st transpose then reverse each row it rotates matrix by 90 degree
// S ==> O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n ; i++)
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        for(int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};