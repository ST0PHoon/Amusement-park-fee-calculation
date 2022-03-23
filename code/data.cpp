#include <stdio.h>

int main () {
	//report 파일 값 불러오기 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0;
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX];
		
	while ( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count],
		&ticketTimeCaseArr[count], &wooDaeArr[count], &ageCaseArr[count], &ticketSuArr[count], &ticketPriceArr[count]) != -1) {

		count++;		
	}
	fclose(fp);
	
	// 데이터 분석할 코드 구간 
	for(int i = 0; i < count; i++) {
		printf("%d,%d,%d,%d,%d,%d,%d,%d\n",year[i], month[i], day[i],
		ticketTimeCaseArr[i], wooDaeArr[i], ageCaseArr[i], ticketSuArr[i], ticketPriceArr[i] );
	}
	
	return 0;
}

