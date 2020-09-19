#include<iostream>

#include<cstdlib>

using namespace std;

int sudoku[9][9];

int safety_no=0;

int counter=0;


struct linked_values

{

    int data;

    int row,col;

    linked_values *prev;

    linked_values *next;



};

void read_sudoku()

{

    for(int i=0;i<9;i++)

    {

        for(int j=0;j<9;j++)

        {

            cin>>sudoku[i][j];

        }

    }



    for(int i=0;i<9;i++)

    {

        for(int j=0;j<9;j++)

        {

            cout<<sudoku[i][j];

            cout<<" ";

        }

        cout<<endl;

    }

}



int check_safety(int data,int i,int j)

{

    int flag=0;



    if(flag==0)

    {

    for(int a=0;a<9;a++)

    {

        if(sudoku[a][j]==data)

        {



            flag=1;

        }

    }

    }

    if(flag==0)

    {

    for(int a=0;a<9;a++)

    {

        if(sudoku[i][a]==data)



        flag=1;

    }

    }



    if(flag==0)

   {

    int dummyi=i/3,dummyj=j/3;

    i=dummyi*3;

    j=dummyj*3;

    dummyi=i+3;

    dummyj=j+3;



    for(int a=i;a<dummyi;a++)

    {

        for(int b=j;b<dummyj;b++)

        {

            if(sudoku[a][b]==data)



            flag=1;

        }

    }

    }

    if(flag==0)

    return 1;

    else

    return 0;



}



linked_values* attach_node(linked_values* head)

{

    linked_values* temp=(linked_values*)malloc(sizeof(linked_values));

    head->next=temp;

    temp->data=1;

    temp->prev=head;

    temp->next=NULL;

    temp->row=0;

    temp->col=0;

    return temp;

}



void solve_sudoku()

{

    linked_values* head=(linked_values*)malloc(sizeof(linked_values));



    head->data=1;

    head->row=0;

    head->col=0;

    head->next=NULL;

    head->prev=NULL;

 LOOP:

 for(int i=head->row;i<9;i++)

    {

        for(int j=head->col;j<9;j++)

        {

           while(sudoku[i][j]==0)

           {

              head->row=i;

              head->col=j;

            if(head->data<10)

               {

                   safety_no=check_safety(head->data,i,j);
                   counter++;

               if(safety_no==1)

              {

                  sudoku[i][j]=head->data;

                  head=attach_node(head);

              }

               else

               (head->data)++;

               }

               else

               {  if(head->prev!=NULL)

                  {

                      sudoku[head->row][head->col]=0;

                      head=head->prev;

                      free(head->next);

                      (head->data)++;

                      sudoku[head->row][head->col]=0;

                      goto LOOP;

                  }

                  else

                  cout<<"NOT SOLVABLE"<<endl;

                  break;

               }

           }

        }

}



}



void print_sudoku()

{cout<<"SOLUTION:"<<endl;

   for(int i=0;i<9;i++)

    {

        for(int j=0;j<9;j++)

        {

            cout<<sudoku[i][j];

            cout<<" ";

        }

        cout<<endl;

    }

}

int main()

{

    read_sudoku();

    solve_sudoku();

    print_sudoku();

    cout<<counter;

    return 0;

}
