//놀이공원 요금 계산 
#include <stdio.h>
int main () {
	//변수 선언
	int ticketCase, enterTime, id, wooDae, myYear, myMonthDay, manAge, realAge, ticketPrice;
	int ageCase, ticketTimeCase1;
	const int dayAdult = 56000, dayTeen = 50000, dayKid = 46000, dayBaby = 15000, a4Adult = 45000, a4Teen = 40000, a4Kid = 35000, a4Baby = 15000,
	    	  dayAdultAll = 59000, dayTeenAll = 52000, dayKidAll = 47000, dayBabyAll = 15000, a4AdultAll = 48000, a4TeenAll = 42000, a4KidAll = 36000, a4BabyAll = 15000;

	// 이용권 종류 선택하기 (종합 or 파크)
	printf("이용권의 종류를 선택해주세요.\n");
	printf("1. 종합이용권 (롯데월드+민속박물관)\n2. 파크이용권 (롯데월드)\n");
	scanf("%d",&ticketCase);

	//주,야간권 선택 메세지 출력 & 입력받기 
	printf("\n입장시간에 따른 이용권을 선택해 주세요.\n");
	printf("1. 1Day\n2. After4 (오후4시부터 입장)\n");
	scanf("%d",&enterTime);
	
	//주민번호 입력 받기 , 변수 계산 
	printf("\n주민등록번호를 입력해주세요. (6자리)\n");
	scanf("%d",&id);
	
	myYear = id/10000;       // ex) 950306 > 95 
	myMonthDay = id%10000;  // ex) 950306 > 306 
	
	realAge = 22- myYear+1;
	
	if (realAge <= 0) {
		//1900년대 출생자인 경우 
		realAge += 100;
	} 
	
	if ( myMonthDay <= 316) {
		manAge= realAge -1;
	} else {
		manAge= realAge-2;
	}
	
	//나이 케이스 정립 / 2022.03.16 기준 
	//36개월(만 2세)이상 ~ 만 12세 : 어린이요금 (3)
	//만 13세 이상 ~ 만 18세 : 청소년 요금      (2)
	//만 65세 이상 : 어린이요금                 (1)
	if ( manAge <2) {
		ticketPrice = 0;
		ageCase=4;
	} else if ((manAge >= 2 && manAge <13) || manAge >= 65 ) {
		ageCase = 3; // 어린이 
	} else if (manAge >= 13 && manAge <= 18) {
		ageCase = 2; //청소년 
	} else {
		ageCase = 1;  //어른 
	}
	
	//주민번호로 만 나이 판단하여 요금제 선정


	//상시 우대사항 선택
	printf("\n우대사항은 선택해주세요.\n1.없음(*만 65세 이상은 어린이요금 적용)\n2.장애인 우대\n3.국가유공자 우대\n4.휴가장병 우대\n5.임산부 우대\n6.다둥이 행복카드 우대\n");
	scanf("%d",&wooDae);
	
	//임장료에 우대사항 적용 
	
	//입장료 총액 출력
	
	//이어서 예매할지 선택 
	
	
	return 0; 
}
