// Created by Lenovo on 12/31/2023.
#include <iostream>
#include <vector>
using namespace std;
const int Max_size=10;
bool Maze(char Board[Max_size][Max_size],int row,int column){
    Board[row][column]='@';
    cout<<"----------------------"<<endl;
    cout<<"row is "<<row<<" , "<<"column is "<<column<<endl;
    cout<<"----------------------"<<endl;
    for(int i = 0; i < Max_size; ++i) {
        for (int j = 0; j < Max_size; ++j)
            cout << Board[i][j] << ' ';
        cout<<endl;
    }
    if(row==Max_size-1 && column==Max_size-1)
        return true;
    //horizontally right
    if(row<Max_size-1 && Board[row+1][column]=='o' && Maze(Board,row+1,column))
            return true;
    //horizontally left
    if(row>0 && Board[row-1][column]=='o' && Maze(Board,row-1,column))
            return true;
    //vertically up
    if(column<Max_size-1 && Board[row][column+1]=='o' && Maze(Board,row,column+1))
            return true;
    //vertically down
    if(column>0 && Board[row][column-1]=='o' && Maze(Board,row,column-1))
            return true;
    Board[row][column]='#';
    return false;
}
int main() {
    char Board[Max_size][Max_size] = {
            {'o', '1', '1', 'o', '1', 'o', 'o', 'o', '1', 'o'},
            {'o', 'o', '1', 'o', 'o', 'o', '1', 'o', 'o', 'o'},
            {'1', 'o', '1', '1', 'o', '1', '1', 'o', 'o', 'o'},
            {'o', 'o', 'o', 'o', 'o', '1', '1', '1', '1', 'o'},
            {'o', '1', '1', 'o', '1', '1', '1', 'o', '1', 'o'},
            {'o', '1', '1', 'o', 'o', 'o', '1', 'o', 'o', 'o'},
            {'o', '1', '1', 'o', 'o', 'o', '1', 'o', '1', '1'},
            {'o', '1', '1', 'o', 'o', '1', '1', 'o', 'o', 'o'},
            {'o', '1', '1', 'o', 'o', '1', '1', '1', '1', 'o'},
            {'o', '1', '1', 'o', 'o', '1', '1', 'o', 'o', 'o'},};
    if(Maze(Board,0,0)){
        for(int i = 0; i < Max_size; ++i) {
            for (int j = 0; j < Max_size; ++j)
                cout << Board[i][j] << ' ';
            cout<<endl;
        }
        return 0;
    }
    cout<<"Unreachable!";
    return 0;
}
