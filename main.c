#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct vendingMachine//자판기 구조체 선언
{
    char drink[20]; //char 형 멤버
    int price; //int 형 멤버
    int amount; //int 형 멤버
};

int totalMoney=0;//누적금액 초기값 설정
int flag=0;//flag 초기값 설정

void printMenu(struct vendingMachine vmData[]);//자판기 이미지 함수
void inputMoney(struct vendingMachine vmData[]);//금액 투입 함수
void selectMenuFunc(struct vendingMachine vmData[]);//메뉴 선택 함수
void countFunc(void);//카운트다운 함수

int main()//main 함수 시작
{
    int selectMenu=0;//메뉴 선택 변수 초기값 설정
    int yesNo=0;//yesNo 변수 초기값 설정
    struct vendingMachine vmData[SIZE]={{"콜라",700,0},{"스프라이트",800,50},{"핫식스",900,50},{"웰치스",1000,50}};//자판기 구조체(vmData) 초기값 설정

    while(1)
    {
        printMenu(vmData);//자판기 이미지 함수
        printf("어서오세요. 입금 가능한 금액은 3만원 까지 입니다.\n");//문자열 "어서오세요. 입금 가능한 금액은 3만원 까지 입니다." 출력
        inputMoney(vmData);//금액 투입 함수
        selectMenuFunc(vmData);//메뉴 선택 함수
        //countFunc();//카운트다운 함수 호출

        if(flag==1)//flag 변수를 활용하여 연산의 결과나 참,거짓을 판단
        {
            flag = 0;//조건에 맞지 않으므로 while 루프를 빠져나옴
            system("cls");//시스템 초기화
            continue;
        }
    }
    return 0;//프로그램 종료
}

void printMenu(struct vendingMachine vmData[])//자판기 이미지 함수 정의
{
    printf("┌─────────────────────────────────────┐\n");
    printf("│                                     │\n");
    printf("│                                     │\n");
    printf("│     ┌──────────┐                    │\n");
    printf("│     │   콜라   │    1번   700원     │\n");
    printf("│     └──────────┘                    │\n");
    printf("│                                     │\n");
    printf("│     ┌──────────┐                    │\n");
    printf("│     │스프라이트│    2번   800원     │\n");
    printf("│     └──────────┘                    │\n");
    printf("│                                     │\n");
    printf("│     ┌──────────┐                    │\n");
    printf("│     │  핫식스  │     3번  900원     │\n");
    printf("│     └──────────┘                    │\n");
    printf("│                                     │\n");
    printf("│     ┌──────────┐                    │\n");
    printf("│     │  웰치스  │     4번  1000원    │\n");
    printf("│     └──────────┘                    │\n");
    printf("│                                     │\n");
    printf("│                                     │\n");
    printf("│                       ┌────┐        │\n");
    printf("│                       └────┘    │   │\n");
    printf("│                         지폐   동전 │\n");
    printf("│                                     │\n");
    printf("│                            ┌────┐   │\n");
    printf("│                            └────┘   │\n");
    printf("│                             반환구  │\n");
    printf("│                                     │\n");
    printf("│                                     │\n");
    printf("│                  EXIT               │\n");
    printf("│            ┌────────────┐           │\n");
    printf("│            │            │           │\n");
    printf("│            │            │           │\n");
    printf("│            └────────────┘           │\n");
    printf("│                                     │\n");
    printf("│                                     │\n");
    printf("└─────────────────────────────────────┘\n");
    return ;
}


void inputMoney(struct vendingMachine vmData[])//금액 투입 함수 정의
{
    int money=0, yesNo=0;//돈, yesNo 변수 초기화
    while(1)//반복문 사용
    {
        printf("돈을 입력하세요\n"); scanf_s("%d", &money);//문자열 "돈을 입력하세요." 출력 & 입력 받기
        if(money>30000 || money<=0)//투입한 금액이 3만원 초과 이거나 0원 이하 일 때
        {
            printf("잘 못 입력하셨습니다.\n");//문자열 "잘 못 입력하셨습니다." 출력
            continue;//반복문 처음으로 돌아가서 조건에 맞을 때 까지 계속 진행
        }
        totalMoney = totalMoney+money;//totalMoney 변수 선언
        printf("총 입금한 금액은 %d 원 입니다\n", totalMoney);//총 입금한 금액 출력

        printf("돈을 추가로 입금하시겠습니까?");//문자열 "돈을 추가로 입금하시겠습니까?"출력
        printf("yes=1, no=0\n"); scanf("%d", &yesNo);//yes, no 출력 & 입력받기
        if(yesNo==0)//yesNo의 값이 0이면
            break;//반복문 종료
        else//yesNo의 값이 0이 아니면
            continue;//금액 투입함수 처음으로 돌아가 다시 실행
      }
      return ;//금액 투입 함수 종료
}

void selectMenuFunc(struct vendingMachine vmData[])//메뉴 선택 함수 정의
{
    int selectMenu=0, yesNo=0;//메뉴 선택, yesNo 변수 초기화

    while(1)//반복문 사용
    {
        system("cls");//시스템 초기화

        printMenu(vmData);//자판기 이미지 함수 호출
        printf("총 입금한 금액은 %d 원 입니다\n", totalMoney);//총 입금한 금액 출력
        printf("메뉴를 선택해주세요: "); scanf_s("%d", &selectMenu);//문자열 "메뉴를 선택해주세요" 출력 & 선택한 메뉴 입력받음
        if(selectMenu>4 || selectMenu<1)//선택한 메뉴 번호가 4를 초과하거나 1 미만일 때의 조건
        {
            printf("잘못 입력하셨습니다. 다시 입력해 주세요.\n");//문자열 "잘못 입력하셨습니다. 다시 입력해 주세요." 출력
            getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
            getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
            continue;//메뉴 선택하는 부분으로 가서 계속 진행
        }
        else if(vmData[selectMenu-1].amount<=0)//선택한 메뉴의 재고가 없으면
        {
            printf("남아있는 %s 가 없습니다. 엔터를 눌러주세요.\n", vmData[selectMenu-1].drink);//문자열"남아있는 메뉴 가 없습니다" 출력
            getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
            getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
            continue;//선택한 메뉴의 재고가 없을 시에 메뉴를 선택해주세요 단계로 가서 다시 진행
        }
        else if(vmData[selectMenu-1].price>totalMoney)//선택한 메뉴의 금액이 자판기에 집어넣은 총 금액보다 높으면
        {
            printf("-%d 잔액이 부족합니다.", vmData[selectMenu-1].price-totalMoney);//부족한 잔액과 문자열 "잔액이 부족합니다." 출력
            printf("충전하시겠습니까? yes=1, no=0: "); scanf("%d", &yesNo); //충전하여 다시 실행 할 것인지 묻는 문자열 출력 & 입력 받기
            if(yesNo==1)//yesNo의 값이 1이면
            {
                inputMoney(vmData);//금액 투입 함수를 호출
                continue;//금액 투입 단계 실행
            }
            else//yesNo의 값이 1이 아니면
            {
                printf("잔액은 %d원 입니다. 감사합니다. 다시 시작하려면 엔터를 눌러주세요",totalMoney);//문자열 "잔액은 %d원 입니다. 감사합니다. 다시 시작하려면 엔터를 눌러주세요" 출력
                getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
                getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
                totalMoney = 0;//잔액 반환 후 총 금액은 0으로 초기화
                flag = 1;
                break;// 메뉴 선택 종료
            }
        }

        totalMoney = totalMoney - vmData[selectMenu-1].price;//메뉴 선택 후 의 totalMoney 재설정
        vmData[selectMenu-1].amount = vmData[selectMenu-1].amount-1;//메뉴 선택 후 의 재고량 재설정
        countFunc();//메뉴 출력 전 카운트다운 함수 호출
        printf("기다려 주셔서 감사합니다.\n");//문자열 "기다려 주셔서 감사합니다." 출력
        sleep(1);//Sleep 함수 사용하여 시간 지연
        printf("주문하신 %s가 준비되었습니다.\n", vmData[selectMenu-1].drink);//문자열 "주문하신 메뉴 가 준비되었습니다." 출력
        printf("남은 금액은 %d 입니다.\n", totalMoney);//"남은 금액은 입니다." 출력

        sleep(2);//Sleep 함수 사용하여 시간 지연
        printf("계속하시겠습니까? \n");//문자열 "계속하시겠습니까?" 출력
        printf("yes=1, no=0: \n"); scanf("%d", &yesNo); //yes, no 출력 & 입력받기
        if(yesNo==0)//yesNo의 값이 0이면
        {
            printf("잔액은 %d원 입니다. 감사합니다. 다시 시작하려면 엔터를 눌러주세요",totalMoney);//문자열 "잔액은 %d원 입니다. 감사합니다. 다시 시작하려면 엔터를 눌러주세요" 출력
            totalMoney = 0;//잔액 반환 후 총 금액은 0으로 초기화
            getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
            getchar();//엔터키를 입력하여 다음 단계로 진행하게 함
            flag = 1;
            break;// 메뉴 선택 종료
        }
    }
    return ;//메뉴 선택 함수 종료
}

void countFunc(void)//카운트다운 함수 정의
{
    for(int i=3; i>0; i--)//반복문을 사용하여 3초부터 1초까지 1씩 줄어들면서 카운트 다운
    {
        if(i>0)//i가 0 초과 일때
        {
            sleep(1);//Sleep 함수 사용하여 시간 지연 후
            printf(" %d", i);//3초부터 1초까지 1씩 줄어들면서 카운트 다운 출력
        }
        else//i가 0과 같거나 작으면
        {
            break;//카운트 다운 반복문 종료
        }
    }
    printf("\a");//카운트 다운 후 알림음 출력

    sleep(1);//Sleep 함수 사용하여 시간 지연

    printf("\n");//한줄 띄어서 출력

    return ;//카운트 다운 함수 종료
}
