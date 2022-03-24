#include <stdio.h>

int main () {
	//report 파일 값 불러오기 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0;
	
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX],
		ageTicketCase[50][50]={0}, wooDeaArrOut[30]={0}, dayDataOut[30][6]={0};
		
	int k=0, dayTotal=0;
		
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
	
	// 계산 구간 // 
	//첫째날 데이터 첫행에 입력 
	dayDataOut[0][0]=year[0], dayDataOut[0][1]=month[0], dayDataOut[0][2]=day[0], dayDataOut[0][3]=ticketPriceArr[0];
	
	for(int i = 0, j = 1; i < count, j < count; i++, j++) {
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
	
		//일자 별 총 매출 , 내림차순의 조건 없이도 가능하도록 수정할 예정 
		if (dayDataOut[k][0]==year[j] && dayDataOut[k][1]==month[j] && dayDataOut[k][2]==day[j]){ //어제 오늘 날짜가 같은가? 
			dayDataOut[k][3]+=ticketPriceArr[i];
		} else {
			k++; // 날짜가 다르다면 다음 행에 새로운 날짜,가격 입력 
			dayDataOut[k][0]=year[j], dayDataOut[k][1]=month[j], dayDataOut[k][2]=day[j], dayDataOut[k][3]=ticketPriceArr[j];
		}	
	}
	
	//총 티켓 수
	for (int i =1; i<=6; i++) {
		wooDeaArrOut[0]+=wooDeaArrOut[i];
	} 
	
	// 메세지 출력구간 //
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
	
	//날짜 별, 매출액 분석	
	printf("\n================ 날짜 별 수입 ================\n");
	for (int i=0;i<=k;i++) {
		printf("%d년 %02d월 %02d일 %d원\n",dayDataOut[i][0],dayDataOut[i][1],dayDataOut[i][2],dayDataOut[i][3]);		
	}
	printf("==============================================\n");
	
	//데이터 출력구간 
	//파일로 출력, 아래 fpirntf 로 값 저장
	FILE *filePointer1, *filePointer2,*filePointer3;
	filePointer1=fopen("ticketdata.csv","w");
	filePointer2=fopen("woodaedata.csv","w");
	filePointer3=fopen("daydata.csv","w");
	
	//티켓_나이 별 매수와 가격 
	for ( int i = 0; i <=7;i++) {
		fprintf(filePointer1,"%d,%d,%d,%d,%d\n",i,ageTicketCase[0][i],ageTicketCase[1][i],ageTicketCase[2][i],ageTicketCase[3][i]);
	}
	//우대 데이터 출력 
	for (int i = 0; i<=6;i++) {
		fprintf(filePointer2,"%d,%d\n",i,wooDeaArrOut[i]);
	}
	//날짜 출력
	for (int i=0;i<=k;i++){
		fprintf(filePointer3,"%d,%d,%d,%d\n",dayDataOut[i][0],dayDataOut[i][1],dayDataOut[i][2],dayDataOut[i][3]);
	} 

	fclose(filePointer1);
	fclose(filePointer2);
	fclose(filePointer3);
	
	return 0;
}
