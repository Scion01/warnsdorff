#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int x[10] = {-2,+2,-2,+2,+3,-3,0,0};
int y[10] = {-2,+2,+2,-2,0,0,+3,-3};
 
int runner = 0;
int check_limit(int x,int y){
    if (x>=0 && x<10 && y>=0 && y<10)
        return 1;
    return 0;
}

int get_degree(int visited[10][10], int p,int q){
    int count =0;
    for(int i=0;i<8;++i)
        if(check_limit(p+x[i],q+y[i]) && !visited[p+x[i]][q+y[i]])
            ++count;
    return count;
}

void print_moves(int moves[10][10]){
    for(int i=0;i<10;++i){
            for(int j=0;j<10;++j){
                cout<<moves[i][j]<<" ";
            }
            cout<<endl;
        }
}

int check_completion(int visited[10][10]){
    for(int i=0;i<10;++i)
        for(int j=0;j<10;++j)
            if(!visited[i][j])
                return 0;
    return 1;
}

int check_moves(int visited[10][10], int moves[10][10], int p, int q, int count){
    // cout<<p<<q<<endl;
    // print_moves(moves);
    // ++runner;
    if(check_completion(visited))
        return 1;
    int minx=-1,miny=-1,min=1000;
    for(int i=0;i<10;++i){
        if(check_limit(p+x[i],q+y[i]) && !visited[p+x[i]][q+y[i]]){
            int temp = get_degree(visited,p+x[i],q+y[i]);
            if(temp<min){
                min =temp;
                minx = p+x[i];
                miny = q+y[i];
            }
        }
    }
    // cout<<minx<<miny<<endl;
    if(minx!=-1){
        visited[minx][miny] = 1;
        moves[minx][miny] = count+1;
        return check_moves(visited,moves,minx,miny,count+1);
    }
    return 0;   
}
int main(){
    int visited[10][10] = {{0}};
    int moves[10][10] = {{0}};
    int p,q;
    cin>>p>>q;
    moves[p][q] = 1;
    visited[p][q] = 1;
 
    if(check_moves(visited,moves,p,q,1))
        cout<<"Done!"<<endl;
    else
        cout<<"Does not exist!"<<endl;
    print_moves(moves);
    return 0;
}