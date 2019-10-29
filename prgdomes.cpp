#include "lib.cpp"

int main(int argc,char **argv)
{
	int mth;
	int flg;
	int C;
	int i,j,N=0;
	clock_t tStart;
	int left,right,middle,time;
	cout<<"Please give the method that you want to make searching"<<endl;
	
	cout<<"1. Linear"<<endl;
	cout<<"2. Binary"<<endl;
	cout<<"3. Interpolation"<<endl;
	cout<<"4. Red Tree"<<endl<<endl;
	cout<<"Your Choice:";
	cin >> mth;
	
	cout<<endl<<endl<<endl<<endl;
	
	do {
		C=menu();
		
		switch(C)
		{
			case 1:
				{
				
				char filename[200];
				cout<<"Give input file:"; cin>>filename;
				openCSV(filename);
				}
				break;
				
			case 2:
				{
				
				ofstream fout;
				char filename[200];
				cout<<"Dose filename:"; cin>>filename;
				fout.open(filename);
				fout<<N;
				for(int i=1;i<N;i++)
				{
				
					fout<<TableData[i].id<<";";
					fout<<TableData[i].name<<";";
					fout<<TableData[i].stars_hotel<<";";
					fout<<TableData[i].rooms<<";";

					for (int j=0;j<TableData[i].NK;j++){
					
						fout<<TableData[i].R[j].name<<";";
						fout<<TableData[i].R[j].hm_afixis<<";";
						fout<<TableData[i].R[j].Diarkeia<<";";
			
					}

					fout<<endl;


				}
				fout.close();
				}
				break;
				
			case 3:
				{
				
			
				HOTEL h1;
				h1.read();
				TableData=(HOTEL * ) realloc(TableData,(N+1)*sizeof(HOTEL));
				TableData[N++]=h1;	
				}
				break;
			
			case 4:
				{
				
				int id;
				cout<<"Give Hotel id:"<<endl;
				cin>> id;
				AVLtree Tree;
				if (mth==4)
				{
					for (j=0;j<N;j++) 
						Tree.insert(TableData[j].id);
				}
				
				tStart = clock();
				switch(mth)
				{

						case 1:
						
							flg=-1;
							for (int j=0;j<N;j++)
							{
								if(TableData[j].id==id)	
								{
									flg=j;
									break;	
								}	
							}
							if(flg!=-1)
								TableData[flg].print();
							else 
								cout<<"Not Found"<<endl;
							
							break;
						
						// binary search
						case 2:
							
							
							left=0;
							right=N-1;
							middle=(left+right)/2;
							while (TableData[middle].id!=id && left<right)
							{
								if(TableData[middle].id<id) right=middle-1;
								else left=middle+1;
								
								middle=(left+right)/2;
									
							}
							if(left<=right)
								TableData[middle].print();
							else
								cout<<"Not Found"<<endl;	
							
						break;
					
						case 3:
							
							
							left=0;
							right=N-1;
							middle = left +((id - TableData[left].id) * (right - left)) /(TableData[right].id - TableData[left].id); 
					
							while (TableData[left].id <=id && TableData[right].id>=id)
							{
								if(TableData[middle].id<id) right=middle-1;
								else left=middle+1;
								 middle = left +((id - TableData[left].id) * (right - left)) /(TableData[right].id - TableData[left].id);  
							}
							if(left<=right)
								TableData[middle].print();
							else
								cout<<"Den Vrethike"<<endl;	
							
							break;
						
						case 4:
						
							int k=Tree.search(id);
							break;
						
				
						
				
				}
				time=(double)((clock() - tStart)/CLOCKS_PER_SEC);
				cout<<"time="<<time<<endl;
				}
				break;
			case 5:
					for(int i=0;i<N;i++) TableData[i].print();
					break;


		}
	
	}while (C!=7);

		
		
		
}
	
	

		
		
	
	

