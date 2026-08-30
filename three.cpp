#include<bits/stdc++.h>
using namespace std;

void droneServicesSchedule(int arr[][2], int M, int N)
{
    unordered_map<bool,vector<bool>>graph;

    for (int i = 0; i < M; i++)
    {
        int u = arr[i][0] - 1;
        int v = arr[i][1] - 1;

        graph[u][v] = true;
        graph[v][u] = true;
    }

    vector<int> x(N, -1);

    x[0] = 0;

    for (int i = 1; i < N; i++)
    {
        if (graph[0][i])
        {
            x[i] = 0;
        }
        else
        {
            x[i] = 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (graph[i][j])
            {
                if (x[i] != x[j])
                {
                    cout << "Not a Complete Day" << endl;
                    return;
                }
            }
            else
            {
                if (x[i] == x[j])
                {
                    cout << "Not a Complete Day" << endl;
                    return;
                }
            }
        }
    }

    cout << "Complete Day" << endl;
}

int main()
{
    int T;
    cin >> T;

    int N, M;

    for (int j = 0; j < T; j++)
    {
        cin >> N >> M;

        int arr[M][2];

        for (int i = 0; i < M; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }

        droneServicesSchedule(arr, M, N);
    }

    return 0;
}