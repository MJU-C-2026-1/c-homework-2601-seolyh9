/* 
  파일이름: 주짓수 퍼포먼스 분석 시스템
  작 성 자: 설연희, 26-05-02
  하 는 일: 주짓수 퍼포먼스 분석 및 관원 관리 
*/

#include <stdio.h>

int main() {
    // [1] 변수 선언: 다양한 자료형 및 5개 이상의 변수 활용
    char user_initial;      // 사용자 이니셜
    char user_gender;       // 성별 (M/F) - V2.0 추가
    int training_months;    // 수련 기간
    int sparring_count;     // 주간 스파링 횟수
    double current_weight;  // 현재 체중
    double training_hours;  // 주간 훈련 시간
    double performance_idx; // 성장 지수

    // [2] 데이터 입력
    printf("--- 주짓수 퍼포먼스 분석 시스템 V2.0 ---\n");
    
    printf("본인의 영문 이니셜 한 글자를 입력하세요: ");
    scanf(" %c", &user_initial);

    printf("성별을 입력하세요 (남성: M, 여성: F): ");
    scanf(" %c", &user_gender);

    printf("수련 기간(개월)과 주간 스파링 횟수를 입력(예: 12 5): ");
    scanf("%d %d", &training_months, &sparring_count);

    printf("현재 체중(kg)을 입력하세요: ");
    scanf("%lf", &current_weight);

    printf("일주일 총 훈련 시간(시간)을 입력하세요: ");
    scanf("%lf", &training_hours);

    // [3] 산술 연산: 성장 지수 계산
    performance_idx = (sparring_count * 1.5) + (training_hours / 2.0) + (training_months * 0.1);

    // [4] 결과 출력 및 조건문 판별 
    printf("\n==========================================\n");
    printf("입력하신 [%c] 관원님의 분석 리포트입니다.\n", user_initial);
    printf("------------------------------------------\n");

    // 4-1. 성별에 따른 중첩 및 다중 조건문 (체급 분류)
    if (user_gender == 'M' || user_gender == 'm') { // 논리 연산자 || 활용
        printf("성별: 남성\t");
        if (current_weight < 64.0) printf("체급: 페더급\n");
        else if (current_weight < 70.0) printf("체급: 라이트급\n");
        else printf("체급: 미들급 이상\n");
    } 
    else if (user_gender == 'F' || user_gender == 'f') {
        printf("성별: 여성\t");
        if (current_weight < 53.0) printf("체급: 페더급\n");
        else if (current_weight < 58.0) printf("체급: 라이트급\n");
        else printf("체급: 미들급 이상\n");
    }
    else {
        printf("성별: 알 수 없음 (잘못된 입력)\n");
    }

    printf("현재 체중:\t%.2f kg\n", current_weight);
    printf("수련 기간:\t%d 개월\n", training_months);
    printf("주간 기록:\t%d회 스파링 / %.1f시간 훈련\n", sparring_count, training_hours);
    printf("------------------------------------------\n");
    printf(">> 퍼포먼스 지수: %.2f 점\n", performance_idx);

    // 4-2. 논리 연산자(&&)를 활용한 승급 자격 판별
    if (performance_idx >= 50.0 && training_months >= 6) {
        printf(">> [결과] 축하합니다! 승급 심사 대상자입니다.\n");
    } else {
        printf(">> [결과] 수련을 지속하여 점수를 더 쌓으세요.\n");
    }
    
    printf("==========================================\n");

    return 0;
}
