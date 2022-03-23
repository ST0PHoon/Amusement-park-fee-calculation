#include <stdio.h>

int main () {
	//report 파일 값 불러오기 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0, cir=0;
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX],
		ageTicketCase[MAX][MAX]={0};
	int wooDae1=0,wooDae2=0,wooDae3=0,wooDae4=0,wooDae5=0,wooDae6=0,
		parkMoney=0, parkAllMoney=0, oneDayMoney=0, After4Money=0,
		k, dayTotal=0, totalTicketSu=0,
		parkTicketSu,parkAllTicketSu,oneDayTicketSu, After4TicketSu;
		
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
						ageTicketCase[0][0] += ticketSuArr[i];
						ageTicketCase[2][0] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkAllMoney += ticketPriceArr[i];
				oneDayMoney += ticketPriceArr[i];
				break;
			case 2: //종합 + 4시후 
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[0][0] += ticketSuArr[i];
						ageTicketCase[3][0] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkAllMoney += ticketPriceArr[i];
				After4Money += ticketPriceArr[i];
				break;
			case 3: //파크 + 1Day
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[1][0] += ticketSuArr[i];
						ageTicketCase[2][0] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkMoney += ticketPriceArr[i];
				oneDayMoney += ticketPriceArr[i];
				break;
			case 4: //파크 + 4시후
				switch(ageCaseArr[i]) {
					case 1: //어른
						ageTicketCase[1][0] += ticketSuArr[i];
						ageTicketCase[3][0] += ticketSuArr[i];
						break;
 					case 2: //청소년 
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;	
					case 3: //어린이 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;
					case 4: //유아 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 5: //노인 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 6: //영아  
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkMoney += ticketPriceArr[i];
				After4Money += ticketPriceArr[i];
				break;
			default:
				break;
		}

	//총 티켓 판매 수, 혜택별 티켓수 분석
		//마지막 인원수는 count 값
		//혜택에 따라 티켓을 나눈다. 
			switch (wooDaeArr[i]) {
				case 1:
					wooDae1 += ticketSuArr[i];
					break;
				case 2:
					wooDae2 += ticketSuArr[i];
					break;
				case 3:
					wooDae3 += ticketSuArr[i];
					break;
				case 4:
					wooDae4 += ticketSuArr[i];
					break;
				case 5:
					wooDae5 += ticketSuArr[i];
					break;
				case 6:
					wooDae6 += ticketSuArr[i];
					break;
				default:
					break;
			}
	}
	
	// 권종 별 총 티켓 수
	parkTicketSu = ageTicketCase[1][5]+ageTicketCase[1][3]+ageTicketCase[1][2]+ageTicketCase[1][1]+ageTicketCase[1][0]+ageTicketCase[1][4];
	parkAllTicketSu = ageTicketCase[0][5]+ageTicketCase[0][3]+ageTicketCase[0][2]+ageTicketCase[0][1]+ageTicketCase[0][0]+ageTicketCase[0][4];
	oneDayTicketSu = ageTicketCase[2][5]+ageTicketCase[2][3]+ageTicketCase[2][2]+ageTicketCase[2][1]+ageTicketCase[2][0]+ageTicketCase[2][4];
	After4TicketSu =  ageTicketCase[3][5]+ageTicketCase[3][3]+ageTicketCase[3][2]+ageTicketCase[3][1]+ageTicketCase[3][0]+ageTicketCase[3][4];
	//총 티켓 수
	totalTicketSu = wooDae1+wooDae2+wooDae3+wooDae4+wooDae5+wooDae6;
	
	// 메시지 출력구간

	//티켓 종류 별, 연령대 구매 분석 / 시간대 별 매출액 + 아래 긴 더하기 값은 변수로 담을 예정  
	printf("\n======================= 권종 별 판매 현황 =======================\n");
	printf("종합권 총 %d매\n",parkAllTicketSu);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[0][5],
						ageTicketCase[0][3],ageTicketCase[0][2],ageTicketCase[0][1],ageTicketCase[0][0],ageTicketCase[0][4]);
	printf("종합권 매출 : %d원\n\n",parkAllMoney);
	
	printf("파크권 총 %d매\n",parkTicketSu);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[1][5],
						ageTicketCase[1][3],ageTicketCase[1][2],ageTicketCase[1][1],ageTicketCase[1][0],ageTicketCase[1][4]);
	printf("파크권 매출 : %d원\n\n",parkMoney); 

	printf("1Day권 총 %d매\n",oneDayTicketSu);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[2][5],
						ageTicketCase[2][3],ageTicketCase[2][2],ageTicketCase[2][1],ageTicketCase[2][0],ageTicketCase[2][4]);
	printf("1Day권 매출 : %d원\n\n",oneDayMoney); 

	printf("4시권 총 %d매\n",After4TicketSu);
	printf("영아 %d매,유아 %d매, 어린이 %d매, 청소년 %d매, 어른 %d매, 노인 %d매\n",ageTicketCase[3][5],
						ageTicketCase[3][3],ageTicketCase[3][2],ageTicketCase[3][1],ageTicketCase[3][0],ageTicketCase[3][4]);
	printf("4시권 매출 : %d원\n",After4Money); 
	printf("================================================================\n"); 
	
	//총 티켓 판매 수, 혜택별 티켓수 분석
	printf("\n=================== 우대사항 분석 ===================\n");
	printf("총 티켓 판매수       : %d매\n",totalTicketSu);
	printf("우대사항 없음        : %d매\n",wooDae1);
	printf("장애인 우대          : %d매\n",wooDae2);
	printf("국가유공자 우대      : %d매\n",wooDae3);
	printf("휴가장병 우대        : %d매\n",wooDae4);
	printf("임산부 우대          : %d매\n",wooDae5);
	printf("다둥이 행복카드 우대 : %d매\n",wooDae6);
	printf("======================================================\n");
	
	//일자 별 총 매출 
		// 날짜가 별로 내림차순 되어있다고 가정, k는 전날을 의미, k가 -1일 경우 0으로 취급
	printf("\n================ 날짜 별 수입 ================\n");
	for(int i = 0; i < count; i++) {
		k= i-1;
		if (k == -1) {
			k = 0;
		}

		if (year[i]==year[k]&& month[i]==month[k]&& day[i]==day[k]) {
			dayTotal += ticketPriceArr[i];
			//마지막 날과 전날이 같은 경우 > 값을 더하고 출력
			if (i==count-1) {
				printf("%d년%2d월%2d일의 매출 총액:  %d원\n",year[k],month[k],day[k], dayTotal);
			} 
		} else {
			//마지막 날과 전날이 다른 경우 > 오늘의 티켓 가격을 출력 
			if (i==count-1) {
				printf("%d년%2d월%2d일의 매출 총액:  %d원\n",year[i],month[i],day[i], ticketPriceArr[i]);
			} else {
				printf("%d년%2d월%2d일의 매출 총액:  %d원\n",year[k],month[k],day[k], dayTotal);
				dayTotal=0;
				dayTotal +=ticketPriceArr[i];
			}
		} 
	}
	printf("==============================================\n");
	
	return 0;
}

