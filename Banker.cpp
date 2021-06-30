#include <bits/stdc++.h>
using namespace std;
#define ROW 100
#define COL 100
void TableNeed(int p, int r, int need[ROW][COL], int max[ROW][COL],
int allot[ROW][COL])
{
    for (int i = 0 ; i < p ; i++)
        for (int j = 0 ; j < r ; j++)
            need[i][j] = max[i][j] - allot[i][j]; //tinh bang Need
}
bool solve (int p, int r, int processes[], int avail[], int max[ROW][COL],
            int allocation[ROW][COL], int need[ROW][COL]){
    int work[r];
    for (int i = 0; i < r ; i++)
        work[i] = avail[i]; // Tao work
    bool finish[p] = {false};
    
    string safe; // khoi tao string luu chuoi an toan
    for (int i = 0; i < p; i++){
        bool found = false;
        for (int proc = 0; proc < p; proc++){
            if (finish[proc] == false){
                int j = 0 ;
                for (j = 0; j < r; j++){
                    if (need[proc][j] > work[j])
                        break;// Xet dieu kien neu finish = false nhung need thu i > work i thi break
                }
                    
                if (j == r){
                    for (int k = 0 ; k < r ; k++)
                        work[k] += allocation[proc][k]; // cap nhat lai work
                    safe += to_string(proc) + " ";
                    finish[proc] = true;
                    found = true;
                    i++;
                }
            }
        }
        if (found == false){
            cout <<"He thong khong an toan";
            cout <<"\nCo kha nang xay ra Deadlock";
            cout <<"\nKhong tim thay chuoi an toan";
            return false;
        }
    }
    cout <<"He thong an toan";
    cout <<"\nKhong phat hien Deadlock";
    cout <<"\nTim thay chuoi an toan: "<<safe;
    return true;
    
}
void xuatMang(int mt[][COL], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mt[i][j] << "\t";
		}
		cout << endl;
	}
}
int main (){
    int p, r;
    cout <<"nhap process p va resources r:  \n";
    cin >>p>>r;
    cout <<"\nnhap "<<p<<" process: ";
    int process[p];
    for (int i = 0; i <p; i++){
        process[i] = i;
    }
    int available[r];
    cout <<"\nnhap "<<r<<" gia tri available: ";
    for (int i = 0; i <r; i++){
        cin >> available[i];
    }
    int max[p][100];
    cout <<"\nnhap table max: \n";
    for (int i = 0; i <p; i++){
        for (int j = 0; j <r; j++){
            cin >> max[i][j];
        }
    }
    // xuatMang(max,p,r);
    // cout <<endl;
    cout <<"\nnhap table allocation: \n";
    int allocation[p][100];
    for (int i = 0; i <p; i++){
        for (int j = 0; j <r; j++){
            cin >>allocation[i][j];
        }
    }
    // xuatMang(allocation,p,r);
    
    int need[ROW][COL];
    TableNeed(p,r,need,max,allocation);
    cout <<"Table Need: \n";
    xuatMang(need,p,r);
    cout <<endl;
    solve (p, r, process, available, max, allocation, need);
    
    return 0;
}
//5 3
//3 3 2
//7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
//0 1 0 2 0 0 3 0 2 2 1 1 0 0 2

