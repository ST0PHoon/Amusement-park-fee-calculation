//놀이공원 요금 계산 
#include <stdio.h>
int main () {
	//변수 선언
	int ticketCase, enterTime;
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
	
	//주민번호 입력 받기
	
	//주민번호로 나이 판단하여 요금제 선정
	
	//상시 우대사항 선택, 우대사항 적용
	
	//입장료 총액 출력
	
	//이어서 예매할지 선택 
	
	
	return 0; 
}
