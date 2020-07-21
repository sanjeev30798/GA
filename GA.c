#include<stdio.h>
#include <stdlib.h>

void solution_fill(int noOfStu,int solution[][noOfStu]){//,int solution2[][noOfStu],int solution3[][noOfStu]){
	int i=0,j=0,a1;
	for(i=0;i<25;i++){
		    j=0;
		        for(j=0;j<noOfStu;j++){
				        a1=rand()%3;
					        solution[i][j]=a1;
						        
						    }
	}
}
void crossover(int noOfStu,int crossmut[50],int solution[][noOfStu]){
	int r1,r2,r3,r4,rmStu=25,row1,row2;
	r1=rand()%noOfStu;
	r2=rand()%noOfStu;
	if(r1>r2){
		    r3=r1;
		        r1=r2;
			    r2=r3;
	}

	int i=0,fillso=25;
	while(rmStu>0){
		    if(rmStu==1){
			            mutation(noOfStu,crossmut[0],r1,r2,solution,fillso);
				            fillso++;
					            break;
						        }
		        r3=rand()%rmStu;
			    r4=rand()%rmStu;
			        if(r3==r4){
					        mutation(noOfStu,crossmut[r3],r1,r2,solution,fillso);
						        remov(crossmut,r3,r4,rmStu);
							        rmStu--;
								        fillso++;
									    }else{
										            crossOv(noOfStu,crossmut[r3],crossmut[r4],r1,r2,solution,fillso);
											            remov(crossmut,r3,r4,rmStu);
												            rmStu-=2;
													            fillso+=2;
														        }
	}
}
void crossOv(int noOfStu,int position1,int position2,int r1,int r2,int solution[][noOfStu],int fillso){
	   int i=0,temp,f2=fillso+1;
	      for(i=0;i<noOfStu;i++){
		              solution[fillso][i]=solution[position1][i];
			              solution[f2][i]=solution[position2][i];
				         }
	         for(i=r1;i<r2;i++){
			         solution[fillso][i]=solution[position2][i];
				         solution[f2][i]=solution[position1][i];
					    }
}
void remov(int crossmut[50],int r3,int r4,int rmStu){

	int i=0;
	if(r3==r4){
		    for(i=r3;i<rmStu;i++){
			            crossmut[i]=crossmut[i+1];
				        }
		        return ;
	}else{
		    if(r3>r4){
			            for(i=r4;i<r3;i++)
					                crossmut[i]=crossmut[i+1];
				            for(i=r3;i<rmStu;i++)
						                crossmut[i]=crossmut[i+2];
					        }
		        else{
				        for(i=r3;i<r4;i++)
						            crossmut[i]=crossmut[i+1];
					        for(i=r4;i<rmStu;i++)
							            crossmut[i]=crossmut[i+2];
						    }
	}
}
void mutation(int noOfStu,int position,int r1,int r2,int solution[][noOfStu],int fillso){
	 
	    int i=0,val1;
	        for(i=0;i<noOfStu;i++)
			        solution[fillso][i]=solution[position][i];
		    for(i=r1;i<r2;i++){
			            val1=rand()%2;
				            if(solution[position][i]==0){
						                if(val1==0)
									                solution[fillso][i]=1;
								            else
										                    solution[fillso][i]=2;
									            }else if(solution[position][i]==1){
											                if(val1==0)
														                solution[fillso][i]=0;
													            else
															                    solution[fillso][i]=2;
														            }else{
																                if(val1==0)
																			                solution[fillso][i]=0;
																		            else
																				                    solution[fillso][i]=1;
																			            }
					        }
}
int selection(int noOfStu,int solution[][noOfStu],int marks[],int sol[][noOfStu],int solId[][2]){
	int mSum=300,i,fitno=0,fTemp,j,badSol,badSolId;
	for(i=0;i<50;i++){
		    badSol=solId[i][1];
		        badSolId=solId[i][0];
			    fTemp=fitfun(noOfStu,solution[i],marks);
			        if(i<25){
					        solId[i][0]=i;
						        solId[i][1]=fTemp;
							        for(j=0;j<noOfStu;j++){
									            sol[i][j]=solution[i][j];
										            }
								    }else{
									            for(j=0;j<25;j++){
											                if(badSol<solId[j][1]){
														                badSol=solId[j][1];
																                badSolId=solId[j][0];
																		            }
													        }
										            if(badSol>fTemp){
												                for(j=0;j<noOfStu;j++){
															                sol[badSolId][j]=solution[i][j];
																	            }
														        }
											        }
				    
				    if(mSum>fTemp){
					            mSum=fTemp;
						            fitno=i;
							        }
	}
	return fitno;
	    
}
int fitfun(int noOfStu,int solution[noOfStu],int marks[]){
	int min1=-1,min2=-1,min3=-1,max1=-1,max2=-1,max3=-1,i;
	for(i=0;i<noOfStu;i++){
		    if(solution[i]==0){
			            if(min1>=marks[i]||min1==-1)
					                min1=marks[i];
				            if(max1<=marks[i]||max1==-1)
						                max1=marks[i];
					        }else if(solution[i]==1){
							        if(min2>marks[i]||min2==-1)
									            min2=marks[i];
								        if(max2<=marks[i]||max2==-1)
										            max2=marks[i];
									    }else{
										            if(min3>marks[i]||min3==-1)
												                min3=marks[i];
											            if(max3<=marks[i]||max3==-1)
													                max3=marks[i];
												        }
	}
	return max1-min1+max2-min2+max3-min3;
}
void print(int noOfStu,int solution[][noOfStu],int fitno,int marks[]){
	    
	    printf("\n");
	        int i=0;
		    for(i=0;i<noOfStu;i++){
			            printf("%d ",solution[fitno][i]);
				        }
		        printf("\nGroup 1 : ");
			    for(i=0;i<noOfStu;i++){
				            if(solution[fitno][i]==0)
						                printf("%d ",marks[i]);
					        }
			        printf("\nGroup 2 : ");
				    for(i=0;i<noOfStu;i++){
					            if(solution[fitno][i]==1)
							                printf("%d ",marks[i]);
						        }
				        printf("\nGroup 3 : ");
					    for(i=0;i<noOfStu;i++){
						            if(solution[fitno][i]==2)
								                printf("%d ",marks[i]);
							        }
					        printf("\n");
}
void reChange(int noOfStu,int solution[][noOfStu],int sol[][noOfStu]){
	int i,j;
	for(i=0;i<25;i++){
		    for(j=0;j<noOfStu;j++)
			            solution[i][j]=sol[i][j];
	}
}
int main(){
	int noOfStu,i,crossmut[50],j,result;
	for(i=0;i<50;i++)
		    crossmut[i]=i;
	scanf("%d",&noOfStu);
	int marks[noOfStu];
	for(i=0;i<noOfStu;i++){
		    marks[i]=rand()%101;

	}
	for(i=0;i<noOfStu;i++){
		    printf("%d ",marks[i]);
	}
	printf("\n");
	int solution[50][noOfStu],sol[25][noOfStu],solId[25][2];
	solution_fill(noOfStu,solution);
	for(i=0;i<98;i++){
		    for(j=0;j<25;j++){
			            solId[j][1]=301;
				            solId[j][0]=0;
					        }
		        crossover(noOfStu,crossmut,solution);
			    result=selection(noOfStu,solution,marks,sol,solId);
			        reChange(noOfStu,solution,sol);
	}
	print(noOfStu,solution,result,marks);
}