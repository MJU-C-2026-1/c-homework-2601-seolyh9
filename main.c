/* 
  파일이름: 주짓수 퍼포먼스 분석 시스템
  작 성 자: 설연희, 26-05-02
  하 는 일: 주짓수 퍼포먼스 분석 및 관원 관리 
*/

#include <stdio.h>

int main() {
    // [1] 변수 선언: 3가지 이상의 자료형 및 5개 이상의 변수 사용
    char user_initial;      // 사용자 이니셜 (문자형)
    int training_months;    // 총 수련 기간 (정수형)
    int sparring_count;     // 주간 스파링 횟수 (정수형)
    double current_weight;  // 현재 체중 (실수형)
    double training_hours;  // 주간 총 훈련 시간 (실수형)
    double performance_idx; // 계산된 퍼포먼스 지수 (실수형)

    // [2] 입출력 포매팅: printf와 scanf를 이용한 데이터 입력
    printf("--- 주짓수 퍼포먼스 분석 시스템 ---\n");
    printf("본인의 영문 이니셜을 입력하세요: ");
    scanf(" %c", &user_initial); 

    printf("수련 기간(개월)과 주간 스파링 횟수를 입력(예: 12 5): ");
    scanf("%d %d", &training_months, &sparring_count);

    printf("현재 체중(kg)을 입력하세요: ");
    scanf("%lf", &current_weight);

    printf("일주일 총 훈련 시간(시간)을 입력하세요: ");
    scanf("%lf", &training_hours);

    // [3] 산술 연산: 입력받은 데이터를 활용한 사칙연산 수행
    // 공식: (스파링 횟수 * 1.5) + (훈련 시간 / 2.0) + (수련 기간 * 0.1)
    performance_idx = (sparring_count * 1.5) + (training_hours / 2.0) + (training_months * 0.1);

    // [4] 출력 : 제어 문자와 서식 지정자 활용
    printf("\n==========================================\n");
    printf("입력하신 [%c] 관원님의 분석 리포트입니다.\t\n", user_initial);
    printf("------------------------------------------\n");
    printf("현재 체중:\t%.2f kg\n", current_weight);
    printf("수련 기간:\t%d 개월\n", training_months);
    printf("주간 기록:\t%d회 스파링 / %.1f시간 훈련\n", sparring_count, training_hours);
    printf("------------------------------------------\n");
    printf(">> 당신의 이번 주 퍼포먼스 지수: %.2f 점\n", performance_idx);
    printf("==========================================\n");

    return 0;
}
