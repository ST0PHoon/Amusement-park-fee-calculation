#include <stdio.h>

int main () {
	//report 파일 값 불러오기 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0;
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX];
	int wooDae1=0,wooDae2=0,wooDae3=0,wooDae4=0,wooDae5=0,wooDae6=0,
		k, dayTotal=0;
		
	while ( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count],
		&ticketTimeCaseArr[count], &wooDaeArr[count], &ageCaseArr[count], &ticketSuArr[count], &ticketPriceArr[count]) != -1) {

		count++;		
	}
	fclose(fp);
	
	//year[i], month[i], day[i], ticketTimeCaseArr[i], wooDaeArr[i], ageCaseArr[i], ticketSuArr[i], ticketPriceArr[i]
	for(int i = 0; i < count; i++) {
	//일자 별 총 매출 
		// 날짜가 별로 내림차순 되어있다고 가정
		k= i-1;
		if (k == -1) {
			k = 0;
		}
		//마지막 날과 전날이 같은 경우 > 값을 더하고 출력  
		//마지막 날과 전날이 다른 경우 > 오늘의 티켓 가격을 출력 
		
		if (year[i]==year[k]&& month[i]==month[k]&& day[i]==day[k]) {
			dayTotal += ticketPriceArr[i];
			if (i==count-1) {
				printf("%d-%d-%d, %d\n",year[k],month[k],day[k], dayTotal);
			} 
		} else {
			if (i==count-1) {
				printf("%d-%d-%d, %d\n",year[i],month[i],day[i], ticketPriceArr[i]);
			} else {
				printf("%d-%d-%d, %d\n",year[k],month[k],day[k], dayTotal);
				dayTotal=0;
				dayTotal +=ticketPriceArr[i];
			}
		}
	
	//티켓 종류 별, 연령대 구매 분석 / 시간대 별 매출액
		//연령에 따른 종합, 파크 and 1Day, After4 담을 행렬을 만든다. (연령6가지 * 티켓 4가지 = 24개의 변수)
		//돌리면서 변수에 값을 추가, 분석해서 값을 내보낸다. 
	
	//총 티켓 판매 수, 혜택별 티켓수 분석
		//마지막 인원수는 count 값
		//혜택에 따라 티켓을 나눈다. 
			switch (wooDaeArr[i]) {
				case 1:
					wooDae1++;
					break;
				case 2:
					wooDae2++;
					break;
				case 3:
					wooDae3++;
					break;
				case 4:
					wooDae4++;
					break;
				case 5:
					wooDae5++;
					break;
				case 6:
					wooDae6++;
					break;
				default:
					break;
			}
	}
	
	// 메시지 출력구간
	//일자 별 총 매출
	
	//티켓 종류 별, 연령대 구매 분석 / 시간대 별 매출액
	
	//총 티켓 판매 수, 혜택별 티켓수 분석
	printf("총 티켓 판매수: %d\n",count);
	printf("우대사항 없음: %d\n",wooDae1);
	printf("장애인 우대: %d\n",wooDae2);
	printf("국가유공자 우대: %d\n",wooDae3);
	printf("휴가장병 우대: %d\n",wooDae4);
	printf("임산부 우대: %d\n",wooDae5);
	printf("다둥이 행복카드 우대: %d\n",wooDae6);
	
	return 0;
}

