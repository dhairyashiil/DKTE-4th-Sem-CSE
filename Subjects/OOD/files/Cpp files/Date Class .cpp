#include<iostream>
using namespace std;
class date
{
	private :
		short day ;
		int month;
		int year;
		
	public :
		date();
		void setdate();
		void printdate();
		long int datediff(date otherdate);
		void incdate();
		void formatprinttdate();
};
			 
			 
			  date::date()
			  {
			  	day   =0;
			  	month =0;
			  	year  =0;
			  }
			  
	void date::setdate( )
		  {
		  	cout << " Enter the Date in DD/MM/YY format "<< endl;
				 	cout << " Enter Day   :- ";
				 	cin >> day ;
				 	cout << " Enter Month :- ";
				 	cin >> month ;
				 	cout << " Enter Year  :- " ;
				 	cin >> year;
				 	cout<<"\n";
		 }
		 
	void date::printdate()
		 {
		 		cout<<"\n Entered Date is :- ";
		 		cout<<day<<"-"<<month<<"-"<<year<<endl;
			    
		 }
		 
    void date::formatprinttdate()
	 {
	 	string mmm[12]={ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct" , "Nov" , "Dec"};
			cout<<"\n Date in Format dd-mm-yyyy :- ";
			cout<< day << "-" << month << "-" << year << endl;
			cout<<" Date in Format dd/mm/yy   :- ";
			cout<< day << "-" << month << "-" << (10*((year/10)%10)+year%10)<< endl;
			cout<<" Date in Format dd/mmm/yy  :- ";
			cout<< day << "-" << mmm[month-1]<< "-" << year << endl;
	 }
	 
    long int date::datediff(date otherdate)
	{
			const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int y1 = year;
			long int days_before_date1;
						if (year<=2)
						y1--;
						days_before_date1= ( year-1582 ) * 365 + day;
							for (int i = 0; i <(month-1); i++)
							{
									  days_before_date1 += monthDays[i];
							}
			               int  count1=0;
							    for ( int i=1582 ; i<=y1; i++)
								{
										if ((i%4 == 0) && (i%100 != 0) || (i%400 ==0) )
									 	count1 ++;
								}
							days_before_date1 += count1;
			             
			             
			int y2 = otherdate.year;
			long int days_before_date2;
						if (year<=2)
						y2--;
						days_before_date2= ( otherdate.year-1582 ) * 365 + otherdate.day;
				    	
						for (int i = 0; i <(otherdate.month-1); i++)
						{
							days_before_date2 += monthDays[i];
						}
						int  count2=0;
				       
						for ( int i=1582 ; i<=y2; i++)
						{
						      if ((i%4 == 0) && (i%100 != 0) || (i%400 ==0) )
							  count2 ++;
						}
						days_before_date2 += count2;
						 
			return   days_before_date1-days_before_date2;
			
	}
	void date::incdate()
	{
		
			if ((year%4 == 0) && (year%100 != 0) || (year%400 ==0) )
		    {
					if (month == 2)
				 {   
			 		if ( day>=1 && day<29)
			 	 	day++;
			 		else 
					 		{
						 day=01;
					     month++;
						 }
			 	}
	      	}
	        
			else if (month == 2)
	        {
	           	
				 	if ( day>=1 && day<28)
				 	day++;
				 	else 
					    {
						 day=01;
					     month++;
						 }
			}
			
		   else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
			{ 
			     if ( day>=1 && day<31)
			     day++;
			     else 
			     {
				 day=01;
			     month++;
				 }
			}
			
		   else if (month==4 || month==6|| month==9 || month==11 )
			{
				if ( day>=1 && day<30)
			     day++;
			    else 
			     {
				 day=01;
			     month++;
			    }
			}
	
	}
     int main()
     {
     	date d1 ,d2;
     	d1.setdate();
     	d2.setdate();
        d2.incdate();
     
     	d1.formatprinttdate();
     	d2.formatprinttdate();
     	
     	cout<< "\n Difference Between Two Dates is :-"<<d1.datediff(d2)<<endl;
     	return 0;
	 }
  	
  	
  	
