/* 
  파일이름: 배달 음식 더치페이 계산기
  작 성 자: 설연희, 26-04-06
  하 는 일: 배달 음식 더치페이 계산
*/

#include <stdio.h>

int main() {
    // 1. 변수 선언 (자료형 3개 이상: char, int, double)
    char menu_initial;      // 메뉴 이니셜 (char)
    int order_id;           // 주문 번호 (int)
    double food_price;      // 음식 가격 (double) 
    double delivery_fee;    // 배달비 (double)
    double person_count;    // 인원수 (double) 
    double total_per_person; // 1인당 결과값 (double)

    // 2. 입력 (scanf 사용)
    printf("--- 배달 음식 더치페이 계산기 V1.0 ---\n");
    
    printf("메뉴의 첫 글자를 입력하세요 (P/C/J): ");
    scanf(" %c", &menu_initial);

    printf("주문 번호를 입력하세요: ");
    scanf("%d", &order_id);

    printf("총 음식 가격을 입력하세요 (원): ");
    scanf("%lf", &food_price); // double이므로 %lf 사용

    printf("총 배달비를 입력하세요 (원): ");
    scanf("%lf", &delivery_fee);

    printf("함께 먹은 인원수를 입력하세요 (명): ");
    scanf("%lf", &person_count); // 계산의 정확도를 위해 %lf로 입력받음

    // 3. 산술 연산 (순차 구조)
    total_per_person = (food_price + delivery_fee) / person_count;

    // 4. 출력 (printf 사용)
    printf("\n[ 주문 번호 %d번 정산 결과 ]\n", order_id);
    printf("선택 메뉴: %c\n", menu_initial);
    printf("---------------------------\n");
    printf("1인당 지불할 금액은 %.2f원 입니다.\n", total_per_person);
    printf("===========================\n");

    return 0;
}
