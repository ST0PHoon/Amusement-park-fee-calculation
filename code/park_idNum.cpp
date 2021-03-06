//놀이공원 요금 계산 
#include <stdio.h>
#include <time.h>
//변수 선언
int ticketCase, enterTime, ticketSu, wooDae, manAge,
	ticketTimeCase, ticketPrice, totalTicketPrice,
	todayDate, yyyymmdd, ageCase, 
	idFront, idFrontYear, idFrontMonth, idFrontDay, idBack, idBackFirst,
	nextCustomer, again, counter=0;
	
int ticketTimeCaseArr[20]={0}, wooDaeArr[20]={0}, ageCaseArr[20]={0}, ticketPriceArr[20]={0}, ticketSuArr[20]={0};
	
const int DAY_ADULT = 56000, DAY_TEEN = 50000, DAY_KID = 46000, DAY_BABY = 15000,
    	  DAY_ADULT_ALL = 59000, DAY_TEEN_ALL = 52000, DAY_KID_ALL = 47000, DAY_BABY_ALL = 15000,
    	  AFTER4_ADULT = 45000, AFTER4_TEEN = 40000, AFTER4_KID = 35000, AFTER4_BABY = 15000,
    	  AFTER4_ADULT_ALL = 48000, AFTER4_TEEN_ALL = 42000, AFTER4_KID_ALL = 36000, AFTER4_BABY_ALL = 15000,
    	  OLDMAN_AGE=65, TEEN_AGE_MAX=18, TEEN_KID_AGE=13, KID_BABY_AGE=3, BABY_AGE_MIN=1;
    	  
void selectTicketFn() {
	do {
		printf("\n이용권의 종류를 선택해주세요.\n");
		printf("1. 종합이용권 (롯데월드+민속박물관)\n2. 파크이용권 (롯데월드)\n");
		scanf("%d",&ticketCase);
		
		if (ticketCase >2) {
			printf("보기 중에서 선택해주세요.\n\n");
		}
	} while(ticketCase >2) ;
}

void selectDayNightFn() {
	do {
		printf("\n입장시간에 따른 이용권을 선택해 주세요.\n");
		printf("1. 1Day\n2. After4 (오후4시부터 입장)\n");
		scanf("%d",&enterTime);
			
		if (enterTime >2) {
			printf("보기 중에서 선택해주세요.\n\n");
		}
	} while(enterTime >2) ;
}

void idInputFn() {
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
	
	do {
		printf("\n주민등록번호를 입력해주세요. ('-'대신 한칸 띄워주세요. ex) 051225 3152135)\n");
		scanf("%6d %7d",&idFront, &idBack);
		
		idBackFirst = idBack/1000000;
		idFrontYear = idFront/10000;
		idFrontMonth = (idFront/100)%100;
		idFrontDay = idFront%100;
		//윤년이 아닌 경우의 2월 29일은 미분류 상 태 
		if(idBackFirst >4 || idBackFirst<1 || idFrontDay>31 || idFrontDay<1 || idFrontMonth >12 ||
				idFrontDay <1 || idBack > 9999999 || idFront>999999 ||(idFrontMonth = 2 && idFrontDay>29)||
				((idFrontYear <= (t->tm_year)%100)&&(idBackFirst==1||idBackFirst==2))||
				((idFrontYear > (t->tm_year)%100)&&(idBackFirst==3||idBackFirst==4))) {
			printf("양식에 맞게 다시 입력해주세요.\n\n");
		}
	} while(idBackFirst >4 || idBackFirst<1 || idFrontDay>31 || idFrontDay<1 || idFrontMonth >12 ||
				idFrontDay <1 || idBack > 9999999 || idFront>999999 ||(idFrontMonth = 2 && idFrontDay>29)||
				((idFrontYear <= (t->tm_year)%100)&&(idBackFirst==1||idBackFirst==2))||
				((idFrontYear > (t->tm_year)%100)&&(idBackFirst==3||idBackFirst==4))) ;	
} 

void wooDaeInputFn() {
	do {	
		printf("\n우대사항은 선택해주세요.\n");
		printf("1.없음(*만 65세 이상은 어린이요금 적용)\n2.장애인 우대\n3.국가유공자 우대\n");
		printf("4.휴가장병 우대\n5.임산부 우대\n6.다둥이 행복카드 우대\n");
		scanf("%d",&wooDae);
		
		if ( wooDae>6 ){
			printf("보기 중에서 선택해주세요.\n\n");
		} 
	} while(wooDae>6) ;
}

void ticketSuFn() {
	do {
		printf("\n동일한 티켓을 몇 장 구매하시겠습니까?.\n");
		scanf("%d",&ticketSu);
		
		if ( ticketSu>10 ){
			printf("최대 10장 구매할 수 있습니다.\n\n");
		} 
	} while(ticketSu>10) ;
}

void manAgeFn() {
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기
	
	todayDate= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  //20220101 형태로 변형 
	if (idBackFirst ==3 || idBackFirst == 4) { //2000년대생 
		yyyymmdd = idFront + 20000000;
	} else {                  //1900년대생 
		yyyymmdd = idFront + 19000000;
	} 

	manAge = (todayDate - yyyymmdd)/10000;
}

void caseAgeTicketFn() {
	//나이 케이스 정립
	if ( manAge <KID_BABY_AGE && manAge >=BABY_AGE_MIN) { 
		ageCase=4; // 베이비 
	} else if ((manAge >= KID_BABY_AGE && manAge <TEEN_KID_AGE)) {
		ageCase = 3; // 어린이 
	} else if (manAge >= TEEN_KID_AGE && manAge <= TEEN_AGE_MAX) {
		ageCase = 2; //청소년 
	} else if ( manAge >= OLDMAN_AGE ) {
		ageCase = 5; //노 인  
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
}

void ticketPrice1Fn() {
if ( ageCase == 1) { // 어른이고  
	if (ticketTimeCase== 1) {        // 종합 + 1Day 
			ticketPrice= DAY_ADULT_ALL;
		} else if (ticketTimeCase==2) {  //종합 + 4시후
			ticketPrice= AFTER4_ADULT_ALL;
		}else if (ticketTimeCase ==3) {  //파크 + 1Day 
			ticketPrice= DAY_ADULT;
		} else {                        // 파크 + 4시후 
			ticketPrice= AFTER4_ADULT;
		}
	} else if ( ageCase == 2) {  // 청소년  
		if (ticketTimeCase== 1) {
			ticketPrice=DAY_TEEN_ALL;
		} else if (ticketTimeCase==2) {
			ticketPrice=AFTER4_TEEN_ALL;
		}else if (ticketTimeCase ==3) {
			ticketPrice=DAY_TEEN;
		} else {
			ticketPrice=AFTER4_TEEN;
		}
	} else if ( ageCase == 3) { //어린이
		if (ticketTimeCase== 1) {
			ticketPrice=DAY_KID_ALL;
		} else if (ticketTimeCase==2) {
			ticketPrice=AFTER4_KID_ALL;
		}else if (ticketTimeCase ==3) {
			ticketPrice=DAY_KID;
		} else {
			ticketPrice=AFTER4_KID;
		}
	} else if (ageCase == 5) { // 노인 (어린이랑 가격 동일) 
		if (ticketTimeCase== 1) {
			ticketPrice=DAY_KID_ALL;
		} else if (ticketTimeCase==2) {
			ticketPrice=AFTER4_KID_ALL;
		}else if (ticketTimeCase ==3) {
			ticketPrice=DAY_KID;
		} else {
			ticketPrice=AFTER4_KID;
		}
	} else {                  // 유 아 
		if (ticketTimeCase== 1) {
			ticketPrice=DAY_BABY_ALL;
		} else if (ticketTimeCase==2) {
			ticketPrice=AFTER4_BABY_ALL;
		}else if (ticketTimeCase ==3) {
			ticketPrice=DAY_BABY;
		} else {
			ticketPrice=AFTER4_BABY;
		}
	}
	
	//12개월 미만의 경우
	if ( manAge == 0) {
		ticketPrice = 0;
		ageCase = 6;
	} 
}

void ticketPriceEndFn() {
	if (wooDae == 2) {
		ticketPrice = ticketPrice/2 ; //종합 + 파크 이용권 우대  
	} else if (wooDae == 3) {
		ticketPrice = ticketPrice/2 ;
	} else if (wooDae == 4 && ticketCase==1) { //종합이용권만 우대 
		ticketPrice = (int)(ticketPrice*0.51);
	} else if (wooDae == 5 && ticketCase==1 ) {
		ticketPrice = ticketPrice/2;
	} else if (wooDae == 6 && ticketCase==1) {
		ticketPrice = (int)(ticketPrice*0.7);
	}
	//최종 가격
	ticketPrice *= ticketSu;
}

void ticketPricePrintFn() {
	if (ticketPrice==0){
		printf("\n무료 입장 입니다.\n");
	}
	else {
		printf ("\n%d매의  총금액은 %d원 입니다.\n",ticketSu,ticketPrice) ;
	}
}

void doNextFn() {
	//이번 구매 선택사항 별, 행렬에 담기
	ticketTimeCaseArr[counter] = ticketTimeCase;
	wooDaeArr[counter] = wooDae;
	ageCaseArr[counter] = ageCase;
	ticketPriceArr[counter] = ticketPrice;
	ticketSuArr[counter]=ticketSu;
	totalTicketPrice += ticketPrice; 
		
	//counter에 1추가, 초기값은 0 
	counter++;
	
	//이어서 예매할지 선택 
	printf("\n이어서 이용권을 구매하시겠습니까?\n1.예\n2.아니요\n");
	scanf("%d",&again); 
	
	//변수 초기화
	ticketCase=0, enterTime=0, wooDae=0, ticketSu=0, idFront=0, idBack=0, ageCase=0, ticketPrice=0;  
} 

void billsOutNextFn(){
	printf("\n\n===================================== %s =====================================\n","행복랜드") ;
	printf("%s\t\t%s\t     %s\t  %s\t\t%s\n\n","선택사항","연  령","매수","가격","우대사항");
	for (int i =0; i<counter; i++) {								
		switch (ticketTimeCaseArr[i]) {
			case 1:
				printf("%s\t%s","종합이용권","1Day");
				break;
			case 2:
				printf("%s\t%s","종합이용권","After4");
				break;
			case 3:
				printf("%s\t%s","파크이용권","1Day");
				break;
			case 4:
				printf("%s\t%s","파크이용권","After4");
				break;
			default:
				break;
		}
		
		switch (ageCaseArr[i]) {
			case 1:
				printf("\t%s","어  른");
				break;
			case 2:
				printf("\t%s","청소년");
				break;
			case 3:
				printf("\t%s","어린이");
				break;
			case 4:
				printf("\t%s","유  아");
				break;
			case 5:
				printf("\t%s","노  인");
				break;
			case 6:
				printf("\t%s","영  아");
				break;
			default:
				break;
		}
		
		printf("%10d%14d원\t",ticketSuArr[i],ticketPriceArr[i]) ;
		
		switch (wooDaeArr[i]) {
			case 1:
				printf("%s\n","우대사항 없음");
				break;
			case 2:
				printf("%s\n","장애인 우대");
				break;
			case 3:
				printf("%s\n","국가유공자 우대");
				break;
			case 4:
				printf("%s\n","휴가장병 우대");
				break;
			case 5:
				printf("%s\n","임산부 우대");
				break;
			case 6:
				printf("%s\n","다둥이 행복카드 우대");
				break;
			default:
				break;
		}
	}
	printf("\n입장료 총액은 %d원 입니다.", totalTicketPrice);
	printf("\n=====================================================================================\n") ;
	printf("\n새로운 주문을 받겠습니까?\n1.예\n2.종료\n");
	scanf("%d",&nextCustomer);
	//변수 초기화 
	counter = 0;
	totalTicketPrice=0;
}

void printReportFn() {
	time_t timer;
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

	FILE *filePointer = fopen("report.csv","a");
	
	for (int i =0; i<counter; i++) {
		fprintf(filePointer,"%d,%d,%d,%d,%d,%d,%d,%d\n",
				t->tm_year + 1900,t->tm_mon + 1, t->tm_mday,
				ticketTimeCaseArr[i],wooDaeArr[i],ageCaseArr[i],ticketSuArr[i],ticketPriceArr[i]);
	}

}

void oneGroupBills() {
	do {
		printf("================= 행복랜드 이용권 구매 =================\n") ;
		//입력구간
		selectTicketFn(); // 이용권 종류 선택하기 (종합 or 파크)
				
		selectDayNightFn(); //주,야간권 선택 메세지 출력 & 입력받기 
							
		idInputFn(); //주민번호 입력 받기 , 변수 계산 
		
		wooDaeInputFn(); //상시 우대사항 선택
		
		ticketSuFn(); //구매권 매수	

		//분류, 계산 
		manAgeFn(); //만 나이 계산
		
		caseAgeTicketFn(); //나이, 티켓 케이스 나누기 
	
		ticketPrice1Fn(); //우대사항 이전, 요금 선정
	
		ticketPriceEndFn(); //임장료에 우대사항 적용, 최종가격
		
		ticketPricePrintFn(); //입장료 총액 출력.
		
		//결괏값 입력, 초기화 
		doNextFn(); 
	} while(again == 1);
	
	printf("\n이용해주셔서 감사합니다.\n");
}

int main () {
	do { 
		//첫 그룸 받기	
		oneGroupBills();

		//결과 엑셀파일로 출력 
		printReportFn();
		
		// 영수증 출력 
		billsOutNextFn();
	} while(nextCustomer == 1);
	
	return 0; 
}
