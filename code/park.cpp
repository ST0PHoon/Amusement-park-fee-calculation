//놀이공원 요금 계산 
#include <stdio.h>
#include <time.h>

int main () {
	//변수 선언
	int ticketCase, enterTime, id, wooDae, myYear, myMonthDay, manAge, realAge, ticketPrice, ageCase, ticketTimeCase, again, todayYear, todayMonth, todayDate;
	const int dayAdult = 56000, dayTeen = 50000, dayKid = 46000, dayBaby = 15000, a4Adult = 45000, a4Teen = 40000, a4Kid = 35000, a4Baby = 15000,
	    	  dayAdultAll = 59000, dayTeenAll = 52000, dayKidAll = 47000, dayBabyAll = 15000, a4AdultAll = 48000, a4TeenAll = 42000, a4KidAll = 36000, a4BabyAll = 15000;
	//시간 불러오기 
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

	do {
	// 이용권 종류 선택하기 (종합 or 파크)
	printf("\n이용권의 종류를 선택해주세요.\n");
	printf("1. 종합이용권 (롯데월드+민속박물관)\n2. 파크이용권 (롯데월드)\n");
	scanf("%d",&ticketCase);

	//주,야간권 선택 메세지 출력 & 입력받기 
	printf("\n입장시간에 따른 이용권을 선택해 주세요.\n");
	printf("1. 1Day\n2. After4 (오후4시부터 입장)\n");
	scanf("%d",&enterTime);
	
	//주민번호 입력 받기 , 변수 계산 
	printf("\n주민등록번호를 입력해주세요. (6자리)\n");
	scanf("%d",&id);
	
	//상시 우대사항 선택
	printf("\n우대사항은 선택해주세요.\n1.없음(*만 65세 이상은 어린이요금 적용)\n2.장애인 우대\n3.국가유공자 우대\n4.휴가장병 우대\n5.임산부 우대\n6.다둥이 행복카드 우대\n");
	scanf("%d",&wooDae);
	
	//시간 입력 
	todayYear = t->tm_year + 1900;
	todayMonth = t->tm_mon + 1;
	todayDate = t->tm_mday;
	
	//만 나이 계산 
	myYear = id/10000;       // ex) 950306 > 95 
	myMonthDay = id%10000;  // ex) 950306 > 306 
	
	realAge = todayYear%100 - myYear+1;
	
	if (realAge <= 0) {
		//1900년대 출생자인 경우 
		realAge += 100;
	} 
	
	if ( myMonthDay <= (todayMonth*100+todayDate)) {
		manAge= realAge -1;
	} else {
		manAge= realAge-2;
	}
	
	//나이 케이스 정립 / 2022.03.16 기준
	// 0 ~ 12개월 미만 (만 0세) 는 무료 
	// 12개월 이상 36개월 미만 : 베이비         (4)
	//36개월(만 3세)이상 ~ 만 12세 : 어린이요금 (3)
	//만 13세 이상 ~ 만 18세 : 청소년 요금      (2)
	//만 65세 이상 : 어린이요금                 (1)
	if ( manAge <3 && manAge >=1) { 
		ageCase=4; // 베이비 
	} else if ((manAge >= 3 && manAge <13) || manAge >= 65 ) {
		ageCase = 3; // 어린이 
	} else if (manAge >= 13 && manAge <= 18) {
		ageCase = 2; //청소년 
	} else {
		ageCase = 1; // 어른 
	}
		
	//이용권 종류 , 주야간권 종류에 따른 케이스 분류 
	if (ticketCase==1 && enterTime==1) {
		ticketTimeCase = 1; //종합 + 1Day 
	} else if (ticketCase==1 && enterTime==2) {
		ticketTimeCase =2; //종합 + 4시후 
	} else if (ticketCase == 2 && enterTime == 1) {
		ticketTimeCase = 3; //파크 + 1Day 
	} else {
		ticketTimeCase = 4; // 파크 + 4시후 
	} 
	
	//우대사항 이전, 요금 선정
	if ( ageCase == 1) { // 어른이고  
		if (ticketTimeCase== 1) {        // 종합 + 1Day 
			ticketPrice= dayAdultAll;
		} else if (ticketTimeCase==2) {  //종합 + 4시후
			ticketPrice= a4AdultAll;
		}else if (ticketTimeCase ==3) {  //파크 + 1Day 
			ticketPrice= dayAdult;
		} else {                        // 파크 + 4시후 
			ticketPrice= a4Adult;
		}
	} else if ( ageCase == 2) {  // 청소년  
		if (ticketTimeCase== 1) {
			ticketPrice=dayTeenAll;
		} else if (ticketTimeCase==2) {
			ticketPrice=a4TeenAll;
		}else if (ticketTimeCase ==3) {
			ticketPrice=dayTeen;
		} else {
			ticketPrice=a4Teen;
		}
	} else if ( ageCase == 3) { //어린이 + 노인 
		if (ticketTimeCase== 1) {
			ticketPrice=dayKidAll;
		} else if (ticketTimeCase==2) {
			ticketPrice=a4KidAll;
		}else if (ticketTimeCase ==3) {
			ticketPrice=dayKid;
		} else {
			ticketPrice=a4Kid;
		}
	} else {                  // 애기 
		if (ticketTimeCase== 1) {
			ticketPrice=dayBabyAll;
		} else if (ticketTimeCase==2) {
			ticketPrice=a4BabyAll;
		}else if (ticketTimeCase ==3) {
			ticketPrice=dayBaby;
		} else {
			ticketPrice=a4Baby;
		}
	}
	//12개월 미만의 경우
	if ( manAge == 0) {
		ticketPrice = 0;
	} 

	//임장료에 우대사항 적용
	if (wooDae == 2) {
		ticketPrice = ticketPrice/2 ; // 모든 티켓 50퍼 우대 
	} else if (wooDae == 3) {
		ticketPrice = ticketPrice/2 ;
	} else if (wooDae == 4 && ticketCase==1) { //종합이용권만 우대 
		ticketPrice = ticketPrice * 0.51;
	} else if (wooDae == 5 && ticketCase==1 ) {
		ticketPrice = ticketPrice/2;
	} else if (wooDae == 6 && ticketCase==1) {
		ticketPrice = ticketPrice*0.7;
	} else {
		printf("\n우대 사항이 없습니다.\n");
	}
	
	//입장료 총액 출력.
	if (ticketPrice==0){
		printf("\n무료 입장 입니다.");
	}
	else {
		printf ("\n가격은 %d원 입니다.",ticketPrice) ;
	}
	
	//이어서 예매할지 선택 
	printf("\n이어서 이용권을 구매하시겠습니까?\n1.예\n2.아니요\n");
	scanf("%d",&again); 
	} while(again == 1);
	
	return 0; 
}
