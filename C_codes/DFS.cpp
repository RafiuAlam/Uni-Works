#include <bits/stdc++.h>
using namespace std;

int graph[200][200];
int status[200];

struct node
{
    int val;
    node* next;

    node(int x)
    {
        val = x;
        next = NULL;
    }
};
node* head;

bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int nodeE)
{
    node *n = new node(nodeE);

    if (isEmpty())
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

int pop()
{
    int item = 0;
    node *temp = head;
    if (isEmpty())
    {
        return item;
    }
    else
    {
        item = temp->val;
        head = temp->next;
        delete temp;
        return item;
    }
}

void inputGraph(int N, int E)
{
    int src, des, weight;
    weight = 1;

    cout<< "Edges: " << endl;
    for (int i = 1; i <= E; i++)
    {
        cin >> src >> des;
        graph[src][des] = weight;
        graph[des][src] = weight;
    }

}

void printAM(int N)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
}

void initStatus(int N)
{
    for (int i = 1; i <= N; i++)
    {
        status[i] = 1;
    }
}

void addNeighbors(int nodeN, int n)
{
    for (int i = n; i >= 1; i--)
    {
        if (graph[nodeN][i] == 1 && status[i] == 1)
        {
            push(i);
            status[i] = 2;
        }
    }
}

void dfs(int source, int n)
{
    //step 1
    initStatus(n);
    head = NULL;

    //step 2
    push(source);
    status[source] = 2;

    //step 3
    while(!isEmpty())
    {
        //step 4
        int nodeN;
        nodeN=pop();
        cout << nodeN;
        status[nodeN] = 3;


        //step 5
        addNeighbors(nodeN,n);

    }


}

int main()
{
    int n, e, source;
    printf("Enter no of Node: ");
    scanf("%d",&n);

    printf("Enter no of Edge: ");
    scanf("%d", &e);

    printf("Enter Source: ");
    scanf("%d", &source);
    inputGraph(n,e);
    printAM(n);
    dfs(source,n);

    return 0;
}


