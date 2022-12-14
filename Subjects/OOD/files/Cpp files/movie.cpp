#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
struct movieName
{
    char name[50];
    int adulttik;
    int childtik;
    int ad;
    int cd;
    int p;
};
int main()
{
    struct movieName* m;
    m=(struct movieName*)malloc(sizeof(struct movieName));
    cout<<"Enter Movie Name: ";
    cin.getline(m->name,50);
    cout<<"No. of Adult Tickets sold: ";
    cin>>m->adulttik;
    cout<<"No. of Child Tickets sold: ";
    cin>>m->childtik;
    cout<<"Enter Adult Ticket Prize: ";
    cin>>m->ad;
    cout<<"Enter Child Ticket Prize: ";
    cin>>m->cd;
    int total=m->adulttik+m->childtik;
    int total1=m->adulttik*m->ad;
    int total2=m->childtik*m->cd;
    int gross=total1+total2;
    cout<<"Enter Charity Percentage: ";
    cin>>m->p;
    int pd=(gross*m->p)/100;
    int net=gross-pd;
    for(int i=0;i<35;i++)
    cout<<"_*";
    cout<<endl<<left<<setfill('.')<<setw(35)<<"Movie Name: "<<right<<m->name<<endl;
    cout<<left<<setfill('.')<<setw(35)<<"Number of Tickets Sold: "<<right<<total<<endl;
    cout<<left<<setfill('.')<<setw(35)<<"Total Gross Amount: "<<right<<gross<<endl;
    cout<<left<<setfill('.')<<setw(35)<<"Percentage of Gross Amount Donated: "<<right<<m->p<<endl;
    cout<<left<<setfill('.')<<setw(35)<<"Amount Donated: "<<right<<pd<<endl;
    cout<<left<<setfill('.')<<setw(35)<<"Net Sale: "<<right<<net<<endl;
    cout<<"Note that the strings, such as 'Movie Name: ', in the first column are left-justified, the numbers in the right column are right-justified, and decimal numbers are output with two decimal places.";
}
