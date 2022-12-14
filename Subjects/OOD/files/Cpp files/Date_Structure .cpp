#include<iostream>

using namespace std;
 	struct date 
 	{
 	short day;
 	int month;
 	int year;
 	};
 
 
 struct date getdate();
 void display( date * temp);
 void display_address( date * temp);
 long int date_diff ( date temp1 ,  date temp2 );
 void incdate(date *);
 

 
 
int main ( )
 {
 	 date date1,date2;
 	
    date1=getdate();
    date2=getdate();
 	incdate(&date1);
 	
 	cout<< " Date 1 in Various Format :- "<< endl;
	display(& date1);
	
	cout<< " Date 2 in Various Format :- "<< endl;
 	display(& date2);
 	
 	cout<< " First Date's  members(i.e DAY,MONTH,YEAR)  Addresses  are  :- "<< endl;
 	display_address(& date1);
 	
 	cout<< " Second Date's members(i.e DAY,MONTH,YEAR)  Addresses  are  :- "<< endl;
 	display_address(& date2); 
 	
 	cout<<"\n Difference Between Date in Days Is :- "<< date_diff( date1 , date2)<<endl;
 	return 0;
 
 }
 
 
 
		struct date getdate()
		 {
		 	struct date temp;
		 	cout << " Enter the Date in DD/MM/YY format "<< endl;
		 	cout << " Enter Day   :- ";
		 	cin >> temp.day ;
		 	cout << " Enter Month :- ";
		 	cin >> temp.month ;
		 	cout << " Enter Year  :- " ;
		 	cin >> temp.year;
		 	cout<< "\n"; 
		 	return temp;
			 
		}
		 
 
		 void display( date * temp)
		{ 
			
			string mmm[12]={ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct" , "Nov" , "Dec"};
			cout<<" Date in Format dd-mm-yyyy :- ";
			cout<< temp->day << "-" << temp->month << "-" << temp->year << endl;
			cout<<" Date in Format dd/mm/yy   :- ";
			cout<< temp->day << "-" << temp->month << "-" << (10*((temp->year/10)%10)+temp->year%10)<< endl;
			cout<<" Date in Format dd/mmm/yy  :- ";
			cout<< temp->day << "-" << mmm[temp->month-1]<< "-" << temp->year << endl;
	        cout<<"\n";
		} 
		
		
		void incdate( date * temp)
		{
			
			if ((temp->year%4 == 0) && (temp->year%100 != 0) || (temp->year%400 ==0) )
		    {
					if (temp->month == 2)
				   {   
			 			if ( temp->day>=1 && temp->day<29)
			 	 			{ temp->day++; }
			 			else 
					 	{
						 	temp->day=01;
					     	temp->month++;
						}
			 		}
	      	}
	        
			else if (temp->month == 2)
	        {
	           	
				 	if ( temp->day >=1 && temp->day < 28)
				 	temp->day++;
				 	else 
					{
						 temp->day=01;
					     temp->month++;
					}
			}
			
		   else if (temp->month==1 || temp->month==3 || temp->month==5 || temp->month==7 || temp->month==8 || temp->month==10 || temp->month==12)
			{ 
			     if ( temp->day>=1 && temp->day<31)
			     temp->day++;
			     else 
			     {
				 temp->day=01;
			     temp->month++;
				 }
			}
			
		   else if (temp->month==4 || temp->month==6|| temp->month==9 || temp->month==11 )
			{
				if ( temp->day >= 1 && temp->day < 30)
			    temp->day++;
			    else 
			    {
				  temp->day=01;
			      temp-> month++;
				}
			}
		}
		
		
		void display_address( date * temp)
	    {
			cout<<" "<<&temp->day<<" , ";
			cout<<" "<<&temp->month<<" , ";
			cout<<" "<<&temp->year<<" ." <<endl;
		}
 	
	  
		long int date_diff(  date temp1 ,  date temp2 )
	    {
	    	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	    	long diff;
		
			/* calculating days before Current Date taking Base Year as 1582 */
					int y1=temp1.year; 
	        		long int days_before_date1;
					if ( temp1.month <= 2 )
	    			y1--;
	    	
	    	      	days_before_date1= ( temp1.year-1582 ) * 365 + temp1.day;
	    	
	    			 for (int i = 0; i < (temp1.month-1); i++)
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
            
             
            /* calculating days before Previous Date taking Base Year as 1582 */
            		int y2=temp2.year;
            		long int days_before_date2;
	    			if ( temp2.month <= 2 )
	    			y2--;
	    			days_before_date2 =  ( temp2.year-1582 )* 365 + temp2.day;
	    			 for (int i = 0; i < (temp2.month-1); i++)
             		{
			 			 days_before_date2 += monthDays[i];
		     		}
		     
		    	 int  count=0;
	       
	       			for ( int i=1582 ; i<=y2; i++)
					 {
	 					if ((i%4 == 0) && (i%100 != 0) || (i%400 ==0) )
	 					count ++;
	 				}
            	days_before_date2 += count;
            
            	diff=(days_before_date1)-(days_before_date2);
            
            	if (diff<0)
           		 diff=-diff;
            
            return ( diff);
	    	
	    }
	    

 
