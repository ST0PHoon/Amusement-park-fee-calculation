#include <stdio.h>

int main () {
	//report 파일 값 불러오기 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0;
	
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX],
		ageTicketCase[MAX][MAX]={0}, wooDeaArrOut[30]={0};
		
	int k, dayTotal=0;
		
	while ( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count],
		&ticketTimeCaseArr[count], &wooDaeArr[count], &ageCaseArr[count], &ticketSuArr[count], &ticketPriceArr[count]) != -1) {

		count++;		
	}
	fclose(fp);
	
	//받아온 데이터 출력 
	printf("\n========================= 데이터 =========================");
	printf("\n날짜           티켓    우대   나이    매수      가격\n");
	for (int i = 0; i < count; i ++) {
		printf ("%d년%2d월%2d일\t%d\t%d\t%d\t%d\t%d\n",year[i], month[i], day[i],
		ticketTimeCaseArr[i], wooDaeArr[i], ageCaseArr[i], ticketSuArr[i], ticketPriceArr[i]);
	}
	printf("\n==========================================================\n");
	
	
	for(int i = 0; i < count; i++) {
	//티켓 종류 별, 연령대 구매 분석 / 시간대 별 매출액
		switch(ticketTimeCaseArr[i]) {
			case 1: //종합 + 1Day 
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[0][6] += ticketSuArr[i];
						ageTicketCase[2][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[0][7] += ticketPriceArr[i];  //티켓 종류별 가격 
				ageTicketCase[2][7] += ticketPriceArr[i];
				ageTicketCase[0][0] += ticketSuArr[i];     // 티켓 종류별 매수 
				ageTicketCase[2][0] += ticketSuArr[i];
				break;
			case 2: //종합 + 4시후 
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[0][6] += ticketSuArr[i];
						ageTicketCase[3][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[0][7] += ticketPriceArr[i];
				ageTicketCase[3][7] += ticketPriceArr[i];
				ageTicketCase[0][0] += ticketSuArr[i];
				ageTicketCase[3][0] += ticketSuArr[i];
				break;
			case 3: //파크 + 1Day
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[1][6] += ticketSuArr[i];
						ageTicketCase[2][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[1][7] += ticketPriceArr[i];
				ageTicketCase[2][7] += ticketPriceArr[i];
				ageTicketCase[1][0] += ticketSuArr[i];
				ageTicketCase[2][0] += ticketSuArr[i];
				break;
			case 4: //파크 + 4시후
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[1][6] += ticketSuArr[i];
						ageTicketCase[3][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[1][7] += ticketPriceArr[i];
				ageTicketCase[3][7] += ticketPriceArr[i];
				ageTicketCase[1][0] += ticketSuArr[i];
				ageTicketCase[3][0] += ticketSuArr[i];
				break;
			default:
				break;
		}

	//총 티켓 판매 수, 혜택별 티켓수 분석
		switch (wooDaeArr[i]) {
			case 1:
				wooDeaArrOut[1] += ticketSuArr[i];
				break;
			case 2:
				wooDeaArrOut[2] += ticketSuArr[i];
				break;
			case 3:
				wooDeaArrOut[3] += ticketSuArr[i];
				break;
			case 4:
				wooDeaArrOut[4] += ticketSuArr[i];
				break;
			case 5:
				wooDeaArrOut[5] += ticketSuArr[i];
				break;
			case 6:
				wooDeaArrOut[6] += ticketSuArr[i];
				break;
			default:
				break;
		}
	}

	//총 티켓 수
	for (int i =1; i<=6; i++) {
		wooDeaArrOut[0]+=wooDeaArrOut[i];
	} 

	//티켓 종류 별, 연령대 구매 분석 / 시간대 별 매출액 
	printf("\n======================= 권종 별 판매 현황 =======================\n");
	printf("종합권 총 %d매\n",ageTicketCase[0][0]);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[0][5],
						ageTicketCase[0][3],ageTicketCase[0][2],ageTicketCase[0][1],ageTicketCase[0][0],ageTicketCase[0][4]);
	printf("종합권 매출 : %d원\n\n",ageTicketCase[0][7]);
	
	printf("파크권 총 %d매\n",ageTicketCase[1][0]);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[1][5],
						ageTicketCase[1][3],ageTicketCase[1][2],ageTicketCase[1][1],ageTicketCase[1][0],ageTicketCase[1][4]);
	printf("파크권 매출 : %d원\n\n",ageTicketCase[1][7]); 

	printf("1Day권 총 %d매\n",ageTicketCase[2][0]);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[2][5],
						ageTicketCase[2][3],ageTicketCase[2][2],ageTicketCase[2][1],ageTicketCase[2][0],ageTicketCase[2][4]);
	printf("1Day권 매출 : %d원\n\n",ageTicketCase[2][7]); 

	printf("4시권 총 %d매\n",ageTicketCase[3][0]);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[3][5],
						ageTicketCase[3][3],ageTicketCase[3][2],ageTicketCase[3][1],ageTicketCase[3][0],ageTicketCase[3][4]);
	printf("4시권 매출 : %d원\n",ageTicketCase[3][7]); 
	printf("================================================================\n"); 
	
	//총 티켓 판매 수, 혜택별 티켓수 분석
	printf("\n=================== 우대사항 분석 ===================\n");
	printf("총 티켓 판매수       : %d매\n",wooDeaArrOut[0]);
	printf("우대사항 없음        : %d매\n",wooDeaArrOut[1]);
	printf("장애인 우대          : %d매\n",wooDeaArrOut[2]);
	printf("국가유공자 우대      : %d매\n",wooDeaArrOut[3]);
	printf("휴가장병 우대        : %d매\n",wooDeaArrOut[4]);
	printf("임산부 우대          : %d매\n",wooDeaArrOut[5]);
	printf("다둥이 행복카드 우대 : %d매\n",wooDeaArrOut[6]);
	printf("======================================================\n");
	
	//파일로 출력, 아래 fpirntf 로 값 저장
	FILE *filePointer1, *filePointer2,*filePointer3;
	filePointer1=fopen("ticketdata.csv","w");
	filePointer2=fopen("woodaedata.csv","w");
	filePointer3=fopen("daydata.csv","w");
		
	//일자 별 총 매출 , 내림차순의 조건 없이도 가능하도록 수정할 예정 
		// 날짜가 별로 내림차순 되어있다고 가정, k는 전날을 의미, k가 -1일 경우 0으로 취급	
	printf("\n================ 날짜 별 수입 ================\n");
	for(int i = 0; i < count; i++) {
		k= i-1;
		if (k == -1) {
			k = 0;
		}
		
		if (i==count-1) {
			if (year[i]==year[k]&& month[i]==month[k]&& day[i]==day[k]) {
				dayTotal += ticketPriceArr[i];
				printf("%d년%2d월%2d일의 매출 총액:  %d원\n",year[i],month[i],day[i], dayTotal);
				fprintf(filePointer3,"%d,%d,%d,%d\n",year[i],month[i],day[i], dayTotal);
			} else {
				printf("%d년%2d월%2d일의 매출 총액:  %d원\n",year[i],month[i],day[i], ticketPriceArr[i]);
				fprintf(filePointer3,"%d,%d,%d,%d\n",year[i],month[i],day[i], ticketPriceArr[i]);
			}
		} else {
			if (year[i]==year[k]&& month[i]==month[k]&& day[i]==day[k]) {
				dayTotal += ticketPriceArr[i];
			} else {
				printf("%d년%2d월%2d일의 매출 총액:  %d원\n",year[k],month[k],day[k], dayTotal);
				fprintf(filePointer3,"%d,%d,%d,%d\n",year[k],month[k],day[k], dayTotal);
				dayTotal =ticketPriceArr[i];
			}
		}
	} 
	printf("==============================================\n");
	
	//티켓_나이 별 매수와 가격 
	for ( int i = 0; i <=7;i++) {
		fprintf(filePointer1,"%d,%d,%d,%d,%d\n", i,ageTicketCase[0][i],ageTicketCase[1][i],ageTicketCase[2][i],ageTicketCase[3][i]);
	}
	//우대 데이터 출력 
	for (int i = 0; i<=6;i++) {
		fprintf(filePointer2,"%d,%d\n",i,wooDeaArrOut[i]);
	}

	fclose(filePointer1);
	fclose(filePointer2);
	fclose(filePointer3);
	
	return 0;
}
