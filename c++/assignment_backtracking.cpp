#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_from(int from[10][10],int size){
    for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                cout<<from[i][j]<<" ";
            }
            cout<<endl;
        }
}

int check_all_visited(int visited[10][10],int size){
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            if(!visited[i][j])
                return 0;
    return 1;
}

int check_solution(int visited[10][10], int from[10][10], int size, int p, int q){

    if(check_all_visited(visited,size))
        return 1;
     
    if(p-2>=0 && q-2>=0 && !visited[p-2][q-2]){
        from[p-2][q-2] = p*size+q;
        visited[p-2][q-2] = 1;
        if(check_solution(visited,from,size,p-2,q-2))
            return 1;
        else{
            from[p-2][q-2] = 0;
            visited[p-2][q-2] = 0;
        }
    }
    if(p+2<size && q-2>=0 && !visited[p+2][q-2]){
        from[p+2][q-2] = p*size+q;
        visited[p+2][q-2] = 1;
        if(check_solution(visited,from,size,p+2,q-2))
            return 1;
        else{
            from[p+2][q-2] = 0;
            visited[p+2][q-2] = 0;
        }
    }
    if(p+2<size && q+2<size && !visited[p+2][q+2]){
        from[p+2][q+2] = p*size+q;
        visited[p+2][q+2] = 1;
        if(check_solution(visited,from,size,p+2,q+2))
            return 1;
        else{
            from[p+2][q+2] = 0;
            visited[p+2][q+2] = 0;
        }
    }
    if(p-2>=0 && q+2<size && !visited[p-2][q+2]){
        from[p-2][q+2] = p*size+q;
        visited[p-2][q+2] = 1;
        if(check_solution(visited,from,size,p-2,q+2))
            return 1;
        else{
            from[p-2][q+2] = 0;
            visited[p-2][q+2] = 0;
        }
    }
    if(p-3>=0 && !visited[p-3][q]){
        from[p-3][q] = p*size+q;
        visited[p-3][q] = 1;
        if(check_solution(visited,from,size,p-3,q))
            return 1;
        else{
            from[p-3][q] = 0;
            visited[p-3][q] = 0;
        }
    }
    if(p+3<size && !visited[p+3][q]){
        from[p+3][q] = p*size+q;
        visited[p+3][q] = 1;
        if(check_solution(visited,from,size,p+3,q))
            return 1;
        else{
            from[p+3][q] = 0;
            visited[p+3][q] = 0;
        }
    }
    if(q+3<size && !visited[p][q+3]){
        from[p][q+3] = p*size+q;
        visited[p][q+3] = 1;
        if(check_solution(visited,from,size,p,q+3))
            return 1;
        else{
            from[p][q+3] = 0;
            visited[p][q+3] = 0;
        }
    }
    if(q-3>=0 && !visited[p][q-3]){
        from[p][q-3] = p*size+q;
        visited[p][q-3] = 1;
        if(check_solution(visited,from,size,p,q-3))
            return 1;
        else{
            from[p][q-3] = 0;
            visited[p][q-3] = 0;
        }
    }
    return 0;
}

int main(){
    //10 is the given size, can be dynamic as well
    int size = 10;
    int from[10][10] = {{0}};
    int visited[10][10] = {{0}};
    int p,q;
    cout<<"Enter the starting co-ords of the pawn: "<<endl;
    cin>>p>>q;
    --p;
    --q;
    visited[p][q] =1;
    from[p][q] = -1;
    if(check_solution(visited,from,size,p,q))
        cout<<"Done!"<<endl;
    else
        cout<<"Not possible without visiting more than once, prinitng what we have: "<<endl;
    print_from(from,size);
}